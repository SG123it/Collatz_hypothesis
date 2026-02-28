#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <console_ui.hpp>

#include "algorithm_start.hpp"

std::vector<unsigned long long int> algorithm_start::get_numbers() {
    std::vector<unsigned long long int> result;

    console_UI::window_settings get_numbers_UI;
    if (search_mode == SEARCH_MODE::default_mode) get_numbers_UI.title = "Default mode";
    else if (search_mode == SEARCH_MODE::enumeration_mode) get_numbers_UI.title = "Enumeration mode";

    get_numbers_UI.text = "Please enter the number or numbers(natural)\nTemplate: 10\nTemplate: 10 20 30 40\n\n";
    if (search_mode == SEARCH_MODE::enumeration_mode) get_numbers_UI.text += "if you write numbers that not multiples of two program ignored number!";
    
    std::string input_string = console_UI::window_print(get_numbers_UI, true);
    if (input_string.empty()) {
        std::cerr << "Error: input_string is empty.\n";
        throw "Error: input_string is empty.";
    }
    
    if (input_string[input_string.size() - 1] != ' ') input_string.append(" "); //Для коррректной работы программы
    if (input_string[0] == ' ' || input_string[0] == '\n') input_string.erase(0,1); //2 условие нужно для предотвращение пропуска ввода


    std::vector<std::string> raw_result; // запись строк без лишнего в вектор для последующей проверки
    do {

        raw_result.push_back(input_string.substr(0, input_string.find(" ")));
        input_string = input_string.substr(input_string.find(" ") + 1, input_string.size() - 1);

    }
    while (input_string.find(" ") != std::string::npos);

    if (search_mode == SEARCH_MODE::enumeration_mode && (raw_result.size()) % 2 == 1) raw_result.pop_back(); //если размер массива не кратен 2 
    if (raw_result.empty()) {
        
        std::cerr << "Error: Result is empty.\n";
        throw "Error: Result is empty.";
        
    }

    //----------------------

    for (std::string el : raw_result) {
        if (!el.empty()) result.push_back(std::stoull(el)); //если вылезет исключение main.cpp его поймает
    }

    if (search_mode == SEARCH_MODE::enumeration_mode) {
        const std::vector<unsigned long long int> vector_copy = result;
        result.clear(); //Перезапись вектора

        for (int i = 0; i < vector_copy.size(); i += 2){ //+= 2 потому что включён enumeration_mode и там елементов кратно двум
            for (int si = vector_copy[i]; si <= vector_copy[i + 1]; si++) {
                result.push_back(si);
            }
        }
    }

    return result;

}