#
# Copyright (c) 2022 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

add_subdirectory(bt_management)
add_subdirectory(bt_rendering_and_capture) #Amit
add_subdirectory(bt_content_control)  #Amit
add_subdirectory(bt_stream)  #Amit

zephyr_library_include_directories(
    bt_management
    bt_rendering_and_capture
    bt_content_control
    bt_stream
)
