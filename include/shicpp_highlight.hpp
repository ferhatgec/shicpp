// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHICPP_HIGHLIGHT_HPP
#define SHICPP_HIGHLIGHT_HPP

#include <iostream>
#include <vector>

#include "defs/shi_defs.hpp"

enum class GlobalOperators : const u8 {
    Addition   = 0, // x + y
    Subtraction   , // x - y
    Division      , // x / y
    Multiplication, // x * y
    Modulo        , // x % y

    GreaterThan   , // x > y
    LessThan      , // x < y

    Not           , // !(x == y)

    AndBit        , // &
    OrBit         , // |
    XorBit        , // ^
    NotBit        , // ~

    Assignment      // x = y
};

enum Builtins : const u8 {
    SingleLineComment = 0,
    VariableData
};

class LanguageData {
public:
    std::vector<std::string> keywords     ;
    std::vector<std::string> colors       ;

    // SingleLineComment = 0
    // VariableData
    std::vector<std::string> builtins      ;
    std::vector<std::string> builtin_colors;

    // For Global operators
    std::vector<std::string> global_colors;
};

const std::vector<char> global_operators = {
        '+', // GlobalOperators::Addition    0
        '-', // GlobalOperators::Subtraction
        '/', // GlobalOperators::Division
        '*', // GlobalOperators::Multiplication
        '%', // GlobalOperators::Modulo

        '>', // GlobalOperators::GreaterThan
        '<', // GlobalOperators::LessThan

        '!', // GlobalOperators::Not

        '&', // GlobalOperators::AndBit
        '|', // GlobalOperators::OrBit
        '^', // GlobalOperators::XorBit
        '~', // GlobalOperators::NotBit

        '='  // GlobalOperators::Assignment
};

class Shicpp_Highlight {
public:
    Shicpp_Highlight() = default;
    ~Shicpp_Highlight()= default;

    LanguageData data;

    void Init(LanguageData data) noexcept {
        // TODO: Check element lengths.
        // LanguageData::color must be equal to LanguageData::keywords
        this->data = data;
    }

    std::string Comment(const std::string& data) noexcept {
        return (this->data.builtin_colors[SingleLineComment] + data) + "\033[0m ";
    }

    std::string VarData(const std::string& data) noexcept {
        return (this->data.builtin_colors[VariableData] + data) + "\033[0m ";
    }

    std::string Colorize(const std::string& data) noexcept {
        std::string temporary(data);

        unsigned i = 0;

        if(temporary.length() > 1) {
            for(auto &token : this->data.keywords) {
                if(token == temporary) {
                    return this->data.colors[i] + temporary + "\033[0m ";
                }

                ++i;
            }

            return temporary;
        }

        const char temporary_op = temporary[0];

        for(auto& op : global_operators) {
            if(op == temporary_op) {
                return this->data.global_colors[i] + temporary + "\033[0m";
            }

            ++i;
        }

        return temporary;
    }
};

#endif // SHICPP_HIGHLIGHT_HPP
