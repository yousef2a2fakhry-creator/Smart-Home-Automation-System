#ifndef OFF_MODE_H
#define OFF_MODE_H

#include <string>
#include "Mode.h"

class OffMode : public Mode
{
public:
    void run(const Thermostat &thermostat) const override;
    std::string getName() const override;

    ~OffMode() noexcept override = default;
};

#endif