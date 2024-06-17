cmake_minimum_required(VERSION 3.0)

project(LoadLibraryRuntime)


set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(Lib)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Lib
)