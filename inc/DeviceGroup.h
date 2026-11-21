#ifndef DEVICE_GROUP_H
#define DEVICE_GROUP_H

#include <memory>
#include <string>
#include <vector>
#include "DeviceComponent.h"

// Composite: a room, a floor or a function group.
class DeviceGroup : public DeviceComponent
{
private:
    std::string name;
    std::vector<std::shared_ptr<DeviceComponent>> children;

public:
    explicit DeviceGroup(const std::string &name);

    void add(std::shared_ptr<DeviceComponent> child);
    bool remove(const std::shared_ptr<DeviceComponent> &child);
    int getChildCount() const;

    std::string getType() const override;
    void activate() override;
    void deactivate() override;

    ~DeviceGroup() noexcept override = default;
};

#endif
