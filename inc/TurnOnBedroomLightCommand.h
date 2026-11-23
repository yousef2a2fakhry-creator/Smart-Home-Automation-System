#ifndef TURN_ON_LIGHT_COMMAND_H
#define TURN_ON_LIGHT_COMMAND_H

#include <memory>
#include "Command.h"
#include "DeviceComponent.h"

// Works on any DeviceComponent: a single light or a whole group (e.g. bedroom).
class TurnOnLightCommand : public Command
{
private:
    std::shared_ptr<DeviceComponent> deviceComponent;

public:
    explicit TurnOnLightCommand(std::shared_ptr<DeviceComponent> deviceComponent);
    ~TurnOnLightCommand() noexcept override = default;

    void execute() override;
    void undo() override;
};

#endif
