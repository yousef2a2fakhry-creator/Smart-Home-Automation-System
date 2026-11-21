#include <iostream>
#include "../inc/HeatingMode.h"
#include "../inc/SmartThermostatB.h"

HeatingMode::HeatingMode(std::shared_ptr<ClimateActuator> heater) : heater(heater) {}

void HeatingMode::run(const Thermostat &thermostat) const
{
    bool tooCold = thermostat.getTemperature() < thermostat.getTargetTemperature();
    bool tooDry = false;

    // only SmartThermostatB has humidity, so check the real type
    const SmartThermostatB *smartB = dynamic_cast<const SmartThermostatB *>(&thermostat);
    if (smartB != nullptr)
        tooDry = smartB->getHumidity() < smartB->getTargetHumidity();

    if (tooCold || tooDry)
    {
        heater->turnOn(thermostat.getTargetTemperature());
        std::cout << "[" << thermostat.getDeviceID() << "] Heater ON\n";
    }
    else
    {
        heater->turnOff();
        std::cout << "[" << thermostat.getDeviceID() << "] Heater OFF (above the threshold)\n";
    }
}
void HeatingMode::stop() const
{
    heater->turnOff();
}
std::string HeatingMode::getName() const
{
    return "Heating";
}