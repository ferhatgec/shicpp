// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHICPP_PARSE_HPP
#define SHICPP_PARSE_HPP

#include <string>
#include <regex>
#include <sstream>
#include <iostream>

#include "shicpp_highlight.hpp"

class Shicpp_Parse {
    Shicpp_Highlight highlight;

    std::vector<std::string> tokens;

    bool is_data    = false;
    bool is_comment = false;
public:
    Shicpp_Parse(const Shicpp_Highlight& data) noexcept {
        this->highlight = data;
    }

    ~Shicpp_Parse()= default;

    std::string Parse(std::string data) noexcept {
        std::istringstream stream(data);

        std::string generated;

        for(std::string temporary; std::getline(stream, temporary); ) {
            std::vector<std::string> keep = this->tokenize(this->make_alpha(temporary));

            for(auto& token : keep) {
                this->tokens.push_back(token);
            }

            this->tokens.push_back("\n");
        }


        for(auto& token : this->tokens) {
            if(token.empty()) continue;

            if(this->is_comment) {
                // !!!!!attention!!!!!
                if(token.back() != '\n') {
                    generated.append(this->highlight.Comment(token));
                    continue;
                }

                this->is_comment = false;
            }

            if(this->is_data) {
                generated.append(this->highlight.VarData(token));

                if(token.back() != this->highlight.data.builtins[VariableData][0]) {
                    continue;
                }

                this->is_data = false;
                continue;
            }

            if(token == this->highlight.data.builtins[SingleLineComment]) {
                this->is_comment = true;
                generated.append(this->highlight.Comment(token));

                continue;
            }

            if(token.front() == this->highlight.data.builtins[VariableData][0]
                || token.back() == this->highlight.data.builtins[VariableData][0]) {
                this->is_data = true;

                generated.append(this->highlight.VarData(token));

                continue;
            }

            generated.append(this->highlight.Colorize(token));
        }

        return generated;
    }

    std::vector<std::string> tokenize(const std::string& data) noexcept {
        std::istringstream temporary(data);
        std::vector<std::string> temporary_vector;

        for(std::string temporary_str; temporary >> temporary_str;
            temporary_vector.push_back(temporary_str));

        return temporary_vector;
    }

    std::string make_alpha(const std::string& data) noexcept {
        std::string temporary(data);

        temporary = std::regex_replace(temporary,
                                       std::regex("\\("), " ( ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\)"), " ) ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\<"), " < ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\>"), " > ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\*"), " * ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\["), " [ ");

        temporary = std::regex_replace(temporary,
                                       std::regex("\\]"), " ] ");

        return temporary;
    }
};

#endif // SHICPP_PARSE_HPP