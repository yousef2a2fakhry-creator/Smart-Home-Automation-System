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
void Controller::AssignDevice(std::shared_ptr<SmartDevice> device)
{
    List_For_System_Devices[device->getDeviceID()] = device;
}

std::shared_ptr<SmartDevice> Controller::getDevice(std::string ID)
{
    auto it = List_For_System_Devices.find(ID);
    if (it != List_For_System_Devices.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}
