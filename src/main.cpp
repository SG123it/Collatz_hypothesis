#include <iostream>
#include <map>
#include <limits>
#include <fstream>
#include <filesystem>

#include "algorithm_start\algorithm_start.hpp"
#include "arguments.hpp"

int main(int argc, char* argv[]){
    algorithm_start::all_program_return all_return_info; //Хранит информацию о возврате
    algorithm_start start; //Хранит настройки для запуска а также функции
    std::vector<unsigned long long> numbers;

    arguments(argc, argv, start);
    //--------------------------

    std::cout << "************************************************\n";
    std::cout << "https://github.com/SG123it/Collatz_hypothesis\n";
    std::cout << "Version: ";
    #ifdef PROGRAM_VERSION
        std::cout << PROGRAM_VERSION << std::endl;
    #else
        std::cout << "UNKNOWN " << std::endl;
    #endif
    std::cout << "Search_mode = " << start.search_mode << std::endl;
    std::cout << "Cycles_limit = " << start.cycles_limit << std::endl;
    if (argc > 1) std::cout << "ARGV: ";
    for (int i = 1; i < argc; i++) std::cout << argv[i] << " ";
    std::cout << "\n************************************************\n\n\n";

    while (true) {

        try { //Если в ходе выполнения функции ниже возникнет ошибка то программа перезапускается по нажатию клавиши

            numbers = start.get_numbers();

            all_return_info = start.launch(&numbers);

        }
        catch(...) {
            std::cout << "Unknown error. Please press enter to restart\n";
            std::cin.ignore();
            std::cin.get();
        }

        if (numbers.size() != all_return_info.all_results.size() || all_return_info.all_results.size() != all_return_info.all_cycles.size()) {
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
        std::cout << "result[" << numbers[i] << "] : " << all_return_info.all_results[i] << " : " << "For " << all_return_info.all_cycles[i] << " Cycles" << std::endl;
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
