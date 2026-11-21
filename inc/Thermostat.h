#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include "SmartDevice.h"
#include <memory>
#include "Mode.h"
class Thermostat : public SmartDevice
{
protected:
    double temperature;
    double targetTemperature;
    std::shared_ptr<Mode> mode;

public:
    Thermostat(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        double targetTemperature = 22.0);

    virtual void setMode(std::shared_ptr<Mode> newMode);
    virtual void run() const;
    virtual std::string getModeName() const;

    virtual void setTargetTemperature(double value);
    void setTemperature(double value);
    double getTargetTemperature() const;
    double getTemperature() const;
    void activate() override;
    void deactivate() override;
    ~Thermostat() noexcept override = default;
};

#endif