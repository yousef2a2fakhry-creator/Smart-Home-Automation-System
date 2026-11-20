#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <string>
#include <memory>
#include <unordered_map>
#include "SmartDevice.h"
#include "Observee.h"
#include "Observer.h"

class MotionSensor : public SmartDevice, Observee
{
private:
    std::string zone;
    bool motionDetected;
    std::unordered_map<std::string, std::shared_ptr<Observer>> list_of_Subscribers_for_Motion_Sensor;

public:
    MotionSensor(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        const std::string &zone = "",
        bool motionDetected = false);

    void detectMotion();
    void clearMotion();

    std::string getZone() const;
    void setZone(const std::string &zone);

    virtual void notifyAll() const override;
    virtual std::string registerUser(std::shared_ptr<Observer> subscriber) override;
    virtual void removeUser(std::string id) override;
    virtual std::string generate_uuid() const override;

    std::string getType() const override;

       ~MotionSensor() noexcept override = default;
};

#endif