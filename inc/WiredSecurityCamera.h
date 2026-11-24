#ifndef WIRED_SECURITY_CAMERA_H
#define WIRED_SECURITY_CAMERA_H

#include <string>
#include "SecurityCamera.h"

class WiredSecurityCamera : public SecurityCamera
{
private:
    std::string cableType;

public:
    WiredSecurityCamera(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        const std::string &cableType = "Ethernet/PoE",
        bool nightVision = false,
        bool recording = false);

    std::string getCableType() const;
    DeviceTypes getType() const override;

    ~WiredSecurityCamera() noexcept override = default;
};

#endif