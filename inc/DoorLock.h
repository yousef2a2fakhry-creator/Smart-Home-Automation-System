#ifndef DOOR_LOCK_H
#define DOOR_LOCK_H

#include <string>
#include "SmartDevice.h"

class DoorLock : public SmartDevice
{
private:
    bool isLocked;

public:
    DoorLock(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        bool isLocked = false);

    void lock();
    void unlock();
    std::string getType() const override;

    ~DoorLock() noexcept override = default;
};

#endif