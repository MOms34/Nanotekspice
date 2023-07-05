/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "Runcircuit.hpp"

namespace nts {

    void Runcircuit::runAll()
    {
        std::cout << "> ";
        std::string input;
        while (std::getline(std::cin, input)) {
            input = nts::removeSpaces(input);
            if (input == "display") {
                Circuit_->DisplayAllState();
            } else if (input == "simulate") {
                Circuit_->update_tik();
                Circuit_->updateInput();
                Circuit_->simulateAll();
            } else if (input == "exit") {
                return;
            } else if (input == "loop") {
                loop_cmd();
            } else {
                size_t pos = input.find("=");
                if (pos != std::string::npos) {
                    std::string name = input.substr(0, pos);
                    size_t name_end = name.find_last_not_of(" \t");
                    if (name_end != std::string::npos) {
                        name.erase(name_end + 1);
                    }
                    std::string tristate = input.substr(pos + 1);
                    if (tristate == "1") {
                        Circuit_->getComponent(name);
                        Circuit_->saveInput(name, nts::Tristate::True);
                    } else if (tristate == "0") {
                        Circuit_->getComponent(name);
                        Circuit_->saveInput(name, nts::Tristate::False);
                    } else if (tristate == "U") {
                        Circuit_->getComponent(name);
                        Circuit_->saveInput(name, nts::Tristate::Undefined);
                    } else
                        std::cerr << "Unknow cmd\n";   


                } else
                    std::cerr << "Unknow cmd\n";    
        }
        std::cout << "> ";
    }
    return;
    }

    int is_signal(int _state = -1) 
    {
        static bool state = false;

        if (_state == 0)
            state = false;
        else if (_state == 1)
            state = true;
        return state;
    }

    void signalHandler(int signal)
    {
        if (signal == SIGINT) {
            is_signal(true);
        }
    }

    void Runcircuit::loop_cmd()
    {
        signal(SIGINT, signalHandler);
        while (!is_signal()) {
            Circuit_->update_tik();
            Circuit_->simulateAll();
            Circuit_->DisplayAllState();
        }
        signal(SIGINT, SIG_DFL);
        is_signal(false);
    }

    Runcircuit::~Runcircuit()
    {

    }
}
