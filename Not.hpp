/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"

#ifndef NOT_HPP
#define NOT_HPP

namespace nts {
    class CNot : public AComponent {
        public:
            CNot (const std::string &name) : AComponent(name, 1, 1, IComponent::Type::NOT) {
                _pin.resize(3, Tristate::Undefined);
            }
            ~CNot() {}
            Tristate compute(std::size_t pin)
            {
                if (pin != 2) {
                    // std::cout << "ta grand mere la pute \n";
                    return Tristate::Undefined;
                }
                // Récupérer les valeurs des entrées
                Tristate input1 = _links[1].first->compute(_links[1].second);
                if (input1 == Tristate::True) {
                    this->setPinValue((pin), Tristate::False);
                    return Tristate::False;
                }
                if (input1 == Tristate::False) {
                    this->setPinValue((pin), Tristate::True);
                    return Tristate::True;
                }
                else {
                    this->setPinValue((pin), Tristate::Undefined);
                    return Tristate::Undefined;
                }
            }
            void simulate (std::size_t tick) {
                this->compute(2);
                tick++;
            }
            bool isItGate()
            {
                return isgate;
            }

        protected:
        private:
            bool isgate;
    };
}

#endif /* !NOT_HPP */
