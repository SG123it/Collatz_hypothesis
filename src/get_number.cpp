#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "get_number.hpp"

unsigned long long int get_number() {
    unsigned long long int number = 0;

    std::cout << "\n|-----------------------------------|\n";
    std::cout << "\nPlease enter the number(natural) \n";
    std::cout << "\nTemplate: '10' - checking whether \nthe number 10 confirms the Collatz hypothesis.\n";
    std::cout << "\n|-----------------------------------|\n";
    std::cout << "P.S. your number must be no more than " << std::numeric_limits<unsigned long long>::max();

    while (true) {
        try {

            std::cout << "\n\n>>> ";
            std::cin >> number;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
        catch(...) {
            continue;
        }

        if (number <= 1) continue;
        break;


    }


    return number;
    
}