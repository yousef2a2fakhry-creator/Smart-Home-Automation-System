#ifndef LIGHT_H
#define LIGHT_H
#include "SmartDevice.h"
#include "MotionObserver.h"
#include <string>

class Light : public SmartDevice , public MotionObserver
{
protected:
    int brightness;
    bool status;

public:
    // The initial brightness and status are 0 and false.
    Light(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int brightness = 0,
        bool status = false);

    virtual void turnON() = 0;
    virtual void turnOFF() = 0;
    virtual void setBrightness(int value);
    int getBrightness() const;
    bool getStatus() const;
    void setStatus(bool value);

    virtual void update(const MotionSensor &) override;
    virtual void setSubscribeID(std::string id) override;
    virtual std::string getType() const override;

    ~Light() noexcept override = default;
};

#endif
