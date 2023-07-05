/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** CIRCUIT_CPP
*/

#include "Circuit.hpp"
#include "clock.hpp"
namespace nts {
    Circuit::Circuit(const std::string &name) : AComponent(name, 0, 0, IComponent::Type::CIRCUIT)
    {
        tik = 0;
        saveClock = false;
    }


    void Circuit::addComponent(IComponent *component)
    {
        if (!component) {
            std::cerr << "Error no component.\n";
            exit(84);
        }
        for (auto composant : _components) {
            if (composant->getName() == component->getName()) {
                std::cerr << "Error same component.\n";
                exit(84);
        }
                
        }
        _components.push_back(component);
    }

    void Circuit::addLink(std::size_t pin_out, IComponent &component_out, std::size_t pin_in)
    {
        _links[pin_out] = std::make_pair(&component_out, pin_in);
    }
    
    void Circuit::display_links() const
    {
        // std::cout << "Links for component " << getName() << ":" << std::endl;
        for (const auto &link : _links) {
            std::cout << "  Pin " << link.first << " is linked to " << link.second.first->getName() << " pin " << link.second.second << std::endl;
        }

    }
    void Circuit::printComponents() const
    {
        std::cout << "List of components:" << std::endl;
        for (const auto& component : _components) {
            std::cout << "- " << component->getName() << std::endl;
        }
    }

    void Circuit::update_tik()
    {
        tik++;
          
    }
    void Circuit::updateInput()
    {
        if (inputs_state.empty())
            return;
        for (auto input : inputs_state) {
            this->getComponent(input.first)->setPinValue(0, input.second);
        }
        inputs_state.clear();
    }

    void Circuit::saveInput(std::string name, nts::Tristate state)
    {
        auto it = inputs_state.find(name);
        if (it == inputs_state.end()) {
            inputs_state.insert({name, state});
        } else {
            it->second = state;
        }
        if (getComponent(name)->getType() == nts::IComponent::Type::True)
            std::cerr << "For " << this->getName() << " A Component True is always <True>.\n";
        if (getComponent(name)->getType() == nts::IComponent::Type::False)
            std::cerr << "For " << this->getName() << " A Component False is always <False>.\n";
        if (getComponent(name)->getType() == nts::IComponent::Type::CLOCK)
            saveClock = true;
            
    }

}
