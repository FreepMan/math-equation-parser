#pragma once
#include <string>

#include "../tree/node.h"

struct Token;
typedef double (*func_type)(Node<Token>); 

enum class TokenType {
    Operator,
    Number,
    Function
};

struct Token
{
    std::string name;
    // Should take Node type in itself
    func_type function;
    Token()
    {
        name = "";
        function = NULL;
    }
    Token(const std::string& init_str, func_type func_ptr)
    {
        function = func_ptr;
        name = init_str;
    }
};