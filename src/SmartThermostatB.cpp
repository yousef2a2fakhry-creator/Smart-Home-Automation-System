#include "../inc/SmartThermostatB.h"
SmartThermostatB::SmartThermostatB(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    double targetTemperature,
    double targetHumidity)
    : Thermostat(deviceID, vendor, countryOfManufacture, year, targetTemperature), humidity(0.0), targetHumidity(targetHumidity) {}

void SmartThermostatB::setHumidity(double value)
{
    humidity = value;
}
double SmartThermostatB::getHumidity() const
{
    return humidity;
}
void SmartThermostatB::setTargetHumidity(double value)
{
    targetHumidity = value;
}
double SmartThermostatB::getTargetHumidity() const
{
    return targetHumidity;
}
DeviceTypes SmartThermostatB::getType() const
{
    return DeviceTypes::SmartThermostatB;
}