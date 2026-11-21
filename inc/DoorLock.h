#ifndef DOOR_LOCK_H
#define DOOR_LOCK_H

#include <string>
#include <memory>
#include "SmartDevice.h"
#include <unordered_map>
#include "DoorLockObserver.h"
class DoorLock : public SmartDevice
{
private:
    bool isLocked;
    std::unordered_map<std::string, std::shared_ptr<DoorLockObserver>> list_of_Subscribers_for_Door_Lock;

public:
    DoorLock(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        bool isLocked = false);

    void lock();
    void unlock();
    bool CheckLock() const;

    virtual void notifyAll() const ;
    virtual void registerUser(std::shared_ptr<DoorLockObserver> subscriber) ;
    virtual void removeUser(std::string) ;

    std::string getType() const override;
    void activate() override;
    void deactivate() override;
    ~DoorLock() noexcept override = default;
};

#endif