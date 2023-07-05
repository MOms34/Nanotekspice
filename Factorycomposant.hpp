/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include "Input.hpp"
#include "Output.hpp"
#include "C4001.hpp"
#include "AND.hpp"
#include "Circuit.hpp"
#include "False.hpp"
#include "True.hpp"
#include "clock.hpp"
#include "Not.hpp"

#ifndef FACTORYUCOMPOSANT_HPP
#define FACTORYUCOMPOSANT_HPP
namespace nts {
    class factorycomponant {
    public:
    factorycomponant(std::unique_ptr<nts::Circuit>& circuit)
        : Circuit_(circuit) {}

    std::unique_ptr<nts::Input> createInput(const std::string& name) {
        auto input = std::make_unique<nts::Input>(name);
        Circuit_->addComponent(input.get());
        inputComponents_.push_back(std::move(input));
        return std::make_unique<nts::Input>(*inputComponents_.back().get());
    }
    std::unique_ptr<nts::clock> createClock(const std::string& name) {
        auto clock = std::make_unique<nts::clock>(name);
        Circuit_->addComponent(clock.get());
        clockComponents_.push_back(std::move(clock));
        return std::make_unique<nts::clock>(*clockComponents_.back().get());
    }
    std::unique_ptr<nts::inputFalse> createInputFalse(const std::string& name) {
        auto inputFalse = std::make_unique<nts::inputFalse>(name);
        Circuit_->addComponent(inputFalse.get());
        inputFalseComponents_.push_back(std::move(inputFalse));
        return std::make_unique<nts::inputFalse>(*inputFalseComponents_.back().get());
    }
    std::unique_ptr<nts::inputTrue> createInputTrue(const std::string& name) {
        auto inputTrue = std::make_unique<nts::inputTrue>(name);
        Circuit_->addComponent(inputTrue.get());
        inputTrueComponents_.push_back(std::move(inputTrue));
        return std::make_unique<nts::inputTrue>(*inputTrueComponents_.back().get());
    }

    std::unique_ptr<nts::Output> createOutput(const std::string& name) {
        auto output = std::make_unique<nts::Output>(name);
        Circuit_->addComponent(output.get());
        outputComponents_.push_back(std::move(output));
        return std::make_unique<nts::Output>(*outputComponents_.back().get());
    }
    std::unique_ptr<nts::CNot> createNot(const std::string& name) {
        auto notObject = std::make_unique<nts::CNot>(name);
        Circuit_->addComponent(notObject.get());
        notComponents_.push_back(std::move(notObject));
        return std::make_unique<nts::CNot>(*notComponents_.back().get());
    }

    

    std::unique_ptr<nts::C4001> createC4001(const std::string& name, nts::IComponent::Type type) {
        auto c4001 = std::make_unique<nts::C4001>(name, type);
        Circuit_->addComponent(c4001.get());
                        // std::cout << "\n\n\n^bababne================================================boum " << name <<"\n\n\n";

        gateComponents_.push_back(std::move(c4001));
        return  std::make_unique<nts::C4001>(*gateComponents_.back().get());
    }

    std::unique_ptr<nts::AND> createAND(const std::string& name, nts::IComponent::Type type) {
        auto AND = std::make_unique<nts::AND>(name, type);
        Circuit_->addComponent(AND.get());
        ANDComponents_.push_back(std::move(AND));
        // std::cout << "dans factory :: " << name << =
        return  std::make_unique<nts::AND>(*ANDComponents_.back().get());
    }

    private:
    std::unique_ptr<nts::Circuit>& Circuit_;
    std::vector<std::unique_ptr<nts::CNot>> notComponents_;
    std::vector<std::unique_ptr<nts::clock>> clockComponents_;
    std::vector<std::unique_ptr<nts::inputTrue>> inputTrueComponents_;
    std::vector<std::unique_ptr<nts::inputFalse>> inputFalseComponents_;
    std::vector<std::unique_ptr<nts::Input>> inputComponents_;
    std::vector<std::unique_ptr<nts::Output>> outputComponents_;
    std::vector<std::unique_ptr<nts::C4001>> gateComponents_;
    std::vector<std::unique_ptr<nts::AND>> ANDComponents_;
    };
}

#endif /* !FACTORYUCOMPOSANT_HPP */
