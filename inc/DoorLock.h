#ifndef DOOR_LOCK_H
#define DOOR_LOCK_H

#include <string>
#include <memory>
#include "SmartDevice.h"
#include <unordered_map>
#include "Observee.h"
#include "Observer.h"

class DoorLock : public SmartDevice, Observee
{
private:
    bool isLocked;
    std::unordered_map<std::string, std::shared_ptr<Observer>> list_of_Subscribers_for_Door_Lock;

public:
    DoorLock(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        bool isLocked = false);

    void lock();
    void unlock();

    virtual void notifyAll() const override;
    virtual std::string registerUser(std::shared_ptr<Observer> subscruiber) override;
    virtual void removeUser(std::string) override;

    virtual std::string generate_uuid() const override;

    std::string getType() const override;
    ~DoorLock() noexcept override = default;
};

#endif