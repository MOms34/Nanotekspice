/*
** EPITECH PROJECT, 2023
** epite
** File description:
** momo
*/

#include "IComponent.hpp" 
#include "AComponent.hpp"
#include "Circuit.hpp"
#include "AND.hpp"
#include "False.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "C4001.hpp"
#include <string>
#include "Parsing.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Factorycomposant.hpp"
#include "Runcircuit.hpp"
#include "False.hpp"
#include "True.hpp"
#include "Not.hpp"

int main(int ac, char** argv)
{
  if (ac != 2) {
    std::cerr << "NEED FILE\n";
    return 84;
  }
  std::unique_ptr<nts::Circuit> Circuit = std::make_unique<nts::Circuit>("circuit 1");
  std::unique_ptr<nts::Parsing> parser = std::make_unique<nts::Parsing>(argv[1]);
  nts::factorycomponant factory(Circuit);
  nts::Runcircuit run(Circuit, factory);
  std::string input;

  auto chipsets = parser->getChipsets();
  auto links = parser->getLinks();
  auto inputs = parser->getInputs();
  auto orderDisplay = parser->getOrderDisplay();

  if (chipsets.empty() || links.empty()) {
    std::cerr << "Link or Chipsets are empty.\n";
    return 84;
  }
  run.SetupCircuit(chipsets);
        std::vector<nts::Parsing::MyData> parseLink = parser->myLinkData();
    for (const auto& data : parseLink) {
        Circuit->getComponent(data.str1)->setLink(data.int1,  *Circuit->getComponent(data.str2), data.int2);
        Circuit->getComponent(data.str2)->setLink(data.int2,  *Circuit->getComponent(data.str1), data.int1);
    }
    Circuit->simulateAll();
    run.runAll();
  return 0;
}
