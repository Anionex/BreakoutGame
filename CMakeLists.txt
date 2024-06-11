cmake_minimum_required(VERSION 3.10)
project(BreakoutGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(SFML_DIR "${VCPKG_ROOT}/packages/CSFML/share/sfml")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(BreakoutGame ${SOURCES})

target_link_libraries(BreakoutGame sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
