cmake_minimum_required(VERSION 3.10)

project(fsmCtrl VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(XWCTK REQUIRED)

set(CMAKE_VERBOSE_MAKEFILE ON)

if(NOT XWCTK_FOUND)
    message(FATAL_ERROR "Package XWCTK not found. Please install it.")
endif()

set(LIB_PATH "${PREFIX}/${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Path to the library directory")
find_library(FLATBUFFERSLIB "libflatbuffers.a" PATHS ${LIB_PATH} REQUIRED)
if (NOT FLATBUFFERSLIB)
    message(FATAL_ERROR "libflatbuffers.a not found at location ${LIB_PATH}. Please install it here.")
endif()

add_executable(fsmCtrl fsmCtrl.cpp)

target_compile_options(fsmCtrl PRIVATE -Wall -g)

target_link_libraries(fsmCtrl PRIVATE
                                XWCTK::XWCTKall
                                ${FLATBUFFERSLIB}
                                # (optional) uncomment is using custom telemetry types
                                )

install(TARGETS fsmCtrl 
        DESTINATION bin
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                    GROUP_READ GROUP_EXECUTE
                    WORLD_READ WORLD_EXECUTE
                    SETUID
        )