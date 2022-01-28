cmake_minimum_required(VERSION 3.17)
project(Stuffwaffe)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(COPY res/ DESTINATION res/)
set(ICON "${CMAKE_CURRENT_SOURCE_DIR}/res/icon.rc")

add_executable(${PROJECT_NAME}
    src/Offsets.hpp
    src/Math.hpp
    src/Logger.hpp
    src/Logger.cpp
    src/Memory.hpp
    src/Memory.cpp
    src/VAC.hpp
    src/VAC.cpp
    src/Player.hpp
    src/Player.cpp
    src/Client.hpp
    src/Client.cpp
    src/Bunnyhop.hpp
    src/Bunnyhop.cpp
    src/Noflash.hpp
    src/Noflash.cpp
    src/Skinchanger.hpp
    src/Skinchanger.cpp
    src/Glow.hpp
    src/Glow.cpp
    src/Stuffwaffe.hpp
    src/Stuffwaffe.cpp
    ${ICON}
)