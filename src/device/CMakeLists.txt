add_library(DeviceLib
    device.cpp
    device.h
)

target_include_directories(DeviceLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(DeviceLib PUBLIC
    cxx_std_17)