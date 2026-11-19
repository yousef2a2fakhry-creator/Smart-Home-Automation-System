#include "../inc/WirelessSecurityCamera.h"

WirelessSecurityCamera::WirelessSecurityCamera(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int batteryLevel,
    bool nightVision,
    bool recording,
    const std::string &wifiSSID)
    : SecurityCamera(deviceID, vendor, countryOfManufacture, year, nightVision, recording), wifiSSID(wifiSSID)
{
    setBatteryLevel(batteryLevel);
}

int WirelessSecurityCamera::getBatteryLevel() const
{
    return batteryLevel;
}

void WirelessSecurityCamera::setBatteryLevel(int value)
{
    if (value < 0)
        batteryLevel = 0;
    else if (value > 100)
        batteryLevel = 100;
    else
        batteryLevel = value;
}

std::string WirelessSecurityCamera::getWifiSSID() const
{
    return wifiSSID;
}

void WirelessSecurityCamera::setWifiSSID(const std::string &ssid)
{
    wifiSSID = ssid;
}

std::string WirelessSecurityCamera::getType() const
{
    return "WirelessSecurityCamera";
}
