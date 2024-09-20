#include "gtest/gtest.h"
#include "../include/llist.h"
#include <stdexcept>

class LListTestSuite : public ::testing::Test {
protected:
    void SetUp() override {
        intLList.insertEnd(1);
        intLList.insertEnd(2);
        intLList.insertEnd(3);
    }
    LList<int> intLList;
};

TEST_F(LListTestSuite,InitialState) {
    EXPECT_EQ(intLList.getSize(),3);
    EXPECT_EQ(intLList.getHead()->val,1);
    EXPECT_EQ(intLList.getTail()->val,3);
}

TEST_F(LListTestSuite, InsertFront) {
    intLList.insertFront(0);
    EXPECT_EQ(intLList.getHead()->val,0);
    EXPECT_EQ(intLList.getSize(),4);
    EXPECT_EQ(intLList.getTail()->val,3);
}

TEST_F(LListTestSuite, AssignmentOperator) {
    LList<int> assigned = intLList;
    EXPECT_EQ(assigned.getSize(), intLList.getSize());
    for (int i = 0; i < assigned.getSize(); ++i) {
        EXPECT_EQ(assigned.getHead()->val, intLList.getHead()->val);
        assigned.deleteFront();
        intLList.deleteFront();
    }
}

