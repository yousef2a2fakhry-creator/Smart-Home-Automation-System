#include "../inc/TurnOnBedroomLightCommand.h"

TurnOnLightCommand::TurnOnLightCommand(std::shared_ptr<DeviceComponent> deviceComponent)
    : deviceComponent(std::move(deviceComponent)) {}

void TurnOnLightCommand::execute()
{
    if (deviceComponent)
        deviceComponent->activate();
}

void TurnOnLightCommand::undo()
{
    if (deviceComponent)
        deviceComponent->deactivate();
}
