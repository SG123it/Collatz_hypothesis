#pragma once
#include <iostream>
#include <vector>

class algorithm_start {
public:
    enum SEARCH_MODE {
        default_mode,
        enumeration_mode
    };
    SEARCH_MODE search_mode = SEARCH_MODE::default_mode;
    int cycles_limit = 1000000;

    //Начать выполнение алгоритма : функция возвращает результаты алгоритма
    std::vector<unsigned long long int> launch(const std::vector<unsigned long long int> *numbers);
    
    //Получить числа
    std::vector<unsigned long long int> get_numbers();
};