cmake_minimum_required(VERSION 3.10)
project(LetsBuild)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME "build_it")

add_executable(${EXECUTABLE_NAME} main.cpp GroundDrawer.cpp GroundDrawer.hpp const.cpp const.hpp Player.cpp Player.hpp World.cpp World.hpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(Box2D REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
include_directories(${BOX2D_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${BOX2D_LIBRARIES})