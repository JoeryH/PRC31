#include "gtest/gtest.h"
#include "WielTest.h"

TEST(TestWiel, setMateriaal)
{
    Wiel wiel(10, "rubber");
    EXPECT_EQ(wiel.getMateriaal(), "rubber");
    wiel.setMateriaal("plastic");
    EXPECT_EQ(wiel.getMateriaal(), "plastic");
}
