#include <iostream>

#include "temperature_logger.H"


int main() {

    TemperatureLog tlog;

    tlog.add_data(10, 75);
    tlog.add_data(15, 68);
    tlog.add_data(22, 79);
    tlog.add_data(40, 85);
    tlog.add_data(49, 96);
    tlog.add_data(55, 88);
    tlog.add_data(62, 78);
    tlog.add_data(70, 71);
    tlog.add_data(76, 62);

    std::cout << "mean temperature = " << tlog.mean() << std::endl;
    std::cout << "max temperature = " << tlog.max() << std::endl;
    std::cout << "time of max temperature = " << tlog.time_of_max() << std::endl;
}
