#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class MotionSensor;
class DoorLock;

class Observer
{
protected:
    std::string id;

public:
    virtual void update(const MotionSensor &) = 0;
    virtual void update(const DoorLock &) = 0;
    virtual void setSubscribeID(std::string) = 0;
    virtual ~Observer() noexcept = default;
};

#endif