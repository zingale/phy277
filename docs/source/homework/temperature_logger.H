#ifndef TEMPERATURE_LOGGER_H
#define TEMPERATURE_LOGGER_H

#include <vector>
#include <numeric>
#include <algorithm>

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
        auto sum =
            std::accumulate(log.begin(), log.end(),
                            0.0,
                            [] (const double a, const TemperatureReading b)
                                {return a + b.temp;});

        return sum / static_cast<double>(log.size());
    }

    double max() {
        auto it =
            std::ranges::max_element(log,
                                     [] (const TemperatureReading& a,
                                         const TemperatureReading& b)
                                         {return a.temp < b.temp;});
        return (*it).temp;
    }

    double time_of_max() {
        auto max_temp = max();
        auto it = std::ranges::find_if(log, [=] (const TemperatureReading& a) {return a.temp == max_temp;});
        return (*it).time;
    }

};

#endif
