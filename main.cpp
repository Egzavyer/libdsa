#include <iostream>
#include "include/darray.h"
#include "include/llist.h"

int main()
{
    DArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.print();

    arr.insert(arr.getSize(),4);
    arr.print();
    arr.insert(1,6);
    arr.print();

}