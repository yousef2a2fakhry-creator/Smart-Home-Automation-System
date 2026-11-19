#include "../inc/LEDLight.h"
LEDLight::LEDLight(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int brightness,
    bool status)
    : Light(deviceID, vendor, countryOfManufacture, year, brightness, status) {}

void LEDLight::turnON()
{
    status = true;
    brightness = 100; // Set brightness to maximum when turned on
}
void LEDLight::turnOFF()
{
    status = false;
    brightness = 0; // Set brightness to zero when turned off
}
std::string LEDLight::getType() const
{
    return "LED Light";
}
