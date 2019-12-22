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
endif ()

# 添加TutorialConfig.h的路径到头文件的搜索路径
add_executable(compiler main.cpp)
add_executable(tutorial tutorial.cpp)
target_include_directories(tutorial PUBLIC
        "${PROJECT_BINARY_DIR}" }
        )
target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

install(TARGETS tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include
        )



enable_testing()

# does the application run
add_test(NAME Runs COMMAND tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND tutorial)
set_tests_properties(Usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
        )

# define a function to simplify adding tests
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result}
            )
endfunction(do_test)

# do a bunch of result based tests
do_test(tutorial 4 "4 is 2")
do_test(tutorial 9 "9 is 3")
do_test(tutorial 5 "5 is 2.236")
do_test(tutorial 7 "7 is 2.645")
do_test(tutorial 25 "25 is 5")
do_test(tutorial -25 "-25 is [-nan|nan|0]")
do_test(tutorial 0.0001 "0.0001 is 0.01")
