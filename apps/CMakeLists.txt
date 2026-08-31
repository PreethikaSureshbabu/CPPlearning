# Create executable
add_executable(CppLearningApp
    main.cpp
)

# Link against our Device library
target_link_libraries(CppLearningApp PRIVATE
   DeviceLib
   SmartDeviceLib
)