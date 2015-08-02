cmake_minimum_required(VERSION 3.2)
project(uart_rx_tx)

SET(ARM_TOOL_CHAIN /home/rhuanca/dev/rpi/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64)
SET(CMAKE_SYSTEM_NAME Linux)

# set(CMAKE_FIND_ROOT_PATH ${ARM_TOOL_CHAIN})
# set(tools ${ARM_TOOL_CHAIN})
set(CMAKE_C_COMPILER ${ARM_TOOL_CHAIN}/bin/arm-linux-gnueabihf-gcc)

set(TX_SOURCE_FILES rpi_uart_tx.c)
set(RX_SOURCE_FILES rpi_uart_rx.c)

add_executable(uart_tx ${TX_SOURCE_FILES})
add_executable(uart_rx ${RX_SOURCE_FILES})