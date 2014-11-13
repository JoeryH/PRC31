#include "gtest/gtest.h"
#include "WheelTest.h"

TEST(TestWheel, setMateriaal)
{
    Wheel wiel(10, "rubber");
    EXPECT_EQ(wiel.getMateriaal(), "rubber");
    wiel.setMateriaal("plastic");
    EXPECT_EQ(wiel.getMateriaal(), "plastic");
}
