#include <iostream>
#include "include/shicpp_parse.hpp"

#include "include/impls/shi_cpp.hpp"

int main() {
    Shicpp_Highlight highlight;

    highlight.Init(LanguageData{
       CPP::InitKeywords(),
       CPP::InitColors()
    });

    Shicpp_Parse parse(highlight);

    std::cout << parse.Parse("#include <iostream>\n"
                "\n"
                "int main(int argc) {\n"
                "    std::cout << \"Hello, world!\\n\";\n"
                "}");

    return 0;
}