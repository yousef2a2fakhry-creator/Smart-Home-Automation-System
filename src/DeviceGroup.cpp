
#include "../inc/DeviceGroup.h"

DeviceGroup::DeviceGroup(const std::string &name) : name(name) {}

void DeviceGroup::add(std::shared_ptr<DeviceComponent> child)
{
    if (child == nullptr || child.get() == this)
        return;
    children.push_back(child);
}

bool DeviceGroup::remove(const std::shared_ptr<DeviceComponent> &child)
{
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if (it->get() == child.get()) 
        {
            children.erase(it);
            return true; 
        }
    }
    return false; 
}

int DeviceGroup::getChildCount() const
{
    return static_cast<int>(children.size());
}

std::string DeviceGroup::getType() const
{
    return name;
}

void DeviceGroup::activate()
{
    for (auto &child : children)
        child->activate();
}

void DeviceGroup::deactivate()
{
    for (auto &child : children)
        child->deactivate();
}
