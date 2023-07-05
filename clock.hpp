/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"
#include "IComponent.hpp"

#ifndef CLOCK_HPP
#define CLOCK_HPP

namespace nts {
    class clock : public AComponent {
        public:
            clock(const std::string &name) : AComponent(name, 0, 1, IComponent::Type::CLOCK) {
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

#endif /* !CLOCK_HPP */
