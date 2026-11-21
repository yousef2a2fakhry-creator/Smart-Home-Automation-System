#include "../inc/OrdinaryAirConditioner.h"

OrdinaryAirConditioner::OrdinaryAirConditioner(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int AC_Temprature,
    bool isOn)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year),
      AC_Temprature(AC_Temprature),
      isOn(isOn) {}

void OrdinaryAirConditioner::turnOn(int AC_Temprature)
{
    setAC_Temprature(AC_Temprature);
    isOn = true;
}

void OrdinaryAirConditioner::turnOff()
{
    isOn = false;
}

void OrdinaryAirConditioner::setAC_Temprature(int value)
{
    AC_Temprature = value;
}

int OrdinaryAirConditioner::getAC_Temprature() const
{
    return AC_Temprature;
}

bool OrdinaryAirConditioner::getStatus() const
{
    return isOn;
}

std::string OrdinaryAirConditioner::getType() const
{
    return "OrdinaryAirConditioner";
}
