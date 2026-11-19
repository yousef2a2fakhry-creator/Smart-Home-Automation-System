#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include "SmartDevice.h"
#include "ThermostatModes.h"

class Thermostat : public SmartDevice
{
protected:
    double temperature;
    double targetTemperature;
    ThermostatModes mode;

public:
    // The initial mode is OFF.
    Thermostat(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        double targetTemperature = 22.0,
        ThermostatModes mode = ThermostatModes::OFF
        );
    virtual void setTargetTemperature(double value);
    void setTemperature(double value);
    void setThermostatMode(ThermostatModes mode);
    double getTargetTemperature() const;
    double getTemperature() const;
    ThermostatModes getMode() const;
    ~Thermostat() noexcept override = default;
};

#endif