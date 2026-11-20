#include "../inc/MotionSensor.h"
#include "Observer.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

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
    notifyAll();
}
void MotionSensor::clearMotion()
{
    motionDetected = false;
    notifyAll();
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

std::string MotionSensor::generate_uuid() const
{
    auto id = boost::uuids::random_generator()();
    return boost::uuids::to_string(id);
}

std::string MotionSensor::registerUser(std::shared_ptr<Observer> subscriber)
{
    std::string id = generate_uuid();
    list_of_Subscribers_for_Motion_Sensor[id] = subscriber;
    subscriber->setSubscribeID(id);
    return id;
}

void MotionSensor::removeUser(std::string id)
{
    auto it = list_of_Subscribers_for_Motion_Sensor.find(id);
    if (it != list_of_Subscribers_for_Motion_Sensor.end())
    {
        list_of_Subscribers_for_Motion_Sensor.erase(it);
    }
}

void MotionSensor::notifyAll() const
{
    for (const auto &subscriber : list_of_Subscribers_for_Motion_Sensor)
    {
        subscriber.second->update(*this);
    }
}