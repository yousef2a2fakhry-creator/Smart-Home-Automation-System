#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H
#include "SmartDevice.h"
#include "DeviceTypes.h"
#include  <memory>

class DeviceFactory
{
public:
    static std::unique_ptr<SmartDevice> createDevice(DeviceTypes deviceType, const std::string &deviceID, const std::string &vendor, const std::string &countryOfManufacture, int year);
};
#endif // DEVICE_FACTORY_H