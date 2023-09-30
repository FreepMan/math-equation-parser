#include <cctype>
#include <string>
#include <unordered_map>
#include <iostream>
#include "../exception/except.h"
#include "../func/func.h"
#include "../token/token.h"
#include "../tree/tree.h"
#include "./parser.h"








std::unordered_map<std::string, func_type> keywords = {
    {"sin", p_sin},
    {"cos", p_cos},
    {"tan", p_tan},
    {"cotan",p_cotan},
    {"asin",p_asin},
    {"acos",p_acos},
    {"atan", p_atan},
    {"acotan",p_acotan},
    {"mod",p_mod},
    {"ln",p_ln},
    {"log",p_log},
    {"+", p_plus},
    {"-",p_minus},
    {"*",p_mult},
    {"**",p_pow},
    {"^",p_pow},
    {"/", p_div},
    {"%", p_mod},
    {",", p_list},
    {"num",p_toNumber}
};



TokenType what_is(char c)
{
    throw VerboseNotImplemented; 
}


bool EmptyToken(Token tkn)
{
    return tkn.name.size() == 0;
}

/**
 * @brief returns next token in sequence. Stores internal static variable that points to next token
 * @param buf param to be parsed
 * Another name for this function is a tokenizer.
 */
Token lexer(const std::string &buf) 
{
    // iterator pointing at the next token 
    static size_t i = 0;
    if (i > buf.size())
    {
        i = 0;
        return Token();
    }
    Token tkn;
    switch (what_is(buf[i]))
    {
        case TokenType::Function:
            while (isalpha(buf[i]))
            {
                tkn.name += buf[i]; 
                ++i;
            }
            tkn.function = keywords.find(tkn.name)->second;
            break;
        case TokenType::Number:
            while (isdigit(buf[i]))
            {
                tkn.name += buf[i];
                ++i;
            }
            // to number
            tkn.function = keywords.find("num")->second;
            break;
        case TokenType::Operator:
            while (ispunct(buf[i]))
            {
                tkn.name += buf[i];
                ++i;
            }
            tkn.function = keywords.find(tkn.name)->second;
            break;
        default:
            throw std::logic_error(std::string("Character cannot be recognized: ") + buf[i]);
    }
    return tkn;
}


Tree<Token> parse(const std::string& buf) 
{
    Tree<Token> AST;
    Token tkn = lexer(buf);
    while (!EmptyToken(tkn))
    {
        tkn = lexer(buf);
    }
    throw VerboseNotImplemented;
    return AST;
}




/**
 * TODO:
 * -----
 * * CFG!
 * * First and follow
 * * Parsing Table 
 */
