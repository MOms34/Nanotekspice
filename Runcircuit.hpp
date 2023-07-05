/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "Input.hpp"
#include "Output.hpp"
#include "C4001.hpp"
#include "AND.hpp"
#include "Circuit.hpp"
#include "Factorycomposant.hpp"
#include "Parsing.hpp"

#ifndef RUNCIRCUIT_HPP
#define RUNCIRCUIT_HPP

namespace nts {
    class Runcircuit {
        public:
            Runcircuit(std::unique_ptr<nts::Circuit> &circuit, nts::factorycomponant &factory) : Circuit_(circuit), Factory_(factory) {

            }

            void SetupCircuit(const std::map<std::string, nts::IComponent::Type>& chipsets) 
            {
                for (const auto& element : chipsets) {
                    // std::cout << "Chipset name: " << element.first << std::endl;
                    if (element.second == nts::IComponent::Type::INPUT) {
    
                        Factory_.createInput(element.first);
                    }
                    if (element.second == nts::IComponent::Type::True) {
    
                        Factory_.createInputTrue(element.first);
                    }
                    if (element.second == nts::IComponent::Type::CLOCK) {
    
                        Factory_.createClock(element.first);
                    }
                    if (element.second == nts::IComponent::Type::False) {
    
                        Factory_.createInputFalse(element.first);
                    }
                    if (element.second == nts::IComponent::Type::OUTPUT) {
                        Factory_.createOutput(element.first);
                    }
                    if (element.second == nts::IComponent::Type::NOT) {
                        Factory_.createNot(element.first);
                    }
                    if (element.first[element.first.size() - 1] != '~') {
                        if (element.second == nts::IComponent::Type::AND || element.second == nts::IComponent::Type::XOR || element.second == nts::IComponent::Type::NAND || element.second == nts::IComponent::Type::NOR ||element.second == nts::IComponent::Type::OR ) {
                            Factory_.createAND(element.first, element.second);
                        }
                    }
                    if (element.first[element.first.size() - 1] == '~') {
                        if (element.second == nts::IComponent::Type::AND || element.second == nts::IComponent::Type::XOR || element.second == nts::IComponent::Type::NAND || element.second == nts::IComponent::Type::NOR ) {
                            const_cast<std::string&>(element.first).pop_back();
                            Factory_.createC4001(element.first, element.second);
                        }                       
                    }
                    
                }
            }
            void printComponant(std::unique_ptr<nts::Circuit> &Circuit) {
                Circuit->printComponents();
            }
            void linkSetup() {}
            void runAll();
            void loop_cmd();
            ~Runcircuit();

        protected:
        private:
            std::unique_ptr<nts::Circuit>& Circuit_;
            nts::factorycomponant &Factory_;
    };
}

#endif /* !RUNCIRCUIT_HPP */
