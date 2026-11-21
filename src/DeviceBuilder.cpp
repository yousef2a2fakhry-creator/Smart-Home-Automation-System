#include "../inc/DeviceBuilder.h"
#include "../inc/DeviceFactory.h"

#include <stdexcept>
#include <string>

DeviceBuilder::DeviceBuilder()
    : type(DeviceTypes::LEDLight),
      typeSet(false),
      deviceID(""),
      vendor(""),
      countryOfManufacture(""),
      year(0),
      brightness(0),
      status(false),
      targetTemperature(22.0),
      ecoMode(false),
      targetHumidity(50.0),
      nightVision(false),
      recording(false),
      cableType("Ethernet/PoE"),
      batteryLevel(100),
      wifiSSID(""),
      zone(""),
      motionDetected(false),
      isLocked(false),
      ordinaryTemperature(20),
      degree(22.0)
{
}

DeviceBuilder::DeviceBuilder(DeviceTypes deviceType)
    : type(deviceType),
      typeSet(true),
      deviceID(""),
      vendor(""),
      countryOfManufacture(""),
      year(0),
      brightness(0),
      status(false),
      targetTemperature(22.0),
      ecoMode(false),
      targetHumidity(50.0),
      nightVision(false),
      recording(false),
      cableType("Ethernet/PoE"),
      batteryLevel(100),
      wifiSSID(""),
      zone(""),
      motionDetected(false),
      isLocked(false),
      ordinaryTemperature(20),
      degree(22.0)
{
}

DeviceBuilder &DeviceBuilder::setType(DeviceTypes deviceType)
{
    type = deviceType;
    typeSet = true;
    return *this;
}

DeviceBuilder &DeviceBuilder::setID(const std::string &value)
{
    deviceID = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setVendor(const std::string &value)
{
    vendor = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setCountry(const std::string &value)
{
    countryOfManufacture = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setYear(int value)
{
    year = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setBrightness(int value)
{
    brightness = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setStatus(bool value)
{
    status = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setTemperature(int value)
{
    ordinaryTemperature = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setDegree(double value)
{
    degree = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setTargetTemperature(double value)
{
    targetTemperature = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setEcoMode(bool value)
{
    ecoMode = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setTargetHumidity(double value)
{
    targetHumidity = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setNightVision(bool value)
{
    nightVision = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setRecording(bool value)
{
    recording = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setCableType(const std::string &value)
{
    cableType = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setBatteryLevel(int value)
{
    batteryLevel = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setWifiSSID(const std::string &value)
{
    wifiSSID = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setZone(const std::string &value)
{
    zone = value;
    return *this;
}
DeviceBuilder &DeviceBuilder::setMotionDetected(bool value)
{
    motionDetected = value;
    return *this;
}

DeviceBuilder &DeviceBuilder::setIsLocked(bool value)
{
    isLocked = value;
    return *this;
}

namespace
{
    void requireInRange(int value, int low, int high, const std::string &name)
    {
        if (value < low || value > high)
            throw std::invalid_argument("DeviceBuilder: " + name + " must be between " +
                                        std::to_string(low) + " and " + std::to_string(high) +
                                        " (got " + std::to_string(value) + ")");
    }

    void requireInRange(double value, double low, double high, const std::string &name)
    {
        if (value < low || value > high)
            throw std::invalid_argument("DeviceBuilder: " + name + " must be between " +
                                        std::to_string(low) + " and " + std::to_string(high) +
                                        " (got " + std::to_string(value) + ")");
    }
}

void DeviceBuilder::validate() const
{
    if (!typeSet)
        throw std::invalid_argument(
            "DeviceBuilder: the device type was not set. "
            "Pass it to the constructor or call setType(...) before build().");

    if (deviceID.empty())
        throw std::invalid_argument("DeviceBuilder: deviceID must not be empty");
    if (year <= 0)
        throw std::invalid_argument("DeviceBuilder: year must be a positive number");

    switch (type)
    {
    case DeviceTypes::LEDLight:
    case DeviceTypes::HalogenLight:
        requireInRange(brightness, 0, 100, "brightness");
        break;

    case DeviceTypes::SmartThermostatB:
        requireInRange(targetHumidity, 0.0, 100.0, "targetHumidity");
        break;

    case DeviceTypes::WirelessSecurityCamera:
        requireInRange(batteryLevel, 0, 100, "batteryLevel");
        break;

    default:
        break;
    }
}

std::shared_ptr<SmartDevice> DeviceBuilder::build() const
{
    validate();
    return DeviceFactory::createDevice(type, *this);
}
