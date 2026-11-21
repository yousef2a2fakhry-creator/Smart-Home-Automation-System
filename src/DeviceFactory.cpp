#include "../inc/DeviceFactory.h"
#include "../inc/DeviceBuilder.h"

#include <stdexcept>

#include "../inc/LEDLight.h"
#include "../inc/HalogenLight.h"
#include "../inc/SmartThermostatA.h"
#include "../inc/SmartThermostatB.h"
#include "../inc/WiredSecurityCamera.h"
#include "../inc/WirelessSecurityCamera.h"
#include "../inc/DoorLock.h"
#include "../inc/MotionSensor.h"
#include "../inc/OrdinaryHeater.h"
#include "../inc/OrdinaryAirConditioner.h"

std::shared_ptr<SmartDevice> DeviceFactory::createDevice(DeviceTypes deviceType, const DeviceBuilder &b)
{
    switch (deviceType)
    {
    case DeviceTypes::LEDLight:
        return std::make_shared<LEDLight>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.brightness, b.status);

    case DeviceTypes::HalogenLight:
        return std::make_shared<HalogenLight>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.brightness, b.status);

    case DeviceTypes::SmartThermostatA:
        return std::make_shared<SmartThermostatA>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.targetTemperature, b.ecoMode);

    case DeviceTypes::SmartThermostatB:
        return std::make_shared<SmartThermostatB>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.targetTemperature, b.targetHumidity);

    case DeviceTypes::WiredSecurityCamera:
        return std::make_shared<WiredSecurityCamera>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.cableType, b.nightVision, b.recording);

    case DeviceTypes::WirelessSecurityCamera:
        return std::make_shared<WirelessSecurityCamera>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.batteryLevel, b.nightVision, b.recording, b.wifiSSID);

    case DeviceTypes::DoorLock:
        return std::make_shared<DoorLock>(
            b.deviceID, b.vendor, b.countryOfManufacture, b.year,
            b.isLocked);

    case DeviceTypes::MotionSensor:
    return std::make_shared<MotionSensor>(
        b.deviceID, b.vendor, b.countryOfManufacture, b.year,
        b.zone, b.motionDetected);

    case DeviceTypes::OrdinaryHeater:
    return std::make_shared<OrdinaryHeater>(
        b.deviceID, b.vendor, b.countryOfManufacture, b.year,
        b.Heater_Temprature, b.status);

    case DeviceTypes::OrdinaryAirConditioner:
    return std::make_shared<OrdinaryAirConditioner>(
        b.deviceID, b.vendor, b.countryOfManufacture, b.year,
        b.AC_Temprature, b.status);

    default:
        throw std::invalid_argument("DeviceFactory: this device type cannot be instantiated");
    }
}
