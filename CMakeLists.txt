cmake_minimum_required(VERSION 3.10)

project(raybt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    bullet
    GIT_REPOSITORY https://github.com/bulletphysics/bullet3.git
    GIT_TAG 3.25
)

FetchContent_MakeAvailable(bullet)

include_directories(
    src/include
    build/_deps/bullet-src/src
    build/_deps/bullet-src/src/BulletCollision
    build/_deps/bullet-src/src/BulletDynamics
    build/_deps/bullet-src/src/LinearMath
    build/_deps/raylib-build/raylib/include
)

add_executable(
    app
    src/main.cpp
    src/player.cpp
    src/alea.cpp
    src/geometry3.cpp
    src/world.cpp
)

target_link_libraries(app PRIVATE raylib)
target_link_libraries(app PRIVATE BulletDynamics BulletCollision LinearMath)