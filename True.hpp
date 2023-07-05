/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"

#ifndef TRUE_HPP
#define TRUE_HPP

namespace nts {
    class inputTrue : public AComponent {
        public:
            inputTrue(const std::string &name) : AComponent(name, 0, 1, IComponent::Type::True) {
                _pin.resize(1);
                _pin[0] = Tristate::True;
            }
       
            nts::Tristate compute(std::size_t pin) override {
                if (pin != 1)
                    throw std::out_of_range("Pin number must be 1 for input component (class INPUT)");

                return nts::Tristate::True;
            }
            void simulate(size_t tick)
            {
                tik = tick;
                compute(1);
            }

            void setPinValue(std::size_t pin, Tristate value) {
                if (pin <= _pin.size() && value == nts::Tristate::False) {
                    _pin[pin] = nts::Tristate::True;
                }
                if (pin <= _pin.size() && value == nts::Tristate::Undefined) {
                    _pin[pin] = nts::Tristate::True;
                }
                _pin[pin] = nts::Tristate::True;
            }


        protected:
        private:
    };
    }

#endif /* !TRUE_HPP */
