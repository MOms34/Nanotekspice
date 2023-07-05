/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <memory>
#include <csignal>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
#include <iterator>
#include <cctype>

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace nts {
    static inline std::string removeSpaces(const std::string& str)
    {
        std::string result;
        for (char c : str) {
            if (!std::isspace(c)) {
                result += c;
            }
        }
        return result;
    }
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
        };
    class IComponent {
        public :
        enum class Type {
        INPUT,
        CIRCUIT,
        OUTPUT,
        CHIPSET, 
        AND,
        OR,
        XOR,
        NOT,
        NOR,
        NAND,
        True,
        False,
        CLOCK
        };
        virtual ~IComponent() = default;
        virtual void simulate (std::size_t tick) = 0;
        virtual  std::string getName() const = 0;
        virtual nts::Tristate compute (std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual Type getType() const = 0;
        virtual void setPinValue(std::size_t pin, Tristate value) = 0;
        virtual Tristate getPinValue(std::size_t pin) const = 0;
        virtual bool isItGate() = 0;
    };
}

#endif /* !ICOMPONENT_HPP */
