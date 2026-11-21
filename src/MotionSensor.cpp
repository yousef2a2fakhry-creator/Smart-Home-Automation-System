#include "../inc/MotionSensor.h"
#include <random>
#include <sstream>
#include <iomanip>

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
    static std::mt19937_64 gen{std::random_device{}()};
    std::uniform_int_distribution<unsigned long long> dist;
    std::ostringstream ss;
    ss << std::hex << std::setfill('0')
       << std::setw(16) << dist(gen) << std::setw(16) << dist(gen);
    return ss.str();
}

void MotionSensor::registerUser(std::shared_ptr<MotionObserver> subscriber)
{
    std::string id = generate_uuid();
    list_of_Subscribers_for_Motion_Sensor[id] = subscriber;
    subscriber->setSubscribeID(id);
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
bool MotionSensor::isMotionDetected() const
{
    return motionDetected;
}