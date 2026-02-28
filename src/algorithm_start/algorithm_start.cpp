#include <iostream>
#include <vector>
#include <limits>
#include <console_ui.hpp>

#include "algorithm_start.hpp"

algorithm_start::all_program_return algorithm_start::launch(const std::vector<unsigned long long int> &numbers) {
    all_program_return return_info;

    for (unsigned long long int number : numbers){
        bool buffer_overload = false; //Флаг для функции который пропускает число

        if (number <= 0) continue;

        const unsigned long long int default_number = number; //Хранит изначальное число без изменений
        int cycle_counter = 0; //счётчик цикла

        while(!buffer_overload && number != 1 && cycle_counter != cycles_limit) { //Когда станет 1 цикл пойдёт по кругу
            cycle_counter++;
            
            std::cout << "[" << default_number << "] : " << "Cycle #" << cycle_counter << " ";
            if (number % 2 == 1){
                if ((number * 3 + 1) > std::numeric_limits<unsigned long long int>::max()) {

                    std::cout << "ERROR: result of operation overloaded the buffer!";
                    buffer_overload = true;
                    break;
                    
                }
                else {
                    number = (number * 3) + 1;
                }
            }
            else number = (number / 2);

            std::cout << "Result: " << number << std::endl;
        }
        std::cout << "\n\nFinal result: " << number << std::endl;
        std::cout << "For " << cycle_counter << " Cycles(to number 1)" << std::endl;

        if (number == 1) std::cout << "Number: " << default_number << " : confirms collatz hypothesis";
        else std::cout << "Number: " << default_number << " : Does not confirm collatz hypothesis";
        
        return_info.default_numbers.push_back(default_number); //Запись изначального числа в вектор
        return_info.all_results.push_back(number); //Запись итогового числа в вектор
        return_info.all_cycles.push_back(cycle_counter); //Запись количества циклов в вектор

        std::cout << "\n-------------------------------------\n";

    }
    
    return return_info;
}