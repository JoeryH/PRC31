#include "gtest/gtest.h"
#include "WagenTest.h"

TEST(TestWagen, destructor)
{
    Wagen* wagen = new Wagen("Tesla Model S", "rubber", 19, 5);
    EXPECT_EQ(wagen->getAantalWielen(), 5);
    delete wagen;
    // Wiel is deleted so shouldn't point to diameter 19.
    // How else to test this?
    EXPECT_NE(wagen->getWiel(1)->getDiameter(), 19);
}

TEST(TestWagen, copy_constructor)
{
    Wagen wagen("Tesla Model S", "rubber", 19, 5);
    Wagen wagen2(wagen);
    //Test if copy
    EXPECT_EQ(wagen2.getAantalWielen(), wagen.getAantalWielen());
    // Test if deep copy
    EXPECT_NE(wagen2.getWiel(2), wagen.getWiel(2));
}

TEST(TestWagen, operator_assign)
{
    Wiel* w1;
    {
        Wagen wagen("Tesla Model S", "rubber", 19, 5);
        Wagen wagen2("Tesla Model S2", "rubber", 19, 5);

        Wiel* w1 = wagen.getWiel(0);
        wagen = wagen2;

        //Test if copy
        EXPECT_EQ(wagen.getType(), "Tesla Model S2");
        //Test if deep copy
        Wiel* w2 = wagen2.getWiel(0);
        EXPECT_NE(wagen.getWiel(0), w2);
    }
    //Test if old wiel is gone
	// How else to test this?
    EXPECT_NE(w1->getDiameter(), 19);
}
