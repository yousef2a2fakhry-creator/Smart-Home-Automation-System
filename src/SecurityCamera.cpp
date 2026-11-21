#include "../inc/SecurityCamera.h"
#include "../inc/DoorLock.h"
#include <iostream>
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

void SecurityCamera::armSystem()
{
    armed = true;
}
void SecurityCamera::disarmSystem()
{
    armed = false;
}
bool SecurityCamera::isArmed() const
{
    return armed;
}

void SecurityCamera::setSubscribeID(std::string id)
{
    DoorLockObserver_id = id;
}

void SecurityCamera::update(const DoorLock &doorLock)
{
    if (armed && !doorLock.CheckLock())
    {
        if (!recording)
            startRecording();

        sendAlert("Security Alert: door lock " + doorLock.getDeviceID() +
                  " was unlocked while the system is armed. Camera " +
                  getDeviceID() + " started recording.");
    }
}

void SecurityCamera::sendAlert(const std::string &message) const
{
    std::cout << "[ALERT] " << message << std::endl;
}

void SecurityCamera::activate()
{
    armSystem();
}

void SecurityCamera::deactivate()
{
    disarmSystem();
}
