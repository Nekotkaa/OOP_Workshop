cmake_minimum_required(VERSION 3.22)
project(Workshop1)

set(CMAKE_CXX_STANDARD 17)

# Główny program
add_executable(Workshop1 main.cpp Container.h Container.cpp)

# Konfiguracja testów jednostkowych (Boost.Test)
enable_testing()

find_package(Boost 1.71.0 CONFIGS COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_CONTAINER_FILES
        test/master.cpp
        test/ContainerTest.cpp
        Container.h
        Container.cpp
)

add_executable(ContainerTester ${SOURCE_TEST_CONTAINER_FILES})

target_link_libraries(ContainerTester
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(TestContainer ContainerTester
        --report_level=detailed
        --log_level=all
        --color_output=yes
)