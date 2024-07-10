cmake_minimum_required(VERSION 3.13)

# initialize the SDK directly
set(PICO_BOARD pico_w)
set(FAMILY rp2040)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

pico_sdk_init()

project(freertos)

# initialize the Raspberry Pi Pico SDK

add_subdirectory(lib/pico-usb-flash-drive)

add_executable(freertos src/main.c src/hooks.c)

target_include_directories(freertos PUBLIC .)

target_link_libraries(freertos
  picofs
  pico_stdlib
  pico_cyw43_arch_none
  FreeRTOS-Kernel-Heap4
  tinyusb_additions
  tinyusb_board
  tinyusb_device
  hardware_flash
  hardware_sync
)

target_compile_definitions(freertos PRIVATE
        PICO_STDIO_STACK_BUFFER_SIZE=64 # use a small printf on stack buffer
)

pico_enable_stdio_usb(freertos 1)
pico_enable_stdio_uart(freertos 0)

pico_add_extra_outputs(freertos)
