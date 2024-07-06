cmake_minimum_required(VERSION 3.13)

# initialize the SDK directly
set(PICO_BOARD pico_w)
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(freertos)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(lib/littlefs)

add_executable(freertos src/main.c)

target_include_directories(freertos PUBLIC .)

target_link_libraries(freertos pico_stdlib FreeRTOS-Kernel-Heap4)
target_link_libraries(freertos littlefs)

pico_add_extra_outputs(freertos)
pico_enable_stdio_usb(freertos 1)
