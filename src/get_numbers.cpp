#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "headers/get_numbers.hpp"

std::vector<unsigned long long int> get_numbers(SEARCH_MODE mode) {
    std::vector<unsigned long long int> result;

    std::cout << "\n|-----------------------------------|\n";
    if (mode == SEARCH_MODE::default_mode) {
        std::cout << "\nPlease enter the number(or numbers)\n";
        std::cout << "\nTemplate: '10'";
        std::cout << "\nTemplate: '10 20 30'";
    }
    else if (mode == SEARCH_MODE::enumeration_mode) {
        std::cout << "\nPlease enter the number or numbers multiples of two (enumeration_mode enable)\n";
        std::cout << "\nTemplate: '10 100' - enumeration from 10 to 100";
        std::cout << "\nTemplate: '10 20 30 50' - enumeration from 10 to 20, and from 30 to 50\n";
        std::cout << "if you writed that not multiples of two program ignored number!";
    }
    std::cout << "\n|-----------------------------------|\n";
    std::cout << "P.S. your number must be no more than " << std::string("").max_size() << " : symbols\n\n";
    
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

    if (mode == SEARCH_MODE::enumeration_mode && (raw_result.size()) % 2 == 1) raw_result.pop_back(); //если размер массива не кратен 2 
    if (raw_result.empty()) {
        std::cerr << "Error: Result is empty.\n";
        throw "Error: Result is empty.";
        
    }

    for (std::string el : raw_result) {
        if (!el.empty()) result.push_back(std::stoull(el)); //если вылезет исключение main.cpp его поймает
    }

    if (mode == SEARCH_MODE::enumeration_mode) {
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