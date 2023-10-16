#--------------------------------------------------------------------
# Zephyr Example Application
#
# Copyright (c) 2021 Nordic Semiconductor ASA
# Copyright (c) 2023 Toost Solutions

# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

# Re-direct the directory where the 'boards' directory is found from
# $ZEPHYR_BASE to the root of this repo
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

# Set myboard as default board to compile for
set(BOARD myboard)

# Suppress SPI DTC warnings
list(APPEND EXTRA_DTC_FLAGS "-Wno-spi_bus_bridge")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Get the latest git tag without 'v' prefix
execute_process(
  COMMAND bash -c "../tools/get_latest_version.sh | sed 's/^v//'"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE APP_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Set a default value for APP_VERSION if it's not obtained from git tags
if(NOT APP_VERSION)
  set(APP_VERSION "0.0.0")
endif()

message("-- App version: ${APP_VERSION}")

# Here the firmware version is defined. This ends up in app_version.hpp after a build
project(app VERSION ${APP_VERSION})

configure_file(app_version.h.in ${CMAKE_BINARY_DIR}/app/include/app_version.h)
target_include_directories(app PRIVATE ${CMAKE_BINARY_DIR}/app/include src)

# Get all files in app directory
file( GLOB_RECURSE
  APP_SOURCES
  RELATIVE
  ${CMAKE_CURRENT_LIST_DIR}
  src/*.c*
)

target_sources(app PRIVATE ${APP_SOURCES})
