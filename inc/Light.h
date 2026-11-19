#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "SmartDevice.h"

class Light : public SmartDevice
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
    virtual void setBrightness(int value) = 0;
    int getBrightness() const;
    bool getStatus() const;
    void setStatus(bool value);

    ~Light() noexcept override = default;
};

#endif
