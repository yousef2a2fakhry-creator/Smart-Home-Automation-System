#include <iostream>
#include "../inc/OffMode.h"
#include "../inc/Thermostat.h"

void OffMode::run(const Thermostat &thermostat) const
{
    std::cout << "[" << thermostat.getDeviceID() << "] IDLE (nothing is working)\n";
}

std::string OffMode::getName() const
{
    return "OFF";
}