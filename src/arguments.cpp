#include <iostream>

#include "arguments.hpp"

void arguments(int argc, char* argv[], algorithm_start &start_settings) {

    for (int i = 1; i < argc; i++) {
        std::string el = argv[i];

        if (el.find("=") != std::string::npos) {

            if (el.find("search_mode=") != std::string::npos) {
                int number = 0; //DEFAULT_MODE
                try {
                    number = std::stoi(el.substr(el.find("=") + 1, el.size() - 1));
                }
                catch (...) {
                    std::cout << "Unknown error. Selected default mode: " << number << std::endl;
                }
                
                if (number == 0) start_settings.search_mode = algorithm_start::SEARCH_MODE::default_mode;
                else if (number == 1) start_settings.search_mode = algorithm_start::SEARCH_MODE::enumeration_mode;
            }
            else if (el.find("cycles_limit=") != std::string::npos) {
                int number = 0;
                try {
                    number = std::stoi(el.substr(el.find("=") + 1, el.size() - 1));
                }
                catch (...) {
                    std::cout << "Unknown error. Default limit: " << start_settings.cycles_limit << std::endl;
                }
                
                if (number != 0) start_settings.cycles_limit = number;
            }

        }

    }
}
