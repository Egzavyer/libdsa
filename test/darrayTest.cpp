#include "gtest/gtest.h"
#include "../include/darray.h"
#include <stdexcept>

class DArrayTestSuite : public ::testing::Test {
protected:
    void SetUp() override {
        intArray.append(1);
        intArray.append(2);
        intArray.append(3);
    }

    DArray<int> intArray;
    DArray<std::string> stringArray;
};

TEST_F(DArrayTestSuite, InitialState) {
    EXPECT_EQ(intArray.getSize(),3);
    EXPECT_EQ(intArray.getCapacity(),4);
}

TEST_F(DArrayTestSuite,AppendToFullArray) {
    intArray.append(4);
    EXPECT_EQ(intArray.getSize(), 4);
    EXPECT_EQ(intArray.getCapacity(), 8);
    EXPECT_EQ(intArray[3], 4);
}

TEST_F(DArrayTestSuite, StringOperations) {
    stringArray.append("Hello");
    stringArray.append("World");
    EXPECT_EQ(stringArray.getSize(), 2);
    EXPECT_EQ(stringArray.getCapacity(), 4);
    EXPECT_EQ(stringArray[0], "Hello");
    EXPECT_EQ(stringArray[1], "World");
}

TEST_F(DArrayTestSuite, InsertAtBoundaries) {
    intArray.insert(0, 0);
    EXPECT_EQ(intArray[0], 0);
    EXPECT_EQ(intArray.getSize(), 4);

    intArray.insert(intArray.getSize(), 4);
    EXPECT_EQ(intArray[intArray.getSize() - 1], 4);
    EXPECT_EQ(intArray.getSize(), 5);
}

TEST_F(DArrayTestSuite, RemoveFromBoundaries) {
    intArray.remove(0);
    EXPECT_EQ(intArray[0], 2);
    EXPECT_EQ(intArray.getSize(), 2);

    intArray.remove(intArray.getSize() - 1);
    EXPECT_EQ(intArray.getSize(), 1);
    EXPECT_EQ(intArray[0], 2);
}

TEST_F(DArrayTestSuite, AppendPerformance) {
    constexpr int n = 100000;
    const auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
        intArray.append(i);
    }

    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to append " << n << " elements: " << duration.count() << " milliseconds" << std::endl;

    EXPECT_LT(duration.count(), 1000);
}

TEST_F(DArrayTestSuite, ExceptionSafety) {
    EXPECT_THROW({
        try {
            intArray.remove(10);
        } catch(const std::out_of_range& e) {
            EXPECT_EQ(intArray.getSize(), 3);
            EXPECT_EQ(intArray[2], 3);
            throw;
        }
    }, std::out_of_range);

    EXPECT_THROW({
        try {
            intArray.insert(10,9);
        }catch (const std::out_of_range& e) {
            EXPECT_EQ(intArray.getSize(),3);
            throw;
        }
    },std::out_of_range);
}

TEST_F(DArrayTestSuite, PrintMethod) {
    testing::internal::CaptureStdout();
   std::cout << intArray;
    const std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Capacity: 4") != std::string::npos);
    EXPECT_TRUE(output.find("Size: 3") != std::string::npos);
    EXPECT_TRUE(output.find("[1,2,3]") != std::string::npos);
}

TEST_F(DArrayTestSuite, CopyConstructor) {
    DArray<int> otherDArray(intArray);
    EXPECT_EQ(otherDArray.getSize(),intArray.getSize());
    for (size_t i = 0; i < otherDArray.getSize(); ++i) {
        EXPECT_EQ(otherDArray[i], intArray[i]);
    }
}

TEST_F(DArrayTestSuite, AssignmentOperator) {
    DArray<int> assigned = intArray;
    EXPECT_EQ(assigned.getSize(), intArray.getSize());
    for (int i = 0; i < assigned.getSize(); ++i) {
        EXPECT_EQ(assigned[i], intArray[i]);
    }
}



