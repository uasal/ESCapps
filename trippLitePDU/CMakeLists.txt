cmake_minimum_required(VERSION 3.10)

project(trippLitePDU VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(XWCTK REQUIRED)

if(NOT XWCTK_FOUND)
    message(FATAL_ERROR "Package XWCTK not found. Please install it.")
endif()

add_executable(trippLitePDU trippLitePDU.cpp)

target_compile_options(trippLitePDU PRIVATE -Wall -g)

# To compile as simulator
target_compile_options(trippLitePDU PRIVATE -DXWC_SIM_MODE)

target_link_libraries(trippLitePDU PRIVATE
                                    XWCTK::XWCTKall
                                    ${FLATBUFFERSLIB}
                                    # (optional) uncomment is using custom telemetry types
                                    )

install(TARGETS trippLitePDU DESTINATION bin)
