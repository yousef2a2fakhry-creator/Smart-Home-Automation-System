#include <iostream>
#include "../inc/OffMode.h"
#include "../inc/Thermostat.h"
OffMode::OffMode(std::shared_ptr<ClimateActuator> h, std::shared_ptr<ClimateActuator> c)
    : heater(h), cooler(c) {}
void OffMode::run(const Thermostat &thermostat) const
{
    stop();
    std::cout << "[" << thermostat.getDeviceID() << "] IDLE (nothing is working)\n";
}

std::string OffMode::getName() const
{
    return "OFF";
}

void OffMode::stop() const
{
    heater->turnOff();
    cooler->turnOff();
}