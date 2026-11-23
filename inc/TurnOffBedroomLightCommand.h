#ifndef TURN_OFF_LIGHT_COMMAND_H
#define TURN_OFF_LIGHT_COMMAND_H

#include <memory>
#include "Command.h"
#include "DeviceComponent.h"

class TurnOffLightCommand : public Command
{
private:
    std::shared_ptr<DeviceComponent> deviceComponent;

public:
    explicit TurnOffLightCommand(std::shared_ptr<DeviceComponent> deviceComponent);
    ~TurnOffLightCommand() noexcept override = default;

    void execute() override;
    void undo() override;
};

#endif
