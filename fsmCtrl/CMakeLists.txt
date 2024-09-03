cmake_minimum_required(VERSION 3.10)

project(fsmCtrl VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(XWCTK REQUIRED)

if(NOT XWCTK_FOUND)
    message(FATAL_ERROR "Package XWCTK not found. Please install it.")
endif()

add_executable(fsmCtrl fsmCtrl.cpp)

target_compile_options(fsmCtrl PRIVATE -Wall -g)

target_link_libraries(fsmCtrl PRIVATE
                                XWCTK::XWCTKall
                                # (optional) uncomment is using custom telemetry types
                                $<TARGET_OBJECTS:ESClogs> 
                                )

add_dependencies(fsmCtrl generated_logTypes)

target_include_directories(fsmCtrl PRIVATE ../logger)

install(TARGETS fsmCtrl DESTINATION bin)