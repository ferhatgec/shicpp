#include <iostream>
#include "../include/shicpp_parse.hpp"

#include "../include/impls/shi_python.hpp"

int main() {
    Shicpp_Highlight highlight;

    highlight.Init(LanguageData{
       Python::InitKeywords()      ,
       Python::InitColors()        ,
       Python::BuiltinKeywords()   ,
       Python::BuiltinColors()     ,
       Python::InitOperatorColors()
    });

    Shicpp_Parse parse(highlight);

    std::cout << parse.Parse("# python shicpp example\n"
                "import sys\n"
                "test = 10 + 20\n"
                "if test == 30:\n"
                "   print('10 + 20 =' , test)");

    return 0;
}