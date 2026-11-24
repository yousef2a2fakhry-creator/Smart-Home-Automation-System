#ifndef WIRELESS_SECURITY_CAMERA_H
#define WIRELESS_SECURITY_CAMERA_H

#include "SecurityCamera.h"
#include <string>

class WirelessSecurityCamera : public SecurityCamera
{
private:
    int batteryLevel;
    std::string wifiSSID;

public:
    WirelessSecurityCamera(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        int batteryLevel = 100,
        bool nightVision = false,
        bool recording = false,
        const std::string &wifiSSID = "");

    int getBatteryLevel() const;
    void setBatteryLevel(int value);
    std::string getWifiSSID() const;
    void setWifiSSID(const std::string &ssid);
    DeviceTypes getType() const override;

    ~WirelessSecurityCamera() noexcept override = default;
};

#endif