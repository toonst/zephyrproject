#-------------------------------------------------------------------------------
# Zephyr Example Application
#
# Copyright (c) 2021 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

# Re-direct the directory where the 'boards' directory is found from
# $ZEPHYR_BASE to the root of this repo
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

# Set myboard as default board to compile for
set(BOARD myboard)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app LANGUAGES C VERSION 1.0.0)

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
