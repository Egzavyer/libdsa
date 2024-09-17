#include <cassert>
#include <iostream>

#include "../include/darray.h"

int main()
{
    DArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);

    assert(arr.getCapacity() == 4);
    assert(arr.getSize() == 3);
    assert(arr[0] == 1);

    arr.insert(0, 4);
    arr.insert(1, 5);
    arr.insert(2, 6);
    arr.insert(3, 7);

    assert(arr.getCapacity() == 8);
    assert(arr.getSize() == 7);
    assert(arr[3] == 7);

    arr.pop();
    arr.pop();
    arr.pop();
    arr.remove(2);

    assert(arr.getCapacity() == 4);
    assert(arr.getSize() == 3);
    assert(arr[2] == 7);

    std::cout << "SUCCESS: no assertions failed\n";
}