#ifndef ORDINARY_HEATER_H
#define ORDINARY_HEATER_H
#include <string>
#include "SmartDevice.h"

class OrdinaryHeater : public SmartDevice
{
private:
    int temperature;
    bool isOn;

public:
    OrdinaryHeater(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int temperature = 20,
        bool isOn = false);

    void turnOn();
    void turnOff();
    void setTemperature(int temp);
    int getTemperature() const;
    bool getStatus() const;
    std::string getType() const override;

    ~OrdinaryHeater() noexcept override = default;
};

#endif // ORDINARY_HEATER_H