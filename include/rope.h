#ifndef ROPE_H
#define ROPE_H

#include <iostream>
#include <string>

struct RNode {
    int weight;
    RNode *left, *right;
    char *data;
};

class Rope {
    RNode *head;
public:
    Rope() {
        head = nullptr;
    }
};

#endif //ROPE_H
