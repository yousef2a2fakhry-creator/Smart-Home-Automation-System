#ifndef LED_LIGHT_H
#define LED_LIGHT_H

#include <string>
#include "Light.h"

class LEDLight : public Light
{
public:
    LEDLight(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int brightness = 0,
        bool status = false);

    virtual void turnON() override;
    virtual void turnOFF() override;
    DeviceTypes getType() const override;
    ~LEDLight() noexcept override = default;
};

#endif