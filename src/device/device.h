#pragma once

#include <iostream>
#include <string>
#include <memory>

// Scoped enum — values must be accessed as, TypeOfDevice::Mobile not just Mobile (Note : to avoid name clashes)

enum class TypeOfDevice
{
    Mobile,
    Laptop,
    TV
};
// Topics learnt/revised:
// Class design
// Initializer list construction
// const correctness on getters
// Virtual destructor
// Rule of five (copy, move, destructor)

class Device
{
public:
    // Constructor using initializer list
    Device(float model, TypeOfDevice deviceType);

    // Virtual destructor: safe for polymorphism
    virtual ~Device();

    // Copy constructor:for deep copy
    Device(const Device& other);

    // Copy assignment operator
    Device& operator=(const Device& other);

    // Move constructor (C++11)
    Device(Device&& other) noexcept;

    // Move assignment operator (C++11)
    Device& operator=(Device&& other) noexcept;

    // Getters — const correct
    float          getModel()      const { return model; }
    TypeOfDevice   getDeviceType() const { return deviceType; }
    std::string    getTypeAsString() const;

    // Display info
    virtual void printInfo() const;

private:
    float        model;
    TypeOfDevice deviceType;
};