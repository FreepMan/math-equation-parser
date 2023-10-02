#pragma once

#include <initializer_list>
#include "../tree/node.h"
#include "../token/token.h"

double p_toNumber(Node<Token> *t);
double p_list(Node<Token> *t); // traverses all adjacent ',' operators
double p_sin(Node<Token> *t);
double p_cos(Node<Token> *t);
double p_tan(Node<Token> *t);
double p_cotan(Node<Token> *t);
double p_asin(Node<Token> *t);
double p_acos(Node<Token> *t);
double p_atan(Node<Token> *t);
double p_acotan(Node<Token> *t);
double p_mod(Node<Token> *t);
double p_ln(Node<Token> *t);
double p_log(Node<Token> *t);
double p_plus(Node<Token> *t);
double p_minus(Node<Token> *t);
double p_mult(Node<Token> *t);
double p_pow(Node<Token> *t);
double p_div(Node<Token> *t);
