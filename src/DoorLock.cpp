#include "../inc/DoorLock.h"
DoorLock::DoorLock(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    bool isLocked)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), isLocked(isLocked) {}
void DoorLock::lock()
{
    isLocked = true;
}
void DoorLock::unlock()
{
    isLocked = false;
}
std::string DoorLock::getType() const
{
    return "DoorLock";
}