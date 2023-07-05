// /*
// ** EPITECH PROJECT, 2023
// ** epitech
// ** File description:
// ** momo
// */

// #include "C4001.hpp"
// namespace nts {
//     Tristate C4001::returnStateType(Tristate input1, Tristate input2, size_t pin)
//     {
//         if (_type == IComponent::Type::NOR) {
//             if (input1 == Tristate::False && input2 == Tristate::False) {
//                 this->setPinValue(pin, Tristate::True);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::True;
//             }
//             if (input2 == nts::Tristate::Undefined && input2 == nts::Tristate::Undefined) {
//                 this->setPinValue(pin, Tristate::Undefined);
//                 return Tristate::Undefined;
//             }
//             else {
//                 this->setPinValue(pin, Tristate::False);
//                 return Tristate::False;
//             }
//         }
//         if (_type == IComponent::Type::AND) {
//             if (input1 == Tristate::True && input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::True);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::True;
//             }
//             if (input2 == nts::Tristate::Undefined && input2 == nts::Tristate::Undefined) {
//                 this->setPinValue(pin, Tristate::Undefined);
//                 return Tristate::Undefined;
//             }
//             else {
//                 this->setPinValue(pin, Tristate::False);
//                 return Tristate::False;
//             }
//         }
//         if (_type == IComponent::Type::XOR) {
//                 if (input1 == Tristate::True && input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::False);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::False;
//             }
//             if (input1 == Tristate::True || input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::True);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::True;
//             }
//             if (input2 == nts::Tristate::Undefined && input2 == nts::Tristate::Undefined) {
//                 this->setPinValue(pin, Tristate::Undefined);
//                 return Tristate::Undefined;
//             }
//             else {
//                 this->setPinValue(pin, Tristate::False);
//                 return Tristate::False;
//             }
//         }
//         if (_type == IComponent::Type::OR) {
//                 if (input1 == Tristate::True || input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::True);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::True;
//             }
//             if (input2 == nts::Tristate::Undefined && input2 == nts::Tristate::Undefined) {
//                 this->setPinValue(pin, Tristate::Undefined);
//                 return Tristate::Undefined;
//             }
//             else {
//                 this->setPinValue(pin, Tristate::False);
//                 return Tristate::False;
//             }
//         }
//         if (_type == IComponent::Type::NAND) {
//                 if (input1 == Tristate::True && input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::False);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::False;
//             }
//             if (input1 == Tristate::True || input2 == Tristate::True) {
//                 this->setPinValue(pin, Tristate::True);
//                 std::cout << "=================================================================== " << pin << std::endl;
//                 return Tristate::True;
//             }
//             if (input2 == nts::Tristate::Undefined && input2 == nts::Tristate::Undefined) {
//                 this->setPinValue(pin, Tristate::Undefined);
//                 return Tristate::Undefined;
//             }
//             else {
//                 this->setPinValue(pin, Tristate::True);
//                 return Tristate::True;
//             }
//         }
//         return Tristate::Undefined;
//     }
// }