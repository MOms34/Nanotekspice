/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "AComponent.hpp"
#
namespace nts {
    AComponent::AComponent(const std::string &name, size_t max_inputs, size_t max_output, IComponent::Type type)
    :_name(name), _max_inputs(max_inputs), _max_outputs(max_output), _type(type)
    {

    }

    void AComponent::setLink(std::size_t pin, IComponent &component, std::size_t otherPin)
    {
        //lien entre deux pins et deux composants
        if (pin > this->_max_outputs + this->_max_inputs) {
          std::cerr << "invalid pin to links " << this->getName() << "with numerber pin = " << pin << std::endl;
          exit(84);
        }
        _links[pin] = std::make_pair(&component, otherPin);
    }
    std::string AComponent::getName() const
    { 
        return _name;
    }
    IComponent::Type AComponent::getType() const 
    { 
        return _type;
    }
    Tristate AComponent::getPinValue(std::size_t pin) const {

      if (pin <= _pin.size()) {
        return _pin[pin];
      }
      return Tristate::Undefined;
    }

    void AComponent::setPinValue(std::size_t pin, Tristate value) {
        // std::cout << "value = " << value << " pin_size = " << _pin.size() << " et PIn arg = " << pin << std::endl ;

      if (pin <= _pin.size()) {
        _pin[pin] = value;
      }
    }

}

