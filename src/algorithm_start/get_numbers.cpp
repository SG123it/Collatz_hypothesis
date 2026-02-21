#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "algorithm_start.hpp"

std::vector<unsigned long long int> algorithm_start::get_numbers() {
    std::vector<unsigned long long int> result;

    if (search_mode == SEARCH_MODE::default_mode) {
        std::cout << R"(
                        ------------------
                        |  Default mode  |
            -----------------------------------------------
            | Please enter the number or numbers(natural) |
            | Template: 10"                               |
            | Template: 10 20 30                          |
            -----------------------------------------------
        )";
    }
    else if (search_mode == SEARCH_MODE::enumeration_mode) {
        std::cout << R"(
                        ----------------------
                        |  Enumeration mode  |
            -----------------------------------------------
            | Please enter the number or numbers(natural) |
            | Template: 10"                               |
            | Template: 10 20 30 40                       |
            -----------------------------------------------
    if you write numbers that not multiples of two program ignored number!
        )";
    }
    std::cout << "P.S. every your number must be no more than: " << std::numeric_limits<unsigned long long>::max() << "\nand no less than: " << std::numeric_limits<unsigned long long>::min();
    
    std::cout << ">>> ";
    std::cin.ignore();

    std::string input_string = "";
    std::getline(std::cin, input_string);

    if (input_string[input_string.size() - 1] != ' ') input_string.append(" "); //Для коррректной работы программы
    if (input_string[0] == ' ') input_string.erase(0,1);



    std::vector<std::string> raw_result; // запись строк без лишнего в вектор для последующей проверки
    while (input_string.find(" ") != std::string::npos) {

        raw_result.push_back(input_string.substr(0, input_string.find(" ")));
        input_string = input_string.substr(input_string.find(" ") + 1, input_string.size() - 1);

    }

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
            for (int si = vector_copy[i]; si < vector_copy[i + 1]; si++) {
                result.push_back(si);
            }
        }
    }

    return result;

}