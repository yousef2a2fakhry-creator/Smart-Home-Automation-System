#include "../inc/SmartDevice.h"
SmartDevice::SmartDevice(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year)
    : deviceID(deviceID), vendor(vendor), countryOfManufacture(countryOfManufacture), year(year) {}

std::string SmartDevice::getDeviceID() const
{
    return deviceID;
}
std::string SmartDevice::getVendor() const
{
    return vendor;
}
std::string SmartDevice::getCountryOfManufacture() const
{
    return countryOfManufacture;
}
int SmartDevice::getYear() const
{
    return year;
}