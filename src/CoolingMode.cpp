#include <iostream>
#include "../inc/CoolingMode.h"
#include "../inc/SmartThermostatB.h"

void CoolingMode::run(const Thermostat &thermostat) const
{
    bool tooHot = thermostat.getTemperature() > thermostat.getTargetTemperature();
    bool tooHumid = false;

    const SmartThermostatB *smartB = dynamic_cast<const SmartThermostatB *>(&thermostat);
    if (smartB != nullptr)
        tooHumid = smartB->getHumidity() > smartB->getTargetHumidity();

    if (tooHot || tooHumid)
        std::cout << "[" << thermostat.getDeviceID() << "] AC ON\n";
    else
        std::cout << "[" << thermostat.getDeviceID() << "] AC OFF (below the threshold)\n";
}

std::string CoolingMode::getName() const
{
    return "Cooling";
}