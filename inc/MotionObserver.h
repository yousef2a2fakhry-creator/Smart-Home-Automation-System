#ifndef MOTION_OBSERVER_H
#define MOTION_OBSERVER_H

class MotionSensor;

class MotionObserver
{
protected:
    std::string observer_id;    
public:
    virtual void update(const MotionSensor &sensor) = 0;
    virtual void setSubscribeID(std::string id) = 0;
    virtual ~MotionObserver() noexcept = default;
};

#endif