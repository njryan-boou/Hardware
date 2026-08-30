cmake_minimum_required(VERSION 3.20)

project(hardwarey VERSION 0.0.0 LANGUAGES CXX)

option(HARDWAREY_BUILD_TESTS "Build hardwarey C++ tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PYBIND11_FINDPYTHON ON)
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

if(HARDWAREY_BUILD_TESTS)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
        GIT_SHALLOW TRUE
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(hardwarey_cpu_test
        tests/test_cpu.cpp
    )
    target_link_libraries(hardwarey_cpu_test
        PRIVATE
            hardwarey_core
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(hardwarey_cpu_test)
endif()
