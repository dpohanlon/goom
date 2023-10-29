cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)
# include(example_auto_set_url.cmake)

project(goom)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

if (TARGET tinyusb_device)
    add_executable(goom
            goom.c
            )

    # pull in common dependencies
    target_link_libraries(goom
                          pico_stdlib
                          hardware_pwm)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(goom 1)
    pico_enable_stdio_uart(goom 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(goom)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building pico_water because TinyUSB submodule is not initialized in the SDK")
endif()
