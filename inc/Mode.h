#ifndef MODE_H
#define MODE_H

#include <string>

class Thermostat; 
class Mode
{
public:
    virtual void run(const Thermostat &thermostat) const = 0;
    virtual std::string getName() const = 0;

    virtual ~Mode() noexcept = default;
};

#endif