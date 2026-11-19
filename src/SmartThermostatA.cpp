#include "../inc/SmartThermostatA.h"
SmartThermostatA::SmartThermostatA(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    double targetTemperature,
    ThermostatModes mode, bool ecoMode)
    : Thermostat(deviceID, vendor, countryOfManufacture, year, targetTemperature, mode), ecoMode(ecoMode) {}

bool SmartThermostatA::getEcoModeState() const
{
    return ecoMode;
}
void SmartThermostatA::setEcoModeState(bool state)
{
    ecoMode = state;

}
void SmartThermostatA::setTargetTemperature(double value) 
{
    if (ecoMode && value > 23.0)
        value = 23.0;
    else if (ecoMode && value < 18.0)
        value = 18.0;
    Thermostat::setTargetTemperature(value);
}
std::string SmartThermostatA::getType() const
{
    return "SmartThermostatA";
}

