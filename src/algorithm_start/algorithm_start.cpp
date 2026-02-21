#include <iostream>
#include <vector>
#include <cmath>

#include "algorithm_start.hpp"

std::vector<unsigned long long int> algorithm_start::launch(const std::vector<unsigned long long int> *numbers) {
    std::vector<unsigned long long int> all_results; //Результат всех чисел из вектора

    for (unsigned long long int number : *numbers){

        int cycle_counter = 0; //счётчик цикла
        while(number != 1) { //Когда станет 1 цикл пойдёт по кругу
            cycle_counter++;
            
            std::cout << "[" << number << "] : " << "Cycle #" << cycle_counter << " ";
            
            if (number % 2 == 1) number = (number * 3) + 1;
            else number = (number / 2);
            

            std::cout << "Result: " << number << std::endl;
        }
        std::cout << "\n\nFinal result: " << number << std::endl;
        std::cout << "For " << cycle_counter << " Cycles(to number 1)" << std::endl;

        if (number == 1) std::cout << "Number: " << number << " : Does not confirm collatz hypothesis";
        else std::cout << "Number: " << number << " : confirm collatz hypothesis";
        all_results.push_back(number);

        std::cout << "\n-------------------------------------\n";
    }
    
    return all_results;
}