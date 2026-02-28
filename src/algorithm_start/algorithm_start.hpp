#pragma once
#include <iostream>
#include <vector>

class algorithm_start {
public:
    //Структура для функции launch которая обеспечивает лёгкий доступ ко всем результатам функций и количеству циклов
    struct all_program_return{
        //Все возвраты функции
        std::vector<unsigned long long int> all_results;

        //Количество циклов
        std::vector<unsigned long long int> all_cycles;

        //изначальные числа
        std::vector<unsigned long long int> default_numbers;
        
    };
    
    enum SEARCH_MODE {
        default_mode, //0
        enumeration_mode //1
    };
    
    SEARCH_MODE search_mode = SEARCH_MODE::default_mode;
    int cycles_limit = 10000;


    
    //Начать выполнение алгоритма : функция возвращает результаты алгоритма
    all_program_return launch(const std::vector<unsigned long long int> &numbers);
    
    //Получить числа
    std::vector<unsigned long long int> get_numbers();
};