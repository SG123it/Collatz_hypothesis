#include <iostream>
#include <vector>
#include <cmath>

#include "algorithm_start.hpp"

std::vector<unsigned long long int> algorithm_start(const unsigned long long int *number){
    std::vector<unsigned long long int> result_history; //история результатов
    unsigned long long int number_copy = *number; //копия оригинального числа чтобы не переписывать оригинал

    int cycle_counter = 0; //счётчик цикла
    while(number_copy != 1) { //Когда станет 1 цикл пойдёт по кругу
        cycle_counter++;
        
        std::cout << "Cycle #" << cycle_counter << " ";
        
        if (std::fmod(number_copy, 2) == 1) number_copy = (number_copy * 3) + 1;
        else number_copy = (number_copy / 2);
        

        std::cout << "Result: " << number_copy << std::endl;
        result_history.push_back(number_copy);
    }
    std::cout << "\n\nFinal result: " << number_copy << std::endl;
    std::cout << "For " << cycle_counter << " Cycles(to number 1)" << std::endl;

    if (number_copy == 1) std::cout << "Number: " << *number << " : Does not confirm collatz hypothesis";
    else std::cout << "Number: " << *number << " : confirm collatz hypothesis";
    
    return result_history;
}