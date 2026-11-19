#ifndef WIRED_SECURITY_CAMERA_H
#define WIRED_SECURITY_CAMERA_H

#include <string>
#include "SecurityCamera.h"

class WiredSecurityCamera : public SecurityCamera
{
private:
    std::string cableType;
    bool continuousPower;

public:
    WiredSecurityCamera(
        const std::string &deviceID,
        const std::string &vendor,
        const std::string &countryOfManufacture,
        int year,
        const std::string &cableType = "Ethernet/PoE",
        bool continuousPower = true);

    std::string getCableType() const;
    bool hasContinuousPower() const;
    std::string getType() const override;

    ~WiredSecurityCamera() noexcept override = default;
};

#endif