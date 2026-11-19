#ifndef SECURITY_CAMERA_H
#define SECURITY_CAMERA_H

#include <string>
#include "SmartDevice.h"

class SecurityCamera : public SmartDevice
{
private:
    bool nightVision;
    bool recording = false;

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

        
    ~SecurityCamera() noexcept override = default;
};
#endif