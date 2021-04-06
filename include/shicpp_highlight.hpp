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

class LanguageData {
public:
    std::vector<std::string> keywords;
    std::vector<std::string> colors  ;
};

class Shicpp_Highlight {
    LanguageData data;
public:
    Shicpp_Highlight() = default;
    ~Shicpp_Highlight()= default;

    void Init(LanguageData data) noexcept {
        // TODO: Check element lengths.
        // LanguageData::color must be equal to LanguageData::keywords
        this->data = data;
    }

    std::string Colorize(const std::string& data) noexcept {
        std::string temporary(data);

        unsigned i = 0;

        for(auto& token : this->data.keywords) {
            if(token == temporary) {
                return this->data.colors[i] + temporary + "\033[0m ";
            }

            ++i;
        }

        return temporary;
    }
};

#endif // SHICPP_HIGHLIGHT_HPP
