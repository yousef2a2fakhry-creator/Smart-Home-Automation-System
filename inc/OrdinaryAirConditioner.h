#ifndef ORDINARY_AIR_CONDITIONER_H
#define ORDINARY_AIR_CONDITIONER_H

#include <string>
#include "SmartDevice.h"

class OrdinaryAirConditioner : public SmartDevice
{
private:
    int AC_Temprature;
    bool isOn;

public:
    OrdinaryAirConditioner(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int AC_Temprature = 22,
        bool isOn = false);

    void turnOn();
    void turnOff();
    void setAC_Temprature(int value);
    int getAC_Temprature() const;
    bool getStatus() const;
    DeviceTypes getType() const override;
    void activate() override;
    void deactivate() override;

    ~OrdinaryAirConditioner() noexcept override = default;
};

#endif