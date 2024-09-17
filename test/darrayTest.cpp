#include "gtest/gtest.h"
#include "../include/darray.h"
#include <stdexcept>

TEST (DArrayTestSuite,GetSize) {
    DArray<int> arr;
    EXPECT_EQ(arr.getSize(),0);
}

TEST (DArrayTestSuite,GetCapacity) {
    DArray<int> arr;
    EXPECT_EQ(arr.getCapacity(),1);
}

TEST (DArrayTestSuite,IsEmpty) {
    DArray<int> arr;
    EXPECT_EQ(arr.isEmpty(),true);
}

TEST (DArrayTestSuite,Append) {
    DArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    EXPECT_EQ(arr[2],3);
    EXPECT_EQ(arr.getCapacity(),4);
    EXPECT_EQ(arr.getSize(),3);
}

TEST (DArrayTestSuite,Pop) {
    DArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.pop();
    arr.pop();
    EXPECT_EQ(arr.getCapacity(),1);
    EXPECT_EQ(arr.getSize(),0);
}

TEST (DArrayTestSuite,Insert) {
    DArray<int> arr;
    arr.insert(0,1);
    arr.insert(0,2);
    EXPECT_EQ(arr.getCapacity(),2);
    EXPECT_EQ(arr.getSize(),2);
    EXPECT_EQ(arr[1],1);
}

TEST (DArrayTestSuite,Remove) {
    DArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);
    arr.remove(1);
    arr.remove(1);
    EXPECT_EQ(arr.getCapacity(),4);
    EXPECT_EQ(arr.getSize(),3);
    EXPECT_EQ(arr[0],1);
}
