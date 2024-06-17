project(Lib)

set(SOURCES src/Implement.cpp)

add_library(${PROJECT_NAME} MODULE ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE DEFINE_LIB)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out
)
