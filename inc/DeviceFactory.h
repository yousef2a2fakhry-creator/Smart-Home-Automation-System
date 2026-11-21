#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include <memory>
#include "SmartDevice.h"
#include "DeviceTypes.h"

class DeviceBuilder;

class DeviceFactory
{
private:
    // preven t any one form crating a factory object
    DeviceFactory();
public:
    static std::shared_ptr<SmartDevice> createDevice(DeviceTypes deviceType, const DeviceBuilder &builder);
};

#endif 
