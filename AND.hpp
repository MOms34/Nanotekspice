/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"
#ifndef AND_HPP
#define AND_HPP
namespace nts {
    class AND : public AComponent {
        public:
            AND(const std::string &name, IComponent::Type type) : AComponent(name, 2, 1, type) {
                _pin.resize(4, Tristate::Undefined);
                isgate = false;
            }
            Tristate compute(std::size_t pin)
            {
                if (pin != 3) {
                    return Tristate::Undefined;
                }
                // Récupérer les valeurs des entrées
                Tristate input1 = _links[1].first->compute(_links[1].second);
                Tristate input2 = _links[2].first->compute(_links[2].second);
                if (_type == IComponent::Type::AND) {
                    if (input1 == nts::Tristate::False || input2 == nts::Tristate::False) {
                        this->setPinValue((pin), Tristate::False);
                        return Tristate::False;
                    }
                    if (input1 == nts::Tristate::Undefined || input2 == nts::Tristate::Undefined) {
                        this->setPinValue((pin), Tristate::Undefined);
                        return Tristate::Undefined;
                    }
                    this->setPinValue((pin), Tristate::True);
                        return Tristate::True;
                }
                if (_type == IComponent::Type::OR) {
                    if (input1 == nts::Tristate::True || input2 == nts::Tristate::True) {
                        this->setPinValue((pin), Tristate::True);
                        return Tristate::True;
                    }
                    if (input1 == nts::Tristate::Undefined || input2 == nts::Tristate::Undefined) {
                        this->setPinValue((pin), Tristate::Undefined);
                        return Tristate::Undefined;
                    }
                    this->setPinValue((pin), Tristate::False);
                        return Tristate::False;
                }
                 if (input1 == nts::Tristate::Undefined || input2 == nts::Tristate::Undefined) {
                        this->setPinValue(pin, nts::Tristate::Undefined);
                        return nts::Tristate::Undefined;
                } else if (_type == IComponent::Type::XOR) {
                    return (input1 ^ input2) ? (this->setPinValue(pin, Tristate::True), Tristate::True) : (this->setPinValue(pin, Tristate::False), Tristate::False);
                } else if (_type == IComponent::Type::NOR) {
                    return (input1 | input2) ? (this->setPinValue(pin, Tristate::False), Tristate::False) : (this->setPinValue(pin, Tristate::True), Tristate::True);
                } else if (_type == IComponent::Type::NAND) {
                    return (input1 & input2) ? (this->setPinValue(pin, Tristate::False), Tristate::False) : (this->setPinValue(pin, Tristate::True), Tristate::True);
                } else {
                    return nts::Tristate::Undefined;
                }
            }
            void simulate (std::size_t tick) {
                this->compute(3);
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
#endif /* !AND_HPP */
