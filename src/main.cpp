#include <iostream>
#include <map>
#include <limits>
#include <fstream>
#include <filesystem>
#include <console_ui.hpp>

#include "algorithm_start\algorithm_start.hpp"
#include "arguments.hpp"

int main(int argc, char* argv[]){
    algorithm_start::all_program_return return_info; //Хранит информацию о возврате
    algorithm_start start; //Хранит настройки для запуска а также функции
    
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
        #if defined(_WIN32) || defined(_WIN64)
            std::system("cls");
        #endif


        try { //Если в ходе выполнения функции ниже возникнет ошибка то программа перезапускается по нажатию клавиши
            std::vector<unsigned long long> numbers;

            numbers = start.get_numbers();

            return_info = start.launch(numbers);

        }
        catch(...) {
            std::cerr << "Unknown error. Please press enter to restart\n";
            std::cin.ignore();
        }

        if (return_info.default_numbers.size() != return_info.all_results.size() || return_info.all_results.size() != return_info.all_cycles.size() || return_info.all_cycles.size() != return_info.default_numbers.size()) {
            std::cerr << "Error: the sizes of the arrays do not match\nPlease press enter to restart\n";
            std::cin.ignore();
        }
        break;
    }

    console_UI::window_settings Finish_text("Results");
    for (int i = 0; i < return_info.default_numbers.size(); i++) {
        Finish_text.text += "result[" + std::to_string(return_info.default_numbers[i]) + "] : " + std::to_string(return_info.all_results[i]) + " : " + "For " + std::to_string(return_info.all_cycles[i]) + " Cycles\n";
    }
    console_UI::window_print(Finish_text);

    std::cout << "\nPress enter to exit";
    std::cin.ignore();
    return 0;

}
