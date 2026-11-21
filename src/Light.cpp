#include "../inc/Light.h"
#include "../inc/MotionSensor.h"
#include "../inc/Clock.h"
#include <iostream>

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
void Light::update(const MotionSensor &sensor)
{
    // If motion is detected and it's night time, turn on the light. Otherwise, turn it off.
    if (sensor.isMotionDetected() && Clock::isNight()&& status== false)
    {
        turnON();
        // std::cout << "Motion detected in zone: " << sensor.getZone() << ". Light turned ON." << std::endl;
    }
}
void Light::setSubscribeID(std::string id)
{
    MotionObserver_id = id;
}
std::string Light::getType() const
{
    return "Light";
}