// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHI_CPP_HPP
#define SHI_CPP_HPP

#include "../shicpp_colorful.hpp"

//
// SHiC++ highlighting interface for C++.
//

namespace CPP {
    static std::vector<std::string> InitKeywords() noexcept {
        return std::vector<std::string> {
                "int",
                "float",
                "double"
                "long",
                "char",

                "int8_t",
                "int16_t",
                "int32_t",
                "int64_t",

                "uint8_t",
                "uint16_t",
                "uint32_t",
                "uint64_t"
        };
    }

    static std::vector<std::string> InitColors() noexcept {
        return std::vector<std::string> {
            colorful::ok(Colors::Red, Types::Light), // int
            colorful::ok(Colors::Red, Types::Light), // float
            colorful::ok(Colors::Red, Types::Light), // double
            colorful::ok(Colors::Red, Types::Light), // long
            colorful::ok(Colors::Red, Types::Light), // char

            colorful::ok(Colors::Red, Types::Light), // int8_t
            colorful::ok(Colors::Red, Types::Light), // int16_t
            colorful::ok(Colors::Red, Types::Light), // int32_t
            colorful::ok(Colors::Red, Types::Light), // int64_t

            colorful::ok(Colors::Red, Types::Light), // uint8_t
            colorful::ok(Colors::Red, Types::Light), // uint16_t
            colorful::ok(Colors::Red, Types::Light), // uint32_t
            colorful::ok(Colors::Red, Types::Light), // uint64_t
        };
    }

    static std::vector<std::string> InitOperatorColors() noexcept {
        return std::vector<std::string> {
            colorful::ok(Colors::Yellow, Types::Light), // GlobalOperators::Addition    0
            colorful::ok(Colors::Yellow, Types::Light), // GlobalOperators::Subtraction
            colorful::ok(Colors::Yellow, Types::Light), // GlobalOperators::Division
            colorful::ok(Colors::Yellow, Types::Light), // GlobalOperators::Multiplication
            colorful::ok(Colors::Yellow, Types::Light), // GlobalOperators::Modulo

            colorful::ok(Colors::Blue, Types::Light), // GlobalOperators::GreaterThan
            colorful::ok(Colors::Blue, Types::Light), // GlobalOperators::LessThan

            colorful::ok(Colors::LightRed, Types::Light), // GlobalOperators::Not

            colorful::ok(Colors::LightBlue, Types::Light), // GlobalOperators::AndBit
            colorful::ok(Colors::LightBlue, Types::Light), // GlobalOperators::OrBit
            colorful::ok(Colors::LightBlue, Types::Light), // GlobalOperators::XorBit
            colorful::ok(Colors::LightBlue, Types::Light), // GlobalOperators::NotBit

            colorful::ok(Colors::LightWhite, Types::Light)  // GlobalOperators::Assignment
        };
    }
}

#endif // SHI_CPP_HPP
