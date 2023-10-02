

#include "func.h"
#include <cmath>
#include <cstdarg>
#include <initializer_list>
#include "../exception/except.h"
#include "../token/token.h"


double p_sin(Node<Token> *t)      { throw VerboseNotImplemented;}
double p_cos(Node<Token> *t)      { throw VerboseNotImplemented; }
double p_tan(Node<Token> *t)      { throw VerboseNotImplemented; }
double p_cotan(Node<Token> *t)    { throw VerboseNotImplemented; }
double p_asin(Node<Token> *t)     { throw VerboseNotImplemented; }
double p_acos(Node<Token> *t)     { throw VerboseNotImplemented; }
double p_atan(Node<Token> *t)     { throw VerboseNotImplemented; }
double p_acotan(Node<Token> *t)   { throw VerboseNotImplemented; }
double p_mod(Node<Token> *t)      { throw VerboseNotImplemented; }
double p_ln(Node<Token> *t)       { throw VerboseNotImplemented; }
double p_log(Node<Token> *t)      { throw VerboseNotImplemented; }

double p_plus(Node<Token> *t)
{
    return t->left_child->data.function(t->left_child) + t->right_child->data.function(t->right_child);
} 

double p_minus(Node<Token> *t)
{ 
    return t->left_child->data.function(t->left_child) - t->right_child->data.function(t->right_child);
} 



double p_mult(Node<Token> *t)     { throw VerboseNotImplemented; }
double p_pow(Node<Token> *t)      { throw VerboseNotImplemented; }
double p_div(Node<Token> *t)      { throw VerboseNotImplemented; }

double p_toNumber(Node<Token> *t) { 
    return std::stod(t->data.name);
} 
double p_list(Node<Token> *t)     { throw VerboseNotImplemented; }

