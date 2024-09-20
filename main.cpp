#include <iostream>
#include "include/darray.h"
#include "include/llist.h"

int main()
{
    LList<int> l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    std::cout << l;

    LList<int> l2 = l;
    std::cout << l2;
}
