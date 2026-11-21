#include "../inc/AirConditionerAdapter.h"

AirConditionerAdapter::AirConditionerAdapter(std::shared_ptr<OrdinaryAirConditioner> ac)
    : ac(ac) {}

void AirConditionerAdapter::turnOn(double target)
{
    ac->setAC_Temprature(static_cast<int>(target));
    ac->turnOn(); // legacy AC takes the degree in turnOn
}

void AirConditionerAdapter::turnOff()
{
    ac->turnOff();
}

bool AirConditionerAdapter::isOn() const
{
    return ac->getStatus();
}