#ifndef OFF_MODE_H
#define OFF_MODE_H

#include <string>
#include <memory>
#include "ClimateActuator.h"
#include "Mode.h"

class OffMode : public Mode
{
private:
    std::shared_ptr<ClimateActuator> heater;
    std::shared_ptr<ClimateActuator> cooler;

public:
    explicit OffMode(std::shared_ptr<ClimateActuator> heater, std::shared_ptr<ClimateActuator> cooler);
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;

    void stop() const override;

    ~OffMode() noexcept override = default;
};

#endif