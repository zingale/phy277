#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <format>
#include <fstream>

const double d = 0.074;
const double A = std::numbers::pi * d * d;
const double m = 0.145;
const double rho_air = 1.2;
const double g = -9.81;

struct OrbitState {
    double t;
    double x;
    double y;
    double vx;
    double vy;
};

OrbitState rhs(const OrbitState& state, double C) {

    OrbitState dodt{};

    // dx/dt = vx; dy/dt = vy

    dodt.x = state.vx;
    dodt.y = state.vy;

    // d(vx)/dt = - 1/2 C rho_air A |v| vx / m
    // d(vy)/dt = - 1/2 C rho_air A |v| vy / m - |g|

    double v = std::sqrt(state.vx * state.vx + state.vy * state.vy);

    dodt.vx = -0.5 * C * rho_air * A * v * state.vx / m;
    dodt.vy = -0.5 * C * rho_air * A * v * state.vy / m - std::abs(g);

    return dodt;

}

OrbitState update_state(const OrbitState& state,
                        const double dt,
                        const OrbitState& state_derivs) {

    OrbitState state_new{};

    state_new.t = state.t + dt;
    state_new.x = state.x + dt * state_derivs.x;
    state_new.y = state.y + dt * state_derivs.y;
    state_new.vx = state.vx + dt * state_derivs.vx;
    state_new.vy = state.vy + dt * state_derivs.vy;

    return state_new;
}

void write_history(const std::vector<OrbitState>& history, double C) {

    std::string filename = std::format("projectile-C{:.2f}.out", C);
    std::ofstream ofile(filename);
    for (const auto& p : history) {
        ofile
            << std::format("{:11.8f} {:11.8f} {:11.8f} {:11.8f} {:11.8f}\n",
                           p.t, p.x, p.y, p.vx, p.vy);
    }
}

std::vector<OrbitState> integrate(const OrbitState& state0,
                                  const double C,
                                  const double dt_in) {

    // how the history of the orbit

    std::vector<OrbitState> orbit_history{};
    orbit_history.push_back(state0);

    double dt = dt_in;

    OrbitState state = state0;

    // integration loop
    while (state.y > 0.0) {

        // get the derivatives
        auto state_derivs = rhs(state, C);

        // get the derivatives at the midpoint in time
        auto state_star = update_state(state, 0.5 * dt, state_derivs);
        state_derivs = rhs(state_star, C);

        // update the state
        state = update_state(state, dt, state_derivs);

        orbit_history.push_back(state);
    }

    return orbit_history;

}

int main() {

    // set initial conditions
    OrbitState state0{};

    double C{};
    std::cout << "# Enter the drag coefficient C: ";
    std::cin >> C;
    std::cout << std::endl;

    // initial velocity and angle
    double v0 = 10.0;
    double theta = std::numbers::pi / 4.0;

    // initial height
    double y0 = 10.0;

    state0.t = 0.0;
    state0.x = 0.0;
    state0.y = y0;
    state0.vx = v0 * std::cos(theta);
    state0.vy = v0 * std::sin(theta);

    double dt = 0.05;

    auto orbit_history = integrate(state0, C, dt);
    write_history(orbit_history, C);

}
