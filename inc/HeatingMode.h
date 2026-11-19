#ifndef HEATING_MODE_H
#define HEATING_MODE_H

#include <string>
#include "Mode.h"

class HeatingMode : public Mode
{
public:
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;

    ~HeatingMode() noexcept override = default;
};

#endif