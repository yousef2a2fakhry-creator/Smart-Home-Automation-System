#ifndef HEATER_ADAPTER_H
#define HEATER_ADAPTER_H

#include <memory>
#include "ClimateActuator.h"
#include "OrdinaryHeater.h"

class HeaterAdapter : public ClimateActuator
{
private:
    std::shared_ptr<OrdinaryHeater> heater; // the adaptee (legacy device)

public:
    explicit HeaterAdapter(std::shared_ptr<OrdinaryHeater> heater);

    void turnOn(double target) override;
    void turnOff() override;
    bool isOn() const override;

    ~HeaterAdapter() noexcept override = default;
};

#endif