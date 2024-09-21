#include "gtest/gtest.h"
#include "../include/llist.h"
#include <stdexcept>

class LListTestSuite : public ::testing::Test {
protected:
    LList<int> emptyList;
    LList<int> singleElementList;
    LList<int> multiElementList;

    void SetUp() override {
        singleElementList.insertEnd(1);

        multiElementList.insertEnd(1);
        multiElementList.insertEnd(2);
        multiElementList.insertEnd(3);
    }
};

TEST_F(LListTestSuite,InitialState) {
    EXPECT_EQ(multiElementList.getSize(),3);
    EXPECT_EQ(multiElementList.getHead()->val,1);
    EXPECT_EQ(multiElementList.getNode(1)->val,2);
    EXPECT_EQ(multiElementList.getTail()->val,3);

    EXPECT_EQ(multiElementList.getHead()->next->val, 2);
    EXPECT_EQ(multiElementList.getHead()->next->next->val, 3);
    EXPECT_EQ(multiElementList.getTail()->next, nullptr);
}

TEST_F(LListTestSuite, InsertFront) {
    LList<char> charLList;
    charLList.insertFront('a');
    EXPECT_EQ(charLList.getHead()->val, 'a');
    EXPECT_EQ(charLList.getTail()->val, 'a');
    EXPECT_EQ(charLList.getSize(), 1);

    charLList.insertFront('b');
    EXPECT_EQ(charLList.getHead()->val, 'b');
    EXPECT_EQ(charLList.getHead()->next->val, 'a');
    EXPECT_EQ(charLList.getSize(), 2);

    multiElementList.insertFront(0);
    EXPECT_EQ(multiElementList.getHead()->val, 0);
    EXPECT_EQ(multiElementList.getHead()->next->val, 1);
    EXPECT_EQ(multiElementList.getSize(), 4);
    EXPECT_EQ(multiElementList.getTail()->val, 3);
}

TEST_F(LListTestSuite, AssignmentOperator) {
    LList<int> assigned = multiElementList;
    EXPECT_EQ(assigned.getSize(), multiElementList.getSize());
    for (int i = 0; i < assigned.getSize(); ++i) {
        EXPECT_EQ(assigned.getHead()->val, multiElementList.getHead()->val);
        assigned.deleteFront();
        multiElementList.deleteFront();
    }
}

TEST_F(LListTestSuite,InsertAt) {
    multiElementList.insertAt(0,9);
    multiElementList.insertAt(multiElementList.getSize(), 9);
    multiElementList.insertAt(2,9);
    EXPECT_EQ(multiElementList.getSize(),6);
    EXPECT_EQ(multiElementList.getHead()->val,9);
    EXPECT_EQ(multiElementList.getTail()->val,9);
    EXPECT_EQ(multiElementList.getNode(2)->val,9);
}

TEST_F(LListTestSuite,DeleteFront) {
    multiElementList.deleteFront();
    multiElementList.deleteFront();
    multiElementList.deleteFront();
    EXPECT_EQ(multiElementList.getHead(),multiElementList.getTail());
    EXPECT_EQ(multiElementList.getSize(),0);
}

TEST_F(LListTestSuite,DeleteEnd) {
    multiElementList.deleteEnd();
    EXPECT_EQ(multiElementList.getTail()->val,2);
    EXPECT_EQ(multiElementList.getSize(),2);
}

TEST_F(LListTestSuite, CopyConstructor) {
    LList<int> copy(multiElementList);
    EXPECT_EQ(copy.getSize(), multiElementList.getSize());

    const Node<int>* origNode = multiElementList.getHead();
    const Node<int>* copyNode = copy.getHead();
    while (origNode != nullptr) {
        EXPECT_EQ(copyNode->val, origNode->val);
        origNode = origNode->next;
        copyNode = copyNode->next;
    }

    multiElementList.insertFront(0);
    EXPECT_EQ(copy.getSize(), 3);
    EXPECT_EQ(copy.getHead()->val, 1);
}

TEST_F(LListTestSuite, DeleteAt) {
    multiElementList.deleteAt(1);
    EXPECT_EQ(multiElementList.getSize(), 2);
    EXPECT_EQ(multiElementList.getHead()->next->val, 3);

    multiElementList.deleteAt(0);
    EXPECT_EQ(multiElementList.getHead()->val, 3);
    EXPECT_EQ(multiElementList.getTail()->val, 3);
    EXPECT_EQ(multiElementList.getSize(), 1);

    multiElementList.deleteAt(0);
    EXPECT_EQ(multiElementList.getSize(), 0);
    EXPECT_EQ(multiElementList.getHead(), nullptr);
    EXPECT_EQ(multiElementList.getTail(), nullptr);
}

