#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <string>
#include "SmartDevice.h"

class MotionSensor : public SmartDevice
{
private:
    std::string zone;
    bool motionDetected;

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

    std::string getType() const override;

   
    ~MotionSensor() noexcept override = default;
};

#endif