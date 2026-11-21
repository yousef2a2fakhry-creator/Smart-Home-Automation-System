#ifndef COOLING_MODE_H
#define COOLING_MODE_H

#include <string>
#include <memory>
#include "ClimateActuator.h"
#include "Mode.h"

class CoolingMode : public Mode
{
private:
    std::shared_ptr<ClimateActuator> cooler;

public:
    explicit CoolingMode(std::shared_ptr<ClimateActuator> cooler);
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;
    void stop() const override;

    ~CoolingMode() noexcept override = default;
};

#endif