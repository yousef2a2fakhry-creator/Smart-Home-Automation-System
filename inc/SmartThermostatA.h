#ifndef SMART_THERMOSTAT_A_H
#define SMART_THERMOSTAT_A_H

#include <string>
#include "Thermostat.h"

class SmartThermostatA : public Thermostat
{
private:
    bool ecoMode;

public:
    // The initial eco mode is false.
    SmartThermostatA(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        double targetTemperature = 22.0,
        bool ecoMode = false);
    bool getEcoModeState() const;
    void setEcoModeState(bool state);
    virtual void setTargetTemperature(double value) override;
    std::string getType() const override;
    ~SmartThermostatA() noexcept override = default;
};

#endif