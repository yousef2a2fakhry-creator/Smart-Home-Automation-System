#ifndef ORDINARY_AIR_CONDITIONER_H
#define ORDINARY_AIR_CONDITIONER_H

#include <string>
#include "SmartDevice.h"

class OrdinaryAirConditioner : public SmartDevice
{
private:
    double degree;
    bool isOn;

public:
    OrdinaryAirConditioner(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        double degree = 22.0,
        bool isOn = false);

    void turnOn(double degree);
    void turnOff();
    void setDegree(double degree);
    double getDegree() const;
    bool getStatus() const;
    std::string getType() const override;

    ~OrdinaryAirConditioner() noexcept override = default;
};

#endif