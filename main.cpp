#include <iostream>
#include "src/parser/parser.h"
#include "src/tree/tree.h"
#include "src/func/func.h"
constexpr int BAD_INPUT = 1;

int main(int argc, char **argv){
    if (argc == 1)
    {
        std::cerr << "Usage: ./bin <expression>\n";
        return BAD_INPUT;
    } 
    std::string parse_str = "";
    for (int i = 1; i != argc; ++i)
    {
        parse_str += argv[i];
    }
    std::cout << "parse_str: " << parse_str << std::endl;
    parse(parse_str);
    return 0;
}
