#include <iostream>
#include <map>
#include <limits>
#include <fstream>
#include <filesystem>
#include <console_ui.hpp>

#include "algorithm_start\algorithm_start.hpp"
#include "arguments.hpp"

int main(int argc, char* argv[]){
    algorithm_start::all_program_return all_return_info; //Хранит информацию о возврате
    algorithm_start start; //Хранит настройки для запуска а также функции
    std::vector<unsigned long long> numbers;
    
    arguments(argc, argv, start);
    //--------------------------
    console_UI::window_settings programinfo_UI;
    programinfo_UI.title = "Program info";
    programinfo_UI.text = "https://github.com/SG123it/Collatz_hypothesis\n";
    #ifdef PROGRAM_VERSION
        programinfo_UI.text += "Version: " + std::to_string(PROGRAM_VERSION) + "\n";
    #endif
    programinfo_UI.text += "Search_mode = " + std::to_string(start.search_mode) + "\n";
    programinfo_UI.text += "Cycles_limit = " + std::to_string(start.cycles_limit) + "\n";
    if (argc > 1) programinfo_UI.text += "ARGV: ";
    for (int i = 1; i < argc; i++) programinfo_UI.text += std::string(argv[i]) + " ";

    console_UI::window_print(programinfo_UI);
    //--------------------------

    while (true) {

        try { //Если в ходе выполнения функции ниже возникнет ошибка то программа перезапускается по нажатию клавиши

            numbers = start.get_numbers();

            all_return_info = start.launch(&numbers);

        }
        catch(...) {
            std::cerr << "Unknown error. Please press enter to restart\n";
            std::cin.ignore();
        }

        if (numbers.size() != all_return_info.all_results.size() || all_return_info.all_results.size() != all_return_info.all_cycles.size()) {
            std::cerr << "Error: numbers.size() != all_results.size()\nPlease press enter to restart\n";
            std::cin.ignore();
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

    console_UI::window_settings Finish_text("Creator: https://github.com/SG123it", "Thank you for using my program :)");
    console_UI::window_print(Finish_text);

    std::cout << "\nPress enter to exit";
    std::cin.ignore();
    return 0;

}
