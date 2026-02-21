#include <iostream>
#include <map>
#include <limits>
#include <fstream>
#include <filesystem>

#include "algorithm_start\algorithm_start.hpp"
#include "arguments.hpp"

int main(int argc, char* argv){
    std::vector<unsigned long long int> numbers;
    std::vector<unsigned long long int> all_results;
    algorithm_start start;

    std::cout << "************************************************\n";
    std::cout << "https://github.com/SG123it/Collatz_hypothesis\n";
    std::cout << "Version: ";
    #ifdef PROGRAM_VERSION
        std::cout << PROGRAM_VERSION << std::endl;
    #else
        std::cout << "UNKNOWN " << std::endl;
    #endif
    std::cout << "Search mode: " << start.search_mode << std::endl;
    std::cout << "Cycles limit: " << start.cycles_limit;

    std::cout << "\n************************************************\n\n\n";

    while (true) {

        try { //Если в ходе выполнения функции ниже возникнет ошибка то программа перезапускается по нажатию клавиши

            numbers = start.get_numbers();

            all_results = start.launch(&numbers);

        }
        catch(...) {
            std::cout << "Unknown error. Please press enter to restart\n";
            std::cin.ignore();
            std::cin.get();
        }

        if (numbers.size() != all_results.size()) {
            std::cout << "Error: numbers.size() != all_results.size()\nPlease press enter to restart\n";
            std::cin.ignore();
            std::cin.get();
        }

        #if defined(_WIN32) || defined(_WIN64)
            std::system("cls");
        #endif
        break;
    }

    std::cout << "\n************************************************\n";
    std::cout << "All results: \n\n";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "result[" << numbers[i] << "] : " << all_results[i] << std::endl;
    }

    std::cout << R"(
        -------------------------------------
        | Thank you for using my program :) |
        -------------------------------------
    )";
    std::cout << "\nPress enter to exit";
    std::cin.ignore();
    std::cin.get();
    return 0;

}
