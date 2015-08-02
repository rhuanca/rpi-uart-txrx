cmake_minimum_required(VERSION 3.2)
project(hello_world)

SET(ARM_TOOL_CHAIN /home/rhuanca/dev/rpi/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64)
SET(CMAKE_SYSTEM_NAME Linux)

# set(CMAKE_FIND_ROOT_PATH ${ARM_TOOL_CHAIN})
# set(tools ${ARM_TOOL_CHAIN})
set(CMAKE_C_COMPILER ${ARM_TOOL_CHAIN}/bin/arm-linux-gnueabihf-gcc)

set(SOURCE_FILES main.c)

add_executable(hello_world ${SOURCE_FILES})