add_library(MathFunctions mysqrt.cpp mysqrt.h)
target_include_directories(MathFunctions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )