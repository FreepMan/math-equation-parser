#include <iostream>
#include "src/parser/parser.h"

constexpr int BAD_INPUT = 1;

int main(int argc, char **argv){
    if (argc == 1)
    {
        std::cout << "Usage: ./bin <expression>" << std::endl;
        return BAD_INPUT;
    }
    std::string buf(argv[1]);
    parse(buf);
    return 0;
}
