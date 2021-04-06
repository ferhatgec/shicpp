// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHI_CPP_HPP
#define SHI_CPP_HPP

#include "../shicpp_highlight.hpp"

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
            "\033[0;31m", // int
            "\033[0;31m", // float
            "\033[0;31m", // double
            "\033[0;31m", // long

            "\033[0;31m", // int8_t
            "\033[0;31m", // int16_t
            "\033[0;31m", // int32_t
            "\033[0;31m", // int64_t

            "\033[0;31m", // uint8_t
            "\033[0;31m", // uint16_t
            "\033[0;31m", // uint32_t
            "\033[0;31m", // uint64_t
        };
    }

    static std::vector<std::string> InitOperatorColors() noexcept {
        return std::vector<std::string> {
            "\033[0;34m", // GlobalOperators::Addition    0
            "\033[0;34m", // GlobalOperators::Subtraction
            "\033[0;34m", // GlobalOperators::Division
            "\033[0;34m", // GlobalOperators::Multiplication
            "\033[0;34m", // GlobalOperators::Modulo

            "\033[0;32m", // GlobalOperators::GreaterThan
            "\033[0;32m", // GlobalOperators::LessThan

            "\033[0;91m", // GlobalOperators::Not

            "\033[0;94m", // GlobalOperators::AndBit
            "\033[0;94m", // GlobalOperators::OrBit
            "\033[0;94m", // GlobalOperators::XorBit
            "\033[0;94m", // GlobalOperators::NotBit

            "\033[0;97m"  // GlobalOperators::Assignment
        };
    }
}

#endif // SHI_CPP_HPP
