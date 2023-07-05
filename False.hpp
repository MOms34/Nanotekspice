/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/
#include "AComponent.hpp"

#ifndef FALSE_HPP
#define FALSE_HPP

namespace nts {
    class inputFalse : public AComponent {
        public:
            inputFalse(const std::string &name) : AComponent(name, 0, 1, IComponent::Type::False) {
                _pin.resize(1);
                _pin[0] = Tristate::False;
            }
       
            nts::Tristate compute(std::size_t pin) override {
                if (pin != 1)
                    throw std::out_of_range("Pin number must be 1 for input component (class InputFalse)");

                return nts::Tristate::False;
            }

            void simulate(size_t tick)
            {
                tik = tick;
                compute(1);
            }
            void setPinValue(std::size_t pin, Tristate value) {
                if (pin <= _pin.size() && value == nts::Tristate::True) {
                    _pin[pin] = nts::Tristate::False;
                }
                if (pin <= _pin.size() && value == nts::Tristate::Undefined) {
                    _pin[pin] = nts::Tristate::False;
                }
                _pin[pin] = nts::Tristate::False;
            }

        protected:
        private:
    };
}

#endif /* !FALSE_HPP */
