#ifndef DEVICE_COMPONENT_H
#define DEVICE_COMPONENT_H

#include <string>

// Component interface of the Composite pattern.
// Implemented by single devices (leaves) and by DeviceGroup (composite).
class DeviceComponent
{
public:
    virtual std::string getType() const = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;

    virtual ~DeviceComponent() noexcept = default;
};

#endif
