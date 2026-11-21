#include "../inc/OrdinaryHeater.h"

OrdinaryHeater::OrdinaryHeater(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int temperature,
    bool isOn)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year),
      temperature(temperature),
      isOn(isOn) {}

void OrdinaryHeater::turnOn()
{
    isOn = true;
}

void OrdinaryHeater::turnOff()
{
    isOn = false;
}

void OrdinaryHeater::setTemperature(int temp)
{
    temperature = temp;
}

int OrdinaryHeater::getTemperature() const
{
    return temperature;
}

bool OrdinaryHeater::getStatus() const
{
    return isOn;
}

std::string OrdinaryHeater::getType() const
{
    return "OrdinaryHeater";
}
