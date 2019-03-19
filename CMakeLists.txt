cmake_minimum_required(VERSION 3.13)

project(launcheroo CXX)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC ")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address ")

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)
set(CMAKE_AUTOMOC ON)


add_subdirectory(cpp)

