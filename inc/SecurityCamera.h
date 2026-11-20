#ifndef SECURITY_CAMERA_H
#define SECURITY_CAMERA_H

#include <string>
#include "SmartDevice.h"
#include "DoorLockObserver.h"
class SecurityCamera : public SmartDevice , DoorLockObserver
{
private:
    bool nightVision;
    bool recording = false;

    bool armed = false;

protected:
    void sendAlert(const std::string &message) const;

public:
// The initial night-vision state is false.
SecurityCamera(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    bool nightVision = false,
    bool recording = false
);
    void startRecording();
    void stopRecording();
    void turnNightVisionON();
    void turnNightVisionOFF();
    bool isNightVision() const;
    bool isRecording() const;

    void armSystem();
    void disarmSystem();
    bool isArmed() const;

    void update(const DoorLock &doorLock) override;
    void setSubscribeID(std::string id) override;

    ~SecurityCamera() noexcept override = default;
};
#endif