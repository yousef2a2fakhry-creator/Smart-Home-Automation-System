#ifndef DOOR_LOCK_OBSERVER_H
#define DOOR_LOCK_OBSERVER_H
#include <string>
class DoorLock;

class DoorLockObserver
{
protected:
    std::string observer_id;
public:
    virtual void update(const DoorLock &doorLock) = 0;
    virtual void setSubscribeID(std::string id) = 0;
    virtual ~DoorLockObserver() noexcept = default;
};

#endif