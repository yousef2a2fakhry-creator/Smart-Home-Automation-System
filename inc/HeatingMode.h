#ifndef HEATING_MODE_H
#define HEATING_MODE_H

#include <string>
#include "Mode.h"
#include "ClimateActuator.h"
#include <memory>

class HeatingMode : public Mode
{
private:
    std::shared_ptr<ClimateActuator> heater;

public:
    explicit HeatingMode(std::shared_ptr<ClimateActuator> heater);
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;

    void stop() const override;

    ~HeatingMode() noexcept override = default;
};

#endif