#ifndef SMART_DEVICE_H
#define SMART_DEVICE_H
#include <string>
#include "DeviceComponent.h"
class SmartDevice : public DeviceComponent

{
private:
    std::string deviceID;
    std::string vendor;
    std::string countryOfManufacture;
    int year;

public:
    SmartDevice(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year);

    std::string getDeviceID() const;
    std::string getVendor() const;
    std::string getCountryOfManufacture() const;
    int getYear() const;

    virtual ~SmartDevice() noexcept override= default;
};


#endif