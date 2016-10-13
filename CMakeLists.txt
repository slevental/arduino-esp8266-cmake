cmake_minimum_required(VERSION 3.5)
project(http_demo)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME http-demo)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH src/main.cpp)
set(${CMAKE_PROJECT_NAME}_BOARD mega)
set(${CMAKE_PROJECT_NAME}_PORT /dev/tty.wchusbserial1420)
set(LIBRARIES_DIR libs)

set(mega.build.mcu atmega2560)
set(mega.upload.protocol wiring)
set(mega.upload.speed 115200)

set(
        LIBRARIES
        esp8266
)

foreach (LIBRARY ${LIBRARIES})
    add_subdirectory("${LIBRARIES_DIR}/${LIBRARY}")
endforeach (LIBRARY)

generate_arduino_firmware(
        ${CMAKE_PROJECT_NAME}
        LIBS ${LIBRARIES}
)
