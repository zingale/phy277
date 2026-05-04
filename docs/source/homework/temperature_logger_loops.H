#ifndef TEMPERATURE_LOGGER_H
#define TEMPERATURE_LOGGER_H

#include <vector>
#include <limits>

struct TemperatureReading {
    double time;
    double temp;
};

struct TemperatureLog {

    std::vector<TemperatureReading> log;

    TemperatureLog() {}

    void add_data(double time, double temp) {
        log.push_back(TemperatureReading{.time=time, .temp=temp});
    }

    double mean() {
        double sum{};
        for (auto tr : log) {
            sum += tr.temp;
        }
        return sum / static_cast<double>(log.size());
    }

    double max() {
        double max{std::numeric_limits<double>::lowest()};
        for (auto tr : log) {
            max = std::max(max, tr.temp);
        }
        return max;
    }

    double time_of_max() {
        auto max_temp = max();
        double time{};
        for (auto tr : log) {
            if (tr.temp == max_temp) {
                time = tr.time;
                break;
            }
        }
        return time;
    }

};
#endif
