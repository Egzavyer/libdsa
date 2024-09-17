#include "gtest/gtest.h"
#include "../include/darray.h"

TEST (DArrayTestSuite,GetSize) {
    DArray<int> arr;
    EXPECT_EQ(arr.getSize(),0);
}