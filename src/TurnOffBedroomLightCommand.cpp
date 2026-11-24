#include "../inc/TurnOffBedroomLightCommand.h"

TurnOffLightCommand::TurnOffLightCommand(std::shared_ptr<DeviceComponent> deviceComponent)
    : deviceComponent(std::move(deviceComponent)) {}

// the logic of selecting only the light of the bedrooms is in the controller
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
