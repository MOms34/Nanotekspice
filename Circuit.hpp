/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/
#include "AComponent.hpp"


#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

namespace nts {

    class Circuit : public AComponent {
        public:
            Circuit(const std::string &name);
            ~Circuit(){}
            void addComponent(IComponent *component);
            void addLink(std::size_t pin_out, IComponent &component_out, std::size_t pin_in);
            Tristate compute(std::size_t pin = 1){
                return _pin[pin];
            }
            void display_links() const;
            void simulateAll() {
                for (std::size_t tick = 0; tick < 1; ++tick) {
                    for (auto component : _components) {
                        if (component->getType() != nts::IComponent::Type::OUTPUT && component->getType() != nts::IComponent::Type::CLOCK ) {
                        // std::cout << "\n" << "dans la simulation teh zebi =" << component->getName() << std::endl;

                            component->simulate(tick);
                        } else if (component->getType() == nts::IComponent::Type::CLOCK && saveClock == true) {
                            component->simulate(tick);
                        } else if (component->getType() == nts::IComponent::Type::CLOCK && saveClock == false && component->getPinValue(0) != nts::Tristate::Undefined && component->getPinValue(0) == nts::Tristate::False)
                            component->setPinValue(0, nts::Tristate::True);
                        else if (component->getType() == nts::IComponent::Type::CLOCK && saveClock == false && component->getPinValue(0) != nts::Tristate::Undefined && component->getPinValue(0) == nts::Tristate::True) {
                            component->setPinValue(0, nts::Tristate::False);
                        }
                        else    
                            continue;
                    }
                    for (auto component : _components) {
                        if (component->getType() == nts::IComponent::Type::OUTPUT) {
                        // std::cout << "\n" << "dans la simulation teh zebi =" << component->getName() << std::endl;
                            component->simulate(tick);
                        }
                    }
                }
                saveClock = false;
                // updateInput();
            }
            void setInputs(std::vector<std::string> inputName)
            {
                inputs = inputName;
            }
            std::string getMyPrintState(nts::Tristate state)
            {
                std::string temp;
                if (state == nts::Tristate::Undefined)
                    return temp = "U";
                if (state == nts::Tristate::True)
                    return temp = "1";
                else
                    return temp = "0";
            }

            void DisplayAllState()
            {
                // std::cout << "\n";
                std::cout << "tick: "<< tik << "\n";
                std::cout << "input(s):\n";
                for (auto component : _components) {

                    if (component->getType() == IComponent::Type::INPUT || component->getType() == IComponent::Type::CLOCK) {
                        std::cout << "  " << component->getName() << ": " << getMyPrintState(component->getPinValue(0)) << std::endl;
                    }


                }
                std::cout << "output(s):\n";
                for (auto component : _components) {
                    if (component->getType() == IComponent::Type::OUTPUT)
                        std::cout << "  " << component->getName() << ": " << getMyPrintState(component->getPinValue(0)) << std::endl;
                }
                // std::cout << "\n";
            }
            void printComponents() const;

            size_t composantNameAt(std::string name)
            {
                 for (size_t i = 0; i < _components.size(); i++) {
                    if (_components[i]->getName() == name) {
                        return i;
                    }
                }
                return std::string::npos;
                
            }
            IComponent *getComponent(std::string name)
            {
                
                 for (size_t i = 0; i < _components.size(); i++) {
                    if (_components[i]->getName() == name) {
                        return _components[i];
                    }
                        // std::cout << "\n" << "name =" << name << "gett == " << _components[i]->getName() << " HELLA \n";
                }
                std::cerr << "Unknow component to do links : " << name << std::endl;
                exit(84);
            }
            void update_tik();
            void updateInput();
            void saveInput(std::string name, nts::Tristate state);

        protected:
            size_t tik;
        private:
            std::map<std::string, nts::Tristate> inputs_state;
            std::vector<IComponent *> _components;
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> _links;
            std::vector<std::string> inputs;
            bool saveClock;
    };
    std::ostream &operator<<(std::ostream &os, const std::pair<IComponent*, std::size_t> &p);

}

#endif /* !CIRCUIT_HPP */
