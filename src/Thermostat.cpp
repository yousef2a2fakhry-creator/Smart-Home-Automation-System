#include "../inc/Thermostat.h"
Thermostat::Thermostat(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    double targetTemperature,
    ThermostatModes mode)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), temperature(0.0), targetTemperature(targetTemperature), mode(mode) {}
void Thermostat::setTargetTemperature(double value)
{
    targetTemperature = value;
}
void Thermostat::setTemperature(double value)
{
    temperature = value;
}
void Thermostat::setThermostatMode(ThermostatModes mode)
{
    this->mode = mode;
    if (mode == ThermostatModes::Cooling)
    {
        setTargetTemperature(18.0);
    }
    else if (mode == ThermostatModes::Heating)
    {
        setTargetTemperature(27.0);
    }
}
double Thermostat::getTargetTemperature() const
{
    return targetTemperature;
}
double Thermostat::getTemperature() const
{
    return temperature;
}
ThermostatModes Thermostat::getMode() const
{
    return mode;
}
