// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef SHICPP_COLORFUL_HPP
#define SHICPP_COLORFUL_HPP

#include "shicpp_highlight.hpp"
#include "defs/shi_defs.hpp"

enum class Colors : const u16{
    Reset,
    Black = 30,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White, // 37
    Default = 39,

    // Light colors
    LightBlack = 90,
    LightRed,
    LightGreen,
    LightYellow,
    LightBlue,
    LightMagenta,
    LightCyan,
    LightWhite, // 97
    LightDefault = 99,

    // Background colors
    BackgroundBlack = 40,
    BackgroundRed,
    BackgroundGreen,
    BackgroundYellow,
    BackgroundBlue,
    BackgroundMagenta,
    BackgroundCyan,
    BackgroundWhite, // 47
    BackgroundDefault = 49,

    // Background light colors
    BackgroundLightBlack = 100,
    BackgroundLightRed,
    BackgroundLightGreen,
    BackgroundLightYellow,
    BackgroundLightBlue,
    BackgroundLightMagenta,
    BackgroundLightCyan,
    BackgroundLightWhite, // 107
    BackgroundLightDefault = 109
};

enum class Types : const u8 {
    Light     ,
    Bold      ,
    Dim       ,
    Italic    ,
    Underlined,
    Blink     ,
    RapidBlink,
    Reverse   ,
    Hidden     // 8
};

#define ESC "\033"

namespace colorful {
    inline std::string ok(Colors color, Types type) noexcept {
        return std::basic_string(ESC)
                + "["
                + std::to_string(static_cast<int>(type))
                + ";"
                + std::to_string(static_cast<int>(color))
                + "m";
    }

    inline std::string make(Colors color, Types type, const std::string& data) noexcept {
        return (ok(color, type)) + data;
    }
}

#endif // SHICPP_COLORFUL_HPP
