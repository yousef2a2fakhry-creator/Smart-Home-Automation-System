#include "../inc/Thermostat.h"
Thermostat::Thermostat(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    double targetTemperature)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), temperature(0.0), targetTemperature(targetTemperature){}
void Thermostat::setTargetTemperature(double value)
{
    targetTemperature = value;
}
void Thermostat::setTemperature(double value)
{
    temperature = value;
}

double Thermostat::getTargetTemperature() const
{
    return targetTemperature;
}
double Thermostat::getTemperature() const
{
    return temperature;
}


void Thermostat::setMode(std::shared_ptr<Mode> newMode)
{
    mode = newMode;
}
void Thermostat::run() const
{
    if (mode != nullptr)
        mode->run(*this);
}
std::string Thermostat::getModeName() const
{
    return mode->getName();
}
