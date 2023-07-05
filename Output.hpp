/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"

#ifndef OUTPUT_HPP
#define OUTPUT_HPP
namespace nts {
class Output : public AComponent {
    public:
        Output(const std::string &name)
            : AComponent(name, 1, 0, IComponent::Type::OUTPUT) {
                _pin.resize(1);
                _pin[0] = Tristate::Undefined;
            }
        ~Output(){}
        Tristate compute(std::size_t pin) {
            // Vérifier que la broche demandée est une broche d'entrée
            if (pin != 0)
                return Tristate::Undefined;
            // Récupérer la valeur de l'entrée
            if (_links[1].first->getType() == nts::IComponent::Type::True)
                this->setPinValue(pin, nts::Tristate::True);
            else if (_links[1].first->getType() == nts::IComponent::Type::False)
                this->setPinValue(pin, nts::Tristate::False);
            else if (_links[1].first->getType() == nts::IComponent::Type::INPUT || _links[1].first->getType() == nts::IComponent::Type::CLOCK)
                this->setPinValue(pin, _links[1].first->compute(_links[1].second));
            else 
                this->setPinValue(0, _links[1].first->getPinValue(_links[1].second));       
            return getPinValue(_links[1].second);
        }

        void simulate(std::size_t tick) {
            this->compute(0);
            tick++;
        }
    };
}

#endif /* !OUTPUT_HPP */
