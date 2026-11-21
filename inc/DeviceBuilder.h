#ifndef DEVICE_BUILDER_H
#define DEVICE_BUILDER_H

#include <memory>
#include <string>
#include "SmartDevice.h"
#include "DeviceTypes.h"

class DeviceBuilder
{
private:
    friend class DeviceFactory;
    DeviceTypes type;
    bool typeSet;
    std::string deviceID;
    std::string vendor;
    std::string countryOfManufacture;
    int year;
    int brightness;
    bool status;
    double targetTemperature;
    bool ecoMode;
    double targetHumidity;
    bool nightVision;
    bool recording;
    std::string cableType;
    int batteryLevel;
    std::string wifiSSID;
    std::string zone;
    bool motionDetected;
    bool isLocked;
    int Heater_Temprature;
    int AC_Temprature;

    void validate() const;

public:
    DeviceBuilder();
    explicit DeviceBuilder(DeviceTypes deviceType);
    DeviceBuilder &setType(DeviceTypes deviceType);
    DeviceBuilder &setID(const std::string &value);
    DeviceBuilder &setVendor(const std::string &value);
    DeviceBuilder &setCountry(const std::string &value);
    DeviceBuilder &setYear(int value);
    DeviceBuilder &setBrightness(int value);
    DeviceBuilder &setStatus(bool value);
    DeviceBuilder &setHeater_Temprature(int value);
    DeviceBuilder &setAC_Temprature(int value);
    DeviceBuilder &setTargetTemperature(double value);
    DeviceBuilder &setEcoMode(bool value);
    DeviceBuilder &setTargetHumidity(double value);
    DeviceBuilder &setNightVision(bool value);
    DeviceBuilder &setRecording(bool value);
    DeviceBuilder &setCableType(const std::string &value);
    DeviceBuilder &setBatteryLevel(int value);
    DeviceBuilder &setWifiSSID(const std::string &value);
    DeviceBuilder &setZone(const std::string &value);
    DeviceBuilder &setMotionDetected(bool value);
    DeviceBuilder &setIsLocked(bool value);
    std::shared_ptr<SmartDevice> build() const;
};

#endif
