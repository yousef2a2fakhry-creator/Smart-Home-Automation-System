#ifndef ORDINARY_HEATER_H
#define ORDINARY_HEATER_H
#include <string>
#include "SmartDevice.h"

class OrdinaryHeater : public SmartDevice
{
private:
    int Heater_Temprature;
    bool isOn;

public:
    OrdinaryHeater(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int Heater_Temprature = 20,
        bool isOn = false);

    void turnOn();
    void turnOff();
    void setHeater_Temprature(int value);
    int getHeater_Temprature() const;
    bool getStatus() const;
    std::string getType() const override;

    ~OrdinaryHeater() noexcept override = default;
};

#endif // ORDINARY_HEATER_H