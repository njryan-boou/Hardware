cmake_minimum_required(VERSION 3.20)

project(hardwarey VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(pybind11 CONFIG REQUIRED)

add_library(hardwarey_core STATIC
    src/cpu.cpp
)
target_include_directories(hardwarey_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
set_target_properties(hardwarey_core PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

pybind11_add_module(_core MODULE
    src/bindings.cpp
)
target_link_libraries(_core PRIVATE hardwarey_core)

install(TARGETS _core
    LIBRARY DESTINATION hardwarey
    RUNTIME DESTINATION hardwarey
)
