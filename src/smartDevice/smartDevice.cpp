#include "smartDevice.h"
#include "device.h"
// ─────────────────────────────────────────────────────────
// SmartDevice — implementation
// ─────────────────────────────────────────────────────────

// Constructor: chains to base class constructor
SmartDevice::SmartDevice(float        modelCreated,
    TypeOfDevice deviceTypeCreated,
    std::string  osNameCreated)
    : Device(modelCreated, deviceTypeCreated)  // base constructor called
    , osName(std::move(osNameCreated)) // move string: avoid copy
{
    std::cout << "SmartDevice Created: OS: "
        << osName << std::endl;
}

SmartDevice::~SmartDevice()
{
    std::cout << "SmartDevice Destroyed: OS: "
        << osName << std::endl;
}

// Override: adds OS info to base output
void SmartDevice::printInfo() const
{
    Device::printInfo();  // call base version first
    std::cout << "  OS    : " << osName << std::endl;
}