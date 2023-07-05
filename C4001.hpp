/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"
 #include "AND.hpp"

#ifndef C4001_HPP
#define C4001_HPP

namespace nts {
    class C4001 : public AComponent {
        public:
            C4001(const std::string& name, IComponent::Type type)
                : AComponent(name, 14, 4, type)
            {
                 _pin.resize(14, Tristate::Undefined);
                for (int i = 0; i < 4; i++) {
                    std::string nameNOR = "NOR" + std::to_string(i + 1);
                    _gate.push_back(AND(nameNOR, _type));
                }
                _outputPins = {3, 4, 10, 11};
                _inputPins = {1, 2, 5, 6, 8, 9, 12, 13};
                isgate = true;
            }
            ~C4001(){}

            Tristate compute(std::size_t pin) override
            {
                size_t input1Pin;
                    size_t input2Pin;
                if (std::find(_outputPins.begin(), _outputPins.end(), pin) == _outputPins.end()) {
                    std::cerr << "C4001::compute: invalid pin number " << pin << '\n';
                    return nts::Tristate::Undefined;
                }
                if (pin == 3) {
                     input1Pin = 1;
                     input2Pin = 2;
                }
                if (pin == 4) {
                     input1Pin = 5;
                     input2Pin = 6;
                }

                if (pin == 10) {
                     input1Pin = 8;
                     input2Pin = 9;
                }
                if (pin == 11) {
                     input1Pin = 12;
                     input2Pin = 13;
                }
                Tristate input1 = _links[input1Pin].first->compute(_links[input1Pin].second);
                Tristate input2 = _links[input2Pin].first->compute(_links[input2Pin].second);

                return returnStateType(input1, input2, pin);
                
            }

            void simulate(std::size_t tick) override
            {
                tick++;
                for (size_t i = 0; i < 4; ++i) {
                    size_t outputPin = _outputPins[i];
                    Tristate result = compute(outputPin);
                    setPinValue(outputPin, result);
                }
            }
              Tristate returnStateType(Tristate input1, Tristate input2, size_t pin)
    {
        if (_type == IComponent::Type::NOR) {
            if (input1 == Tristate::True || input2 == Tristate::True) {
                this->setPinValue(pin, Tristate::False);
                return Tristate::False;
            }
            if (input1 == nts::Tristate::Undefined || input2 == nts::Tristate::Undefined) {
                this->setPinValue(pin, Tristate::Undefined);
                return Tristate::Undefined;
            }
            else {
                this->setPinValue(pin, Tristate::True);
                return Tristate::True;
            }
        }
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
        if (_type == IComponent::Type::XOR) {
            if (input1 == nts::Tristate::Undefined || input2 == nts::Tristate::Undefined) {
                    this->setPinValue((pin), Tristate::Undefined);
                    return Tristate::Undefined;
            } else    
                return (input1 ^ input2) ? (this->setPinValue(pin, Tristate::True), Tristate::True) : (this->setPinValue(pin, Tristate::False), Tristate::False);
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
        if (_type == IComponent::Type::NAND) {
                if (input1 == Tristate::True || input2 == Tristate::True) {
                this->setPinValue(pin, Tristate::False);
                return Tristate::False;
            }
            if (input2 == nts::Tristate::Undefined || input1 == nts::Tristate::Undefined) {
                this->setPinValue(pin, Tristate::Undefined);
                return Tristate::Undefined;
            }
            else {
                this->setPinValue(pin, Tristate::True);
                return Tristate::True;
            }
        }
        return Tristate::Undefined;
    }
        bool isItGate()
            {
                return isgate;
            }

        private:
            bool isgate;
            std::vector<AND> _gate;
            std::vector<size_t> _outputPins;
            std::vector<size_t> _inputPins;
    };
}
#endif /* !C4001_HPP */
