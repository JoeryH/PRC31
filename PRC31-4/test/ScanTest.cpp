#include "gtest/gtest.h"
#include "Scan.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Everything else tested in ScanListTest */

class ScanTest : public ::testing::Test {

};

TEST(TestScan, getter)
{
    Scan * test = new Scan(100);
    EXPECT_EQ(test->getTimesRecycled(), 1);
    test->recycle();
    test->recycle();
    EXPECT_EQ(test->getTimesRecycled(), 3);

    EXPECT_EQ(test->getSerialNumber(), 100);
}
