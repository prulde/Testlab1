#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

// Подробнее https://google.github.io/googletest/reference/testing.html

class LR1T : public ::testing::Test {
protected:
    void SetUp() override {
        arr = {10, 14, 15, 20, 21, 25, 30};
    }

    void TearDown() override {  
        arr.clear();
    }

    std::vector<int> arr;
};

TEST_F(LR1T, CTest1) {
    Res output = countAndSum(arr);

    std::vector<int> outputTest = { 31, 39, 45, 40 };
    EXPECT_EQ(output.min, 31);
    EXPECT_EQ(output.result, outputTest);
}

TEST_F(LR1T, Path2) {
    std::vector<int> out = { 62 };
    std::vector<int> in = { 31 };
    Res output = countAndSum(in);
    if(output.sizeChanged)
        EXPECT_EQ(output.min, 62);
    EXPECT_EQ(output.result, out);
}

TEST(CountAndSumTest1, CTest3) {
    std::vector<int> arr2;
    arr2 = {10, 14, 15, 20, 21, 25, 30, 35, 5};
    Res output = countAndSum(arr2);
    std::vector<int> outputTest = { 35,44,50,25,42 };
    EXPECT_EQ(output.min, 25);
    EXPECT_EQ(output.result, outputTest);
}