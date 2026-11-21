#include "../inc/HeaterAdapter.h"

HeaterAdapter::HeaterAdapter(std::shared_ptr<OrdinaryHeater> heater)
    : heater(heater) {}

void HeaterAdapter::turnOn(double target)
{
    // legacy heater stores an int and has a parameterless turnOn()
    heater->setHeater_Temprature(static_cast<int>(target));
    heater->turnOn();
}

void HeaterAdapter::turnOff()
{
    heater->turnOff();
}

bool HeaterAdapter::isOn() const
{
    return heater->getStatus();
}