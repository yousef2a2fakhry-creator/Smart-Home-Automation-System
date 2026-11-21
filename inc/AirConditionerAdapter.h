#ifndef AIR_CONDITIONER_ADAPTER_H
#define AIR_CONDITIONER_ADAPTER_H

#include <memory>
#include "ClimateActuator.h"
#include "OrdinaryAirConditioner.h"

class AirConditionerAdapter : public ClimateActuator
{
private:
    std::shared_ptr<OrdinaryAirConditioner> ac; // the adaptee

public:
    explicit AirConditionerAdapter(std::shared_ptr<OrdinaryAirConditioner> ac);

    void turnOn(double target) override;
    void turnOff() override;
    bool isOn() const override;

    ~AirConditionerAdapter() noexcept override = default;
};

#endif