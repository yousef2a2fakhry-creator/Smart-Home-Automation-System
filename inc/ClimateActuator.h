#ifndef CLIMATE_ACTUATOR_H
#define CLIMATE_ACTUATOR_H

// Target interface of the Adapter:
// anything that can heat or cool a room looks like this to the modes.
class ClimateActuator
{
public:
    virtual void turnOn(double target) = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;

    virtual ~ClimateActuator() noexcept = default;
};

#endif