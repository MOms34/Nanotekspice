/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/
#include "AComponent.hpp"

#ifndef INPUT_HPP
#define INPUT_HPP
namespace nts {
    class Input : public AComponent {
        public:
            Input(const std::string &name) : AComponent(name, 0, 1, IComponent::Type::INPUT) {
                _pin.resize(1);
                _pin[0] = Tristate::Undefined;
            }
       
            nts::Tristate compute(std::size_t pin) override {
                if (pin != 1)
                    throw std::out_of_range("Pin number must be 1 for input component (class INPUT)");

                return this->getPinValue(pin - 1);
            }
            void simulate(size_t tick)
            {
                tik = tick;
                compute(1);
            }

        protected:
        private:
    };
    }

#endif /* !INPUT_HPP */
