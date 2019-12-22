// A simple program that computes the square root of a number
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "TutorialConfig.h"
#include "mysqrt.h"
#include <string>
#include <iostream>

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;


        return 1;
    }

    const double inputValue = std::stod(argv[1]);
#ifdef USE_MYMATH
    const double outputValue = mysqrt(inputValue);
        std::cout << outputValue << std::endl;
#else
    const double outputValue = sqrt(inputValue);
#endif
}

