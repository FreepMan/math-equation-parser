#pragma once

#include <string>
#include "../tree/tree.h"
#include "../token/token.h"
typedef Tree<Token> AstType;




AstType parse(const std::string& buf);
