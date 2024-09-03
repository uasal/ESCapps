cmake_minimum_required(VERSION 3.10)

project(ESCapps VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(XWCTK REQUIRED)

if(NOT XWCTK_FOUND)
    message(FATAL_ERROR "Package XWCTK not found. Please install it.")
endif()

add_subdirectory(logger)
add_subdirectory(fsmCtrl)
add_subdirectory(trippLitePDU)

# Define installation of generated headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/logger/generated
        DESTINATION include/${PROJECT_NAME}/logger
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.inc"
)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/logger/types/generated
        DESTINATION include/${PROJECT_NAME}/logger/types
        FILES_MATCHING PATTERN "*.h"
)