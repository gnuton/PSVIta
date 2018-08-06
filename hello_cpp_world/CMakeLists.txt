cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type 
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is 
# highly recommended that you include this block for all projects.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

## Define project parameters here
# Name of the project
set(SHORT_NAME hello_cpp_world)
project(${SHORT_NAME})

# This line adds Vita helper macros, must go after project definition in order 
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "Hello World")
# Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X = 
# unique string of developer and Y = a unique number for this app
set(VITA_TITLEID  "VSDK00005")
# Optional version string to show in LiveArea's more info screen
set(VITA_VERSION  "01.00")
option(DEBUGNET "Enable debugnet for logging" ON)

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# Optional. You can specify more param.sfo flags this way.
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

# Add any additional include paths here
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/libs/gui/
)

# Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/src/libs/gui/
)

## Build and link
# Add all the files needed to compile here

FUNCTION(ADD_RESOURCES out_var)
  SET(result)
  FOREACH(in_f ${ARGN})
    SET(out_f "${CMAKE_CURRENT_BINARY_DIR}/${in_f}.o")
    GET_FILENAME_COMPONENT(out_dir ${out_f} DIRECTORY)
    ADD_CUSTOM_COMMAND(OUTPUT ${out_f}
      COMMAND ${CMAKE_COMMAND} -E make_directory ${out_dir}
      COMMAND ${CMAKE_LINKER} -r -b binary -o ${out_f} ${in_f}
      DEPENDS ${in_f}
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      COMMENT "Building resource ${out_f}"
      VERBATIM
      )
    LIST(APPEND result ${out_f})
  ENDFOREACH()
  SET(${out_var} "${result}" PARENT_SCOPE)
ENDFUNCTION()

file(GLOB_RECURSE res_files RELATIVE ${CMAKE_SOURCE_DIR} assets/*.png assets/*.jpeg assets/*.yml assets/*.ttf assets/*.wav assets/*.ogg)
add_resources(PROJECT_RESOURCES ${res_files})

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.hpp" "src/*.cpp" "src/*.c")
add_executable(${SHORT_NAME}
  ${PROJECT_RESOURCES}
  ${PROJECT_SOURCE_FILES}
)

if(DEBUGNET)
  add_definitions(-DDEBUGNET)
  target_link_libraries(${SHORT_NAME} debugnet)
  file(STRINGS "debugnetip.txt" DEBUGNETIP)
  add_definitions(-DDEBUGNETIP="${DEBUGNETIP}")
endif()

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(
    ${SHORT_NAME}
    vita2d
    SceDisplay_stub # Required by: vita2d
    SceGxm_stub # Required by: vita2d
    SceCommonDialog_stub # Required by: vita2d
    SceSysmodule_stub # Required by: vita2d
    SceTouch_stub
    SceCtrl_stub
    png
    jpeg
    z # required by png for crc32
)


vita_create_self(${SHORT_NAME}.self ${SHORT_NAME})
# The FILE directive lets you add additional files to the VPK, the syntax is
# FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
vita_create_vpk (${SHORT_NAME}.vpk ${VITA_TITLEID} ${SHORT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)

