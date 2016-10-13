set(PROJECT_NAME esp8266)
set(LIBRARY_NAME ${PROJECT_NAME})
set(LIBRARY_HEADERS_DIR include/${LIBRARY_NAME})
set(LIBRARY_SOURCE_DIR src)

set(
        LIBRARY_HEADERS
        ${LIBRARY_HEADERS_DIR}/ESP8266wifi.h
)

set(
        LIBRARY_SOURCE
        ${LIBRARY_SOURCE_DIR}/ESP8266wifi.cpp
)

project(${PROJECT_NAME})

generate_arduino_library(
        ${PROJECT_NAME}
        SRCS ${LIBRARY_SOURCE}
        HDRS ${LIBRARY_HEADERS}
        BOARD mega)

target_include_directories(
        ${LIBRARY_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
        $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(
        ${LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
