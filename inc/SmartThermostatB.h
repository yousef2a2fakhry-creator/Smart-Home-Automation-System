#ifndef SMART_THERMOSTAT_B_H
#define SMART_THERMOSTAT_B_H

#include <string>
#include "Thermostat.h"

class SmartThermostatB : public Thermostat
{
private:
    double humidity;
    double targetHumidity;

public:
    SmartThermostatB(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        double targetTemperature = 22.0,
        double targetHumidity = 50.0);
    void setHumidity(double value);
    double getHumidity() const;
    void setTargetHumidity(double value);
    double getTargetHumidity() const;
    std::string getType() const override;
    ~SmartThermostatB() noexcept override = default;

};
#endif