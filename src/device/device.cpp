#include "device.h"

// Constructor — initializer list
// Note: members initialized in declaration order
// not in the order written in initializer list
Device::Device(float modelCreated, TypeOfDevice deviceTypeCreated)
    : model(modelCreated)           
    , deviceType(deviceTypeCreated) 
{
    std::cout << "Device Created: "
        << getTypeAsString()
        << " model " << model <<std::endl;
}

// Destructor: virtual so derived class destructor
// is called correctly when deleting via base pointer
Device::~Device()
{
    std::cout << "Device Destroyed: "
        << getTypeAsString()
        << " model: " << model << std::endl;
}

// Copy constructor: memberwise copy is fine here
// because we have no raw pointers (no deep copy needed)
Device::Device(const Device& other)
    : model(other.model)
    , deviceType(other.deviceType)
{
    std::cout << "Device Copy constructed"<< std::endl;
}

// Copy assignment operator
Device& Device::operator=(const Device& other)
{
    if (this != &other)  // self assignment check
    {
        model = other.model;
        deviceType = other.deviceType;
        std::cout << "Device Copy assigned" << std::endl;
    }
    return *this;  // return reference to self
}

// Move constructor (C++11)
// Takes ownership: no copy of data
Device::Device(Device&& other) noexcept
    : model(other.model)
    , deviceType(other.deviceType)
{
    // For primitive data type: just copy the value
    // For heap resources: we would steal the pointer
    
    other.model = 0.0f;
    std::cout << "Device Move constructed"<< std::endl;
}

// Move assignment operator (C++11)
Device& Device::operator=(Device&& other) noexcept
{
    if (this != &other)
    {
        model = other.model;
        deviceType = other.deviceType;
        other.model = 0.0f;
        std::cout << "Device Move assigned"<< std::endl;
    }
    return *this;
}

// Convert enum class to string for display
std::string Device::getTypeAsString() const
{
    switch (deviceType)
    {
    case TypeOfDevice::Mobile: return "Mobile";
    case TypeOfDevice::Laptop: return "Laptop";
    case TypeOfDevice::TV:     return "TV";
    default:                   return "Unknown";
    }
}

// Display device information
void Device::printInfo() const
{
    std::cout << "Device Info:\n"
        << "  Type  : " << getTypeAsString() << '\n'
        << "  Model : " << model << '\n';
}