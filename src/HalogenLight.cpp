#include "../inc/HalogenLight.h"
HalogenLight::HalogenLight(
    const std::string &deviceID,
    const std::string &vendor,
    const std::string &countryOfManufacture,
    int year,
    int brightness,
    bool status)
    : Light(deviceID, vendor, countryOfManufacture, year, brightness, status) {}
void HalogenLight::turnON()
{
    // it has preserved value for the brightness when turning ON the light
    status = true;    
}
void HalogenLight::turnOFF()
{
    // preserving the brightness value when turning OFF the light
    status = false;    
}
std::string HalogenLight::getType() const
{
    return "Halogen Light";
}
