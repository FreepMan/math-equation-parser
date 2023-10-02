#pragma once

#include <cstddef>
#include "../exception/except.h"
#include "../token/token.h"
#include "../tree/node.h"
#include <iostream>

// OK, it's better than an array



/**
 * Actually, we can always push the operator to the top of the tree.
 * Then, we only need to care about push_top() and eval()
 * And iterator types
 */


template<typename T = Token, typename RetType = double>
class Tree {
    Node<T> *top = NULL;
    typedef NotImplemented iterator_type;
public:
    Tree push_top(const Token &tkn);
    Tree push_left(const Token &tkn);
    Tree push_right(const Token &tkn);
    RetType eval();
    void free();
};


// adds on the top a token
template<typename T, typename N>
Tree<T,N> Tree<T,N>::push_top(const Token &tkn)
{
    Node<T> *new_element = new Node<T>;
    new_element->data = tkn;
    new_element->right_child = top;
    top = new_element;
    return *this;
}


// adds as a left child of top a token
template<typename T, typename N>
Tree<T,N> Tree<T,N>::push_left(const Token &tkn)
{
    Node<T> *left_child = new Node<T>;
    left_child->data = tkn;
    top->left_child = left_child;
    return *this;
}


template<typename T, typename N>
Tree<T,N> Tree<T,N>::push_right(const Token &tkn) 
{
    Node<T> *right_child = new Node<T>;
    right_child ->data = tkn;
    top->right_child = right_child;
    return *this;
}

template<typename T, typename N>
N Tree<T, N>::eval()
{
    return top->data.function(top); 
}
