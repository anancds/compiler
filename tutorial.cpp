// A simple program that computes the square root of a number
#include <cstdio>
#include <cstdlib>
//#include <math.h>
#include "TutorialConfig.h"
#include "mysqrt.h"
#include <string>
#include <iostream>

int main (int argc, char *argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;

        const double inputValue = std::stod(argv[1]);

        return 1;
    }
}

