// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHI_PYTHON_HPP
#define SHI_PYTHON_HPP

#include "../shicpp_colorful.hpp"

//
// SHiC++ highlighting interface for Python.
//

namespace Python {
    static std::vector<std::string> InitKeywords() noexcept {
        return std::vector<std::string> {
                "int",
                "float",
                "str",
                "char",

                "if",
                "elif",
                "else",

                "import",
                "from"
        };
    }

    static std::vector<std::string> InitColors() noexcept {
        return std::vector<std::string> {
            colorful::ok(Colors::Red, Types::Light), // int
            colorful::ok(Colors::Red, Types::Light), // float
            colorful::ok(Colors::Red, Types::Light), // str
            colorful::ok(Colors::Red, Types::Light), // char

            colorful::ok(Colors::LightRed, Types::Light), // if
            colorful::ok(Colors::LightRed, Types::Light), // elif
            colorful::ok(Colors::LightRed, Types::Light), // else

            colorful::ok(Colors::Yellow, Types::Light     ), // import
            colorful::ok(Colors::LightYellow, Types::Light)  // from
        };
    }

    static std::vector<std::string> BuiltinKeywords() noexcept {
        return std::vector<std::string> {
            "#", // SingleLineComment
            "'" // VariableData
        };
    }

    static std::vector<std::string> BuiltinColors() noexcept {
        return std::vector<std::string> {
            colorful::ok(Colors::LightBlack, Types::Light), // SingleLineComment,
            colorful::ok(Colors::White,      Types::Light)  // VariableData
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
