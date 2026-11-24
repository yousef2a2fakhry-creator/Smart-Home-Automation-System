#include "../inc/OrdinaryHeater.h"

OrdinaryHeater::OrdinaryHeater(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int Heater_Temprature,
    bool isOn)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year),
      Heater_Temprature(Heater_Temprature),
      isOn(isOn) {}

void OrdinaryHeater::turnOn()
{
    isOn = true;
}

void OrdinaryHeater::turnOff()
{
    isOn = false;
}

void OrdinaryHeater::setHeater_Temprature(int value)
{
    Heater_Temprature = value;
}

int OrdinaryHeater::getHeater_Temprature() const
{
    return Heater_Temprature;
}

bool OrdinaryHeater::getStatus() const
{
    return isOn;
}

DeviceTypes OrdinaryHeater::getType() const
{
    return DeviceTypes::OrdinaryHeater;
}

void OrdinaryHeater::activate()
{
    turnOn();
}

void OrdinaryHeater::deactivate()
{
    turnOff();
}
