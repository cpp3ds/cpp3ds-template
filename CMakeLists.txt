cmake_minimum_required(VERSION 2.8)

# Project name without spaces or special characters
project("cpp3ds-template")

set(APP_TITLE "cpp3ds Template")
set(APP_DESCRIPTION "Basic cpp3ds template project")
set(APP_AUTHOR "Cruel")
set(APP_ICON ${PROJECT_SOURCE_DIR}/res/app/icon.png)

# CIA settings
set(APP_UNIQUE_ID 0xfffff) # This must be unique for your CIA project
set(APP_PRODUCT_CODE ${PROJECT_NAME})
set(BANNER_IMAGE ${PROJECT_SOURCE_DIR}/res/app/banner.png)
set(BANNER_SOUND ${PROJECT_SOURCE_DIR}/res/app/banner.wav)
set(CIA_CONFIG ${PROJECT_SOURCE_DIR}/res/app/cia.rsf)

# Include cpp3ds cmake module
set(CPP3DS $ENV{CPP3DS})
if(NOT CPP3DS)
	message(FATAL_ERROR "You need to set the env variable CPP3DS before compiling.")
endif()
set(CMAKE_MODULE_PATH "${CPP3DS}/cmake" ${CMAKE_MODULE_PATH})
include(cpp3ds)

# Use either nihstro or picasso for your shader scripts
set(SHADER_AS nihstro)

# You may prefer not to use GLOB and instead define each file explicitly.
# See: http://stackoverflow.com/questions/1027247/best-way-to-specify-sourcefiles-in-cmake
# Variables used by template: SOURCE_FILES & SHADER_FILES
set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)
FILE(GLOB_RECURSE SHADER_FILES ${PROJECT_SOURCE_DIR}/res/romfs/shaders/[^.]*.vsh)

##################################################
# Don't usually need to change anything below
##################################################
set(CPP3DS_ARM_FLAGS "-g -O2 -fno-rtti -fno-exceptions -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft")
set(CPP3DS_EMU_FLAGS "-g -O0")

set(CPP3DS_ARM_LIBS cpp3ds-window cpp3ds-graphics cpp3ds-audio cpp3ds-system gl3ds ctru freetype png z vorbisenc vorbisfile vorbis ogg)
set(CPP3DS_EMU_LIBS cpp3ds-emu sfml-graphics sfml-window sfml-system sfml-audio openal GLEW GL jpeg freetype vorbisenc vorbisfile vorbis ogg)

add_subdirectory(${CPP3DS}/cmake/template_arm build/arm)
add_subdirectory(${CPP3DS}/cmake/template_emu build/emu)
