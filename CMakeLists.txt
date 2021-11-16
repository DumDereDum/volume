cmake_minimum_required(VERSION 2.8)

project(volume)

set(MAIN
    volume/main.cpp
    )

set(VOLUME
    volume/include/volume.hpp
    volume/src/volume.cpp
    )

set(VOLUME_SETTINGS
    volume/include/volume_settings.hpp
    volume/src/volume_settings_impl.cpp
    )

add_executable(main ${MAIN} ${VOLUME} ${VOLUME_SETTINGS})