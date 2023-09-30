#pragma once

#include <cstddef>

template<typename T>
struct Node {
    T data;
    Node *left_child = NULL;
    Node *right_child = NULL;
};