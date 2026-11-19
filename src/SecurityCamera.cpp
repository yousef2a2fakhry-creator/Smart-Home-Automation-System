#include "../inc/SecurityCamera.h"

SecurityCamera::SecurityCamera(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    bool nightVision,
    bool recording)
    : SmartDevice(deviceID, vendor, countryOfManufacture, year), nightVision(nightVision), recording(recording) {}

void SecurityCamera::startRecording()
{
    recording = true;
}
void SecurityCamera::stopRecording()
{
    recording = false;
}
void SecurityCamera::turnNightVisionON()
{
    nightVision = true;
}
void SecurityCamera::turnNightVisionOFF()
{
    nightVision = false;
}
bool SecurityCamera::isNightVision() const
{
    return nightVision;
}
bool SecurityCamera::isRecording() const
{
    return recording;
}
