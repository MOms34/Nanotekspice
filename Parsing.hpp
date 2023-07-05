/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** momo
*/

#ifndef PARSING_HPP
#define PARSING_HPP

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
#include <string>
#include <iterator>
#include <cctype>


#include "IComponent.hpp"
namespace nts {
class Parsing {
public:
    struct MyData {
        std::string str1;
        int int1;
        std::string str2;
        int int2;
    };
    Parsing(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Can not open file\n";
            exit(84);
        }

        parseChipsets(file);
        parseLinks(file);
        parseOrderCircuit(file);
    }
    ~Parsing(){}

        std::vector<MyData> myLinkData() 
        {
            for (const auto& link : _links) {
                MyData myData;
                std::string not_dest;
                std::istringstream iss(link.second);
                iss >> myData.int1 >> myData.str2 >> myData.int2 >> not_dest;
                not_dest = nts::removeSpaces(not_dest);
                if (not_dest != "") {
                    std::cerr << "Invalid line to link in <.links:> = " << link.first << " " << link.second << std::endl;
                    exit(84);
                }
                myData.str1 = link.first;
                myVector.push_back(myData);
        }
            return myVector;

        }
    std::map<std::string, IComponent::Type> getChipsets() const {
        return _chipsets;
    }

    std::vector<std::pair<std::string, std::string>> getLinks() const {
        return _links;
    }
    std::vector<std::string> getInputs() const {
        return _inputs;
    }
    std::vector<std::string> getOrderDisplay() const {
        return _orderDisplay;
    }


private:
    int check_name(std::string nameCompar, std::vector<std::string> listcomponant, std::string errormessage)
    {
        if (listcomponant.empty())
            return 0;
        for (auto name : listcomponant) {
            if (name == nameCompar || nameCompar == "") {
                std::cerr << errormessage << nameCompar << std::endl;
                exit(84);
            }
        }
        return 0;
    }

    void parseChipsets(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line.front() == '#') {
                continue;
            }
            if (line == ".chipsets:" || (nts::removeSpaces(line)) == ".chipsets:") {
                continue;;
            }
            if (line == ".links:" || line == "\n" || (nts::removeSpaces(line)) == ".links:")
                break;
            auto firstNonSpace = line.find_first_not_of(' ');
            auto spaceIndex = line.find(' ', firstNonSpace);
            std::string componentType = line.substr(firstNonSpace, spaceIndex - firstNonSpace);
            auto secondFirstNonSpace = line.find_first_not_of(' ', spaceIndex);
            std::string componentName = line.substr(secondFirstNonSpace);
            _inputs.push_back(componentType);
            if (check_name(componentName, _componentName, "Invalid name of composant : ") == 0)
                _componentName.push_back(componentName);
            if (componentType == "input") {
                _chipsets[componentName] = IComponent::Type::INPUT;
            } else if (componentType == "true") {
                _chipsets[componentName] = IComponent::Type::True;
            } else if (componentType == "clock") {
                _chipsets[componentName] = IComponent::Type::CLOCK;
            } else if (componentType == "false") {
                _chipsets[componentName] = IComponent::Type::False;
            } else if (componentType == "output") {
                _chipsets[componentName] = IComponent::Type::OUTPUT;
            } else if (componentType == "4001") {
                componentName  = componentName + "~";
                _chipsets[componentName] = IComponent::Type::NOR;
            } else if (componentType == "4011") {
                componentName  = componentName + "~";
                _chipsets[componentName] = IComponent::Type::NAND;
            } else if (componentType == "4030") {
                componentName  = componentName + "~";
                _chipsets[componentName] = IComponent::Type::XOR;
            } else if (componentType == "4071") {
                componentName  = componentName + "~";
                _chipsets[componentName] = IComponent::Type::OR;
            } else if (componentType == "4081") {
                componentName  = componentName + "~";
                _chipsets[componentName] = IComponent::Type::AND;
            } else if (componentType == "and") {
                _chipsets[componentName] = IComponent::Type::AND;
            } else if (componentType == "or") {
                _chipsets[componentName] = IComponent::Type::OR;
            } else if (componentType == "nand") {
                _chipsets[componentName] = IComponent::Type::NAND;
            } else if (componentType == "nor") {
                _chipsets[componentName] = IComponent::Type::NOR;
            } else if (componentType == "xor") {
                _chipsets[componentName] = IComponent::Type::XOR;
            } else if (componentType == "not") {
                _chipsets[componentName] = IComponent::Type::NOT;
            } else {
                std::cerr << "Unknow component : " << componentType << std::endl;
                exit(84);
            }
        }
    }

    void parseLinks(std::ifstream& file) 
    {
        std::string line;

        while (std::getline(file, line)) {
            if (line.empty() || line.front() == '#') {
                continue;
            }
            if (line == ".circuit:" || (nts::removeSpaces(line)) == ".circuit:")
                break;
            
            size_t colon_pos = line.find(':');
            if (colon_pos == std::string::npos) {
                std::cerr << "Invalid format of link : " << line << std::endl;
                exit(84);
            }
            
            std::string source_name = line.substr(0, colon_pos);
            source_name = nts::removeSpaces(source_name);
            std::string dest_name = line.substr(colon_pos+1);

            if (check_name(source_name, _tempComponentName, "In <.Chipset> invalid name of composant : ") == 0)
                _tempComponentName.push_back(source_name);
            std::replace(dest_name.begin(), dest_name.end(), ':', ' ');
            _links.push_back(std::make_pair(source_name, dest_name));
            _tempComponentName.clear();
        }
    }

    bool is_number(std::string str)
    {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }

    void parseOrderCircuit(std::ifstream& file)
    {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line.front() == '#') {
                continue;
            }
            if (line.front() == '.') {
                std::cerr << "Invalid format of Circuit : " << line << std::endl;
                exit(84);
            }
            std::stringstream ss(line);
            std::string source_name, dest_name, not_dest;
            ss >> source_name >> dest_name >> not_dest;
            if (!not_dest.empty())
                not_dest = nts::removeSpaces(not_dest);
            if (dest_name.empty() || !is_number(dest_name) || not_dest != "") {
                std::cerr << "Invalid format it's not a number : " << dest_name << " in -> " << line << std::endl;
                exit(84);
            } else {
                if (checkInputs(source_name) == 0)
                    _orderDisplay.push_back(source_name);
                if (check_name(source_name, _tempComponentName, "In <.circuit> invalid name of composant : ") == 0) {
                    _tempComponentName.push_back(source_name);

                } else {
                    std::cerr << "Name dans .Circuit non trouvé : " << source_name << std::endl;
                    exit(84);
                }
            }
        }
    }

    int checkInputs(std::string name)
    {
        for (auto chip : _chipsets) {
            if (chip.first == name)
                return 0;
        }
        return -1;
    }

    std::vector<std::string> _inputs;
    std::map<std::string, IComponent::Type> _chipsets;
    std::vector<std::pair<std::string, std::string>> _links;
    std::vector<MyData> myVector;
    std::vector<std::string> _orderDisplay;
    std::vector<std::string> _componentName;
    std::vector<std::string> _tempComponentName;



};
}

#endif /* !PARSING_HPP */
