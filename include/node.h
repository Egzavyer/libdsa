#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Node
{
public:
    Node(T value, Node<T> *left = nullptr, Node<T> *right = nullptr)
    {
        val = value;
        l = left;
        r = right;
    }

    ~Node()
    {
        val.~T();
    }

    T val;
    Node<T> *l;
    Node<T> *r;
};

#endif // NODE_H