#include <iostream>
#include <vector>
#include <cmath>
#include <console_ui.hpp>

#include "algorithm_start.hpp"

algorithm_start::all_program_return algorithm_start::launch(const std::vector<unsigned long long int> *numbers) {
    all_program_return return_info;

    for (unsigned long long int number : *numbers){

        const unsigned long long int default_number = number; //Хранит изначальное число без изменений
        int cycle_counter = 0; //счётчик цикла

        while(number != 1 && cycle_counter != cycles_limit) { //Когда станет 1 цикл пойдёт по кругу
            cycle_counter++;
            
            std::cout << "[" << default_number << "] : " << "Cycle #" << cycle_counter << " ";
            
            if (number % 2 == 1) number = (number * 3) + 1;
            else number = (number / 2);

            std::cout << "Result: " << number << std::endl;
        }
        std::cout << "\n\nFinal result: " << number << std::endl;
        std::cout << "For " << cycle_counter << " Cycles(to number 1)" << std::endl;

        if (number == 1) std::cout << "Number: " << number << " : Does not confirm collatz hypothesis";
        else std::cout << "Number: " << number << " : confirm collatz hypothesis";
        
        return_info.default_numbers.push_back(default_number); //Запись изначального числа в вектор
        return_info.all_results.push_back(number); //Запись итогового числа в вектор
        return_info.all_cycles.push_back(cycle_counter); //Запись количества циклов в вектор

        std::cout << "\n-------------------------------------\n";

    }
    
    return return_info;
}