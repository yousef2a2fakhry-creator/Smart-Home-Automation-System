#include "../inc/WiredSecurityCamera.h"

WiredSecurityCamera::WiredSecurityCamera(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    const std::string &cableType,
    bool nightVision,
    bool recording)
    : SecurityCamera(deviceID, vendor, countryOfManufacture, year, nightVision, recording), cableType(cableType) {}

std::string WiredSecurityCamera::getCableType() const
{
    return cableType;
}

std::string WiredSecurityCamera::getType() const
{
    return "WiredSecurityCamera";
}
