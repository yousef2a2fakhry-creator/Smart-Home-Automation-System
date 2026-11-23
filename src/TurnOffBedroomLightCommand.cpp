#include "../inc/TurnOffBedroomLightCommand.h"

TurnOffLightCommand::TurnOffLightCommand(std::shared_ptr<DeviceComponent> deviceComponent)
    : deviceComponent(std::move(deviceComponent)) {}

void TurnOffLightCommand::execute()
{
    if (deviceComponent)
        deviceComponent->deactivate();
}

void TurnOffLightCommand::undo()
{
    if (deviceComponent)
        deviceComponent->activate();
}
