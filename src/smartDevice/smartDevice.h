#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <device.h>

// Topics learned/revised:
// Inheritance
// Virtual function override

class SmartDevice : public Device
{
public:
    SmartDevice(float model,
        TypeOfDevice deviceType,
        std::string  osName);

    ~SmartDevice() override;

    // Override base class virtual function
    void printInfo() const override;

    std::string getOsName() const { return osName; }

private:
    std::string osName;
};