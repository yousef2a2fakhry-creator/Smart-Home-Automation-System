#include "../inc/Controller.h"

std::shared_ptr<Controller> Controller::Uniqe_Controller = nullptr;

Controller::Controller()
{
}
std::shared_ptr<Controller> Controller::getInstance()
{
    if (!Uniqe_Controller)
    {
        Uniqe_Controller = std::shared_ptr<Controller>(new Controller());
    }
    return Uniqe_Controller;
}

bool Controller::AssignDevice(std::shared_ptr<SmartDevice> device, const std::string &name)
{
    if (!device || name.empty())
        return false;

    // the name must be unique
    if (Devices.find(name) != Devices.end())
        return false;

    // the device must be unique (it can only be registered once, under one name)
    const std::string id = device->getDeviceID();
    for (const auto &entry : Devices)
    {
        if (entry.second->getDeviceID() == id)
            return false;
    }

    Devices[name] = device;
    return true;
}

std::shared_ptr<SmartDevice> Controller::getDeviceByName(const std::string &name) const
{
    auto it = Devices.find(name);
    if (it != Devices.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<SmartDevice> Controller::getDeviceByID(const std::string &ID) const
{
    for (const auto &entry : Devices)
    {
        if (entry.second->getDeviceID() == ID)
        {
            return entry.second;
        }
    }
    return nullptr;
}

bool Controller::hasName(const std::string &name) const
{
    return Devices.find(name) != Devices.end();
}

bool Controller::removeDevice(const std::string &name)
{
    return Devices.erase(name) > 0;
}