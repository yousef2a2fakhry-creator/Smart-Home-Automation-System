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
    std::unordered_map<std::string, std::shared_ptr<SmartDevice>> Devices;

public:
    Controller(const Controller &) = delete;
    const Controller &operator=(const Controller &) = delete;
    virtual ~Controller() noexcept = default;
    static std::shared_ptr<Controller> getInstance();

    // Register a device under a name. A name is required.
    // Nothing can be repeated: returns false if the device is null, the name is
    // empty, the name is already used, or the device is already registered.
    bool AssignDevice(std::shared_ptr<SmartDevice> device, const std::string &name);

    // name -> device (returns nullptr if the name is unknown)
    std::shared_ptr<SmartDevice> getDeviceByName(const std::string &name) const;

    // ID -> device (scans the devices, returns nullptr if the ID is unknown)
    std::shared_ptr<SmartDevice> getDeviceByID(const std::string &ID) const;

    bool hasName(const std::string &name) const;

    // Remove a device by its name. Returns false if the name is unknown.
    bool removeDevice(const std::string &name);
};

#endif
