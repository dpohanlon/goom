cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from GIT
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
include(pico_sdk_import.cmake)

project(goom C CXX ASM)

pico_sdk_init()

set(FAMILY rp2040)
set(BOARD pico_sdk)
set(TINYUSB_FAMILY_PROJECT_NAME_PREFIX "tinyusb_dev_")

# Initialize the executable without specifying sources here
add_executable(goom)

# Add all source files
target_sources(goom PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src/goom.c
        ${CMAKE_CURRENT_LIST_DIR}/src/usb_descriptors.c)

# Include directory for header files
target_include_directories(goom PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src)

# Link libraries
target_link_libraries(goom PUBLIC pico_stdlib pico_unique_id tinyusb_device tinyusb_board hardware_pwm)

# Generate extra outputs (map/bin/hex/uf2)
pico_add_extra_outputs(goom)
