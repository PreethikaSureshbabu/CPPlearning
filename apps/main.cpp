#include <iostream>
#include <memory>
#include <vector>
#include "device.h"
#include "smartDevice.h"


void displayDevice(const Device& device)
{
    device.printInfo();
    std::cout << '\n';
}

int main()
{


    // 1. Stack allocated objects
    // Created when declared, destroyed when scope ends
    // No manual cleanup needed
    std::cout << " 1. Stack Allocated "<<std::endl;
    {
        Device laptop(15.6f, TypeOfDevice::Laptop);
        laptop.printInfo();
        std::cout << '\n';
    }  // laptop destroyed automatically here

    // 2. Heap allocated — raw pointer (C++03 way)
    // Manual new/delete — avoid in modern C++
    // used here to understand what smart pointers replace
    std::cout << " 2. Heap: Raw Pointer (old way) "<<std::endl;
    {
        Device* rawDevice = new Device(
            17.3f, TypeOfDevice::Mobile);
        rawDevice->printInfo();
        delete rawDevice;  // must manually delete
        rawDevice = nullptr;
        std::cout << '\n';
    }

    // 3. Heap allocated — unique_ptr (C++11)
    // Single owner — automatically deleted when out of scope
    // Preferred over raw pointer in modern C++
    std::cout << " 3. Heap: unique_ptr (modern way) ";
    {
        auto uniqueDevice = std::make_unique<Device>(
            32.0f, TypeOfDevice::TV);
        uniqueDevice->printInfo();
        std::cout << '\n';
    }  // automatically deleted here — no delete needed

    //  4. Heap allocated — shared_ptr (C++11)
    // Multiple owners — deleted when last owner gone
    std::cout <<std::endl << " 4. Heap: shared_ptr \n";
    {
        auto shared1 = std::make_shared<Device>(
            13.3f, TypeOfDevice::Laptop);

        {
            auto shared2 = shared1;  // both own same object
            std::cout << "Owners: "
                << shared1.use_count() << '\n';
            shared2->printInfo();
        }  // shared2 gone — count drops to 1

        std::cout << "Owners after shared2 gone: "
            << shared1.use_count() << '\n';
        std::cout << '\n';
    }  // shared1 gone : count = 0, device deleted

    // 5. Copy constructor and assignment 
    std::cout << std::endl << " 5. Copy Semantics \n";
    {
        Device original(10.5f, TypeOfDevice::Mobile);
        Device copied = original;      // copy constructor
        Device assigned(5.0f, TypeOfDevice::TV);
        assigned = original;           // copy assignment
        std::cout << '\n';
    }

    // 6. Move semantics (C++11)
    std::cout << std::endl << " 6. Move Semantics \n";
    {
        Device source(8.0f, TypeOfDevice::Laptop);
        Device moved = std::move(source); // move constructor
        moved.printInfo();
        std::cout << '\n';
    }

    //  7. Inheritance and polymorphism
    // Base pointer pointing to derived object
    // Virtual function called via vtable
    std::cout << std::endl << "7. Inheritance + Polymorphism \n";
    {
        // Base pointer → derived object
        std::unique_ptr<Device> smartPhone =
            std::make_unique<SmartDevice>(
                6.7f,
                TypeOfDevice::Mobile,
                "Android 14");

        // Calls SmartDevice::printInfo() via vtable
        smartPhone->printInfo();
        std::cout << '\n';
    }

    // 8. Polymorphic container
    // Vector of base pointers holding mixed derived objects
    // Classic use of vtable dispatch
    std::cout << std::endl << " 8. Polymorphic Container \n";
    {
        std::vector<std::unique_ptr<Device>> devices;

        devices.push_back(
            std::make_unique<Device>(
                15.6f, TypeOfDevice::Laptop));

        devices.push_back(
            std::make_unique<SmartDevice>(
                6.1f,
                TypeOfDevice::Mobile,
                "iOS 18"));

        devices.push_back(
            std::make_unique<SmartDevice>(
                55.0f,
                TypeOfDevice::TV,
                "WebOS"));

        std::cout << "All devices:\n";
        for (const auto& device : devices)
        {
            device->printInfo();  // vtable picks right one
            std::cout << "\n";
        }
    }

    //  9. Pass by reference 
    std::cout << std::endl << " 9. Pass by Reference \n";
    {
        Device tv(55.0f, TypeOfDevice::TV);
        displayDevice(tv);  // no copy made
    }

    return 0;
}