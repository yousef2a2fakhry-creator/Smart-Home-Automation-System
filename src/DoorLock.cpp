#include "../inc/DoorLock.h"
#include "Observer.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

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

std::string DoorLock::generate_uuid() const
{
    auto id = boost::uuids::random_generator()();
    return boost::uuids::to_string(id);
}

std::string DoorLock::registerUser(std::shared_ptr<Observer> subscruiber)
{
    std::string id = generate_uuid();
    list_of_Subscribers_for_Door_Lock[id] = subscruiber;
    subscruiber->setSubscribeID(id);
}
void DoorLock::removeUser(std::string id)
{
    auto it = list_of_Subscribers_for_Door_Lock.find(id);
    if (it != list_of_Subscribers_for_Door_Lock.end())
    {
        list_of_Subscribers_for_Door_Lock.erase(it);
    }
}
void DoorLock::notifyAll() const
{
    for(auto it : list_of_Subscribers_for_Door_Lock)
    {
        it.second->update(*this);
    }
}