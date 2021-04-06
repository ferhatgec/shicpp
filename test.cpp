#include <iostream>
#include "include/shicpp_parse.hpp"

#include "include/impls/shi_cpp.hpp"

int main() {
    Shicpp_Highlight highlight;

    highlight.Init(LanguageData{
       CPP::InitKeywords()      ,
       CPP::InitColors()        ,
       CPP::BuiltinKeywords()   ,
       CPP::BuiltinColors()     ,
       CPP::InitOperatorColors()
    });

    Shicpp_Parse parse(highlight);

    std::cout << parse.Parse("#include <iostream>\n"
                "// hello world!!\n"
                "int main(int argc, char** argv) {\n"
                "    int test = 10 + 20;\n"
                "    std::cout << \"10 + 20 = \" << test << '\\n';\n"
                "}");

    return 0;
}