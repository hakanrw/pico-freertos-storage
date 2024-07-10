cmake_minimum_required(VERSION 3.13)

project(picofs_project C CXX ASM)

set(PICO_BOARD pico_w)
set(FAMILY rp2040)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#pico_sdk_init()

add_library(picofs
  flash.c
  ${PICO_SDK_PATH}/lib/tinyusb/lib/fatfs/source/ff.c
  ${PICO_SDK_PATH}/lib/tinyusb/lib/fatfs/source/ffsystem.c
  ${PICO_SDK_PATH}/lib/tinyusb/lib/fatfs/source/ffunicode.c
  fatfs_driver.c
  usb_msc_driver.c
  usb_descriptors.c
)

target_include_directories(picofs
  PUBLIC
  ${PICO_SDK_PATH}/lib/tinyusb/lib/fatfs/source
  ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(picofs
  PRIVATE
  pico_stdlib
  pico_flash
  tinyusb_device
  hardware_flash
  hardware_exception
)

#pico_enable_stdio_usb(picofs 1)
#pico_add_extra_outputs(picofs)
