#include "../inc/MotionSensor.h"

MotionSensor::MotionSensor(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    const std::string &zone,
    bool motionDetected)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), zone(zone), motionDetected(motionDetected) {}
void MotionSensor::detectMotion()
{
    motionDetected = true;
}
void MotionSensor::clearMotion()
{
    motionDetected = false;
}
void MotionSensor::setZone(const std::string &zone)
{
    this->zone = zone;
}
std::string MotionSensor::getZone() const
{
    return zone;
}
std::string MotionSensor::getType() const
{
    return "MotionSensor";
}