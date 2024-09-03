# # Ensure flatlogcode executable exists
# find_program(FLATLOGCODES flatlogcodes)

# if(NOT FLATLOGCODES)
#     message(FATAL_ERROR "flatlogcodes executable not found")
# endif()

# # Find all .fbs files required by logTypes.hpp
# file(GLOB FBS_FILES "${CMAKE_SOURCE_DIR}/logger/types/schemas/*.fbs")

# add_custom_command(
#     OUTPUT ${CMAKE_SOURCE_DIR}/logger/generated/logTypes.hpp
#             ${CMAKE_SOURCE_DIR}/logger/generated/binarySchemata.inc
#     COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/logger/types/generated    
#     COMMAND ${CMAKE_COMMAND} -E echo "Executing flatlogcodes"    
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/logger
#     COMMAND ${FLATLOGCODES} --extra-guard "esc"
#     COMMAND ${CMAKE_COMMAND} -E echo "Generating header files"    
#     COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/logger/types/generated bash -c "for bfb in *.bfbs; do xxd -i \$bfb > \$(basename \$bfb).h; done"
#     COMMAND ${CMAKE_COMMAND} -E echo "Generatinc .inc file"
#     COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/logger/types/generated bash -c "find . -name '*.bfbs.h' -print0 | xargs -0 cat > ${CMAKE_SOURCE_DIR}/logger/generated/binarySchemata.inc"
#     DEPENDS ${CMAKE_SOURCE_DIR}/logger/logCodes.dat ${FBS_FILES}
#     COMMENT "Generating logger/generated/logTypes.hpp"
#     VERBATIM
# )

# Create a custom target for generating log types
add_custom_target(generated_logTypes DEPENDS ${CMAKE_SOURCE_DIR}/logger/generated/logTypes.hpp)

add_library(ESClogs types/telem.cpp)
target_link_libraries(ESClogs PRIVATE XWCTK::XWCTKall)
add_dependencies(ESClogs generated_logTypes)
