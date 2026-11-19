#include "../inc/Light.h"
Light::Light(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int brightness,
    bool status)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), status(status)
{
    setBrightness(brightness); // applies the 0-100 limit to the starting value
}

int Light::getBrightness() const
{
    return brightness;
}
bool Light::getStatus() const
{
    return status;
}
void Light::setStatus(bool value)
{
    status = value;
}
void Light::setBrightness(int value)
{
    if (value < 0)
        brightness = 0;
    else if (value > 100)
        brightness = 100;
    else
        brightness = value;
}