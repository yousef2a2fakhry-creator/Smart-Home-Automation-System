#include "../inc/OrdinaryAirConditioner.h"

OrdinaryAirConditioner::OrdinaryAirConditioner(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    double degree,
    bool isOn)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year),
      degree(degree),
      isOn(isOn) {}

void OrdinaryAirConditioner::turnOn(double degree)
{
    setDegree(degree);
    isOn = true;
}

void OrdinaryAirConditioner::turnOff()
{
    isOn = false;
}

void OrdinaryAirConditioner::setDegree(double degree)
{
    this->degree = degree;
}

double OrdinaryAirConditioner::getDegree() const
{
    return degree;
}

bool OrdinaryAirConditioner::getStatus() const
{
    return isOn;
}

std::string OrdinaryAirConditioner::getType() const
{
    return "OrdinaryAirConditioner";
}
