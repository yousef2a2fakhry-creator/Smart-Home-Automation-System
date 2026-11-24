#ifndef HALOGEN_LIGHT_H
#define HALOGEN_LIGHT_H

#include <string>
#include "Light.h"

class HalogenLight : public Light
{
public:
    HalogenLight(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int brightness = 0,
        bool status = false);

    virtual void turnON() override;
    virtual void turnOFF() override;
    DeviceTypes getType() const override;
    ~HalogenLight() noexcept override = default;
};

#endif