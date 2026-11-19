#ifndef COOLING_MODE_H
#define COOLING_MODE_H

#include <string>
#include "Mode.h"

class CoolingMode : public Mode
{
public:
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;

    ~CoolingMode() noexcept override = default;
};

#endif