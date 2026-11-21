#include <iostream>
#include "../inc/CoolingMode.h"
#include "../inc/SmartThermostatB.h"

CoolingMode::CoolingMode(std::shared_ptr<ClimateActuator> cooler)
    : cooler(cooler) {}

void CoolingMode::run(const Thermostat &thermostat) const
{
    bool tooHot = thermostat.getTemperature() > thermostat.getTargetTemperature();
    bool tooHumid = false;

    const SmartThermostatB *smartB = dynamic_cast<const SmartThermostatB *>(&thermostat);
    if (smartB != nullptr)
        tooHumid = smartB->getHumidity() > smartB->getTargetHumidity();

    if (tooHot || tooHumid)
    {
        cooler->turnOn(thermostat.getTargetTemperature());
        std::cout << "[" << thermostat.getDeviceID() << "] AC ON\n";
    }
    else
    {
        cooler->turnOff();
        std::cout << "[" << thermostat.getDeviceID() << "] AC OFF (below the threshold)\n";
    }
}

void CoolingMode::stop() const
{
    cooler->turnOff();
}

std::string CoolingMode::getName() const
{
    return "Cooling";
}