/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/
#include "IComponent.hpp"

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP
namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent(const std::string &name, size_t max_inputs, size_t max_output, IComponent::Type type);
            virtual ~AComponent() {}
            virtual void simulate(std::size_t tick)
            {
            tik = tick;
            // std::cout << "dans A::\n";
                for (const auto &link : _links) {
                    std::size_t pin = link.first;
                    auto component_and_pin = link.second;
                    IComponent *connected_component = component_and_pin.first;
                    std::size_t connected_pin = component_and_pin.second;

                    if (connected_component->getPinValue(connected_pin) == Tristate::Undefined) {
                    // Skip this pin if the connected component's value is UNDEFINED
                        continue;
                    }
                    _pin[pin] = connected_component->compute(connected_pin);
                    }
            }
            virtual  std::string getName() const;
            virtual nts::Tristate compute (std::size_t pin){
                // std::cout << "compute de acomponent\n";
                return _pin[pin];

            }
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            Tristate getPinValue(std::size_t pin) const;
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> getLinks()
            {
                return _links;
            }

            virtual IComponent::Type getType() const;
            virtual void setPinValue(std::size_t pin, Tristate value);
            unsigned int getOutputPinCount() const
            {
                return _max_outputs;
            }
            virtual bool isItGate(){
                return false;
            }
        protected:
            std::string _name;
            std::size_t _max_inputs;
            std::size_t _max_outputs;
            IComponent::Type _type;
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> _links;
            std::vector<Tristate> _pin;
            std::size_t tik;

        private:
    };
}

#endif /* !ACOMPONENT_HPP */
