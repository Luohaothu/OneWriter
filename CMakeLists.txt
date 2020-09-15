cmake_minimum_required(VERSION 3.0)

project(OneWriter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_DEFAULT_BUILD_TYPE Release)

file(GLOB SRCS "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${SRCS})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/external/tqdm.cpp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/fmt/include)
include_directories(${CMAKE_SOURCE_DIR}/external/spdlog/include)

install(TARGETS OneWriter
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)