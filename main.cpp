#include <iostream>
#include "include/darray.h"
#include "include/llist.h"

int main()
{
    LList<int> l;
    l.insertAt(0,1);
    l.insertAt(1,2);
    l.insertAt(1,3);
    l.print();

    l.deleteAt(1);
    l.print();
}