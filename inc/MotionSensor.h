#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <string>
#include <memory>
#include <unordered_map>
#include "MotionObserver.h"
#include "SmartDevice.h"

class MotionSensor : public SmartDevice
{
private:
    std::string zone;
    bool motionDetected;
    std::unordered_map<std::string, std::shared_ptr<MotionObserver>> list_of_Subscribers_for_Motion_Sensor;

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
    bool isMotionDetected() const;

    std::string getZone() const;
    void setZone(const std::string &zone);

    virtual void notifyAll() const ;
    virtual void registerUser(std::shared_ptr<MotionObserver> subscriber) ;
    virtual void removeUser(std::string id) ;
    virtual std::string generate_uuid() const ;

    std::string getType() const override;

    ~MotionSensor() noexcept override = default;
};

#endif