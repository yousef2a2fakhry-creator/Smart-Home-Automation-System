#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include <unordered_map>
#include "SmartDevice.h"
class Controller
{
private:
    Controller();
    static std::shared_ptr<Controller> Uniqe_Controller;
    std::unordered_map<std::string, std::shared_ptr<SmartDevice>> List_For_System_Devices;

public:
    Controller(const Controller &) = delete;
    const Controller &operator=(const Controller &) = delete;
    virtual ~Controller() noexcept = default;
    static std::shared_ptr<Controller> getInstance();

    void AssignDevice(std::shared_ptr<SmartDevice> device);
    std::shared_ptr<SmartDevice> getDevice(std::string ID);

    
};

#endif
