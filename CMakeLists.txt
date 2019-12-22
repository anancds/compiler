# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.10)
project(compiler VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 配置一个头文件来传递一些CMake设置到源代码
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)


option(USE_MYMATH
        "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif ()

# 添加TutorialConfig.h的路径到头文件的搜索路径
add_executable(compiler main.cpp)
add_executable(tutorial tutorial.cpp)
target_include_directories(tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
        )
target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})