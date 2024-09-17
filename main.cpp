#include <iostream>
#include "include/list.h"

int main()
{
    List<int> arr(1);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.print();

    arr.pop();
    arr.pop();
    arr.print();

    arr.insert(1, 5);
    arr.print();

    arr.remove(1);
    arr.print();
}