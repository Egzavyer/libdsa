#include <iostream>
#include "include/darray.h"
#include "include/llist.h"

int main()
{
    LList<int> l;
    l.insertFront(1);
    l.insertFront(2);
    l.insertFront(3);
    l.insertEnd(6);
    l.print();

    l.insertAt(2, 5);
    l.print();

    l.deleteEnd();

    l.print();
}