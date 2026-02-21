#include <iostream>
#include <map>
#include <limits>
#include <fstream>
#include <filesystem>

#include "algorithm_start\algorithm_start.hpp"

int main(){
    unsigned long long int number = 0;
    std::vector<unsigned long long int> results_history;

    std::cout << "************************************************\n";
    std::cout << "https://github.com/SG123it/Collatz_hypothesis\n";
    std::cout << "Version: ";

    #ifdef PROGRAM_VERSION
        std::cout << PROGRAM_VERSION;
    #else
        std::cout << "UNKNOWN";
    #endif

    std::cout << "\n************************************************\n\n\n";

    while (true) {
        #if defined(_WIN32) || defined(_WIN64)
            std::system("cls");
        #endif

        try { //Если в ходе выполнения 2 функций ниже возникнет ошибка то программа перезапускается по нажатию клавиши

        }
        catch(...) {
            std::cout << "Unknown error. Please press enter to restart";
            std::cin.ignore();
            std::cin.get();
        }

        break;

    }

    
    char action = ' ';
    while (true) {
        std::cout << "\n\nProgram finished successful! Do you want to save results history to file?\n[1] - YES\n[2] - NO\n";
        std::cout << ">>> ";
        std::cin >> action;
        if(std::cin.fail()) continue;
        break;
    }

    //если action == '2' программа просто переходит в конец и выводит текст 'Thank you for using my program :)'
    if (action == '1') {

        std::fstream file("CH_results_history.txt", std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            std::cout << "Unable to open CH_results_history.txt";
            return 1; //выход из программы
        }
            

        file << "written number: " << number << std::endl;
        for (unsigned long long int el : results_history) {
            file << el << std::endl;
        }

        file.close();
        std::cout << "File was saved to " << std::filesystem::absolute("./CH_results_history.txt").string();
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
