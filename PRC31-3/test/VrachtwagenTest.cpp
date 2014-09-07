#include "gtest/gtest.h"
#include "VrachtwagenTest.h"

TEST(TestVrachtwagen, destructor)
{
    Vrachtwagen* wagen = new Vrachtwagen("Tesla Model S", "rubber", 19, 5, 100);
    EXPECT_EQ(wagen->getVermogen(), 100);
    delete wagen;
    // Vermogen is deleted so shouldn't point to 100.
    // How else to test this?
    EXPECT_NE(wagen->getVermogen(), 100);
}

TEST(TestVrachtwagen, copy_constructor)
{
    Vrachtwagen wagen("Tesla Model S", "rubber", 19, 5, 100);
    Vrachtwagen wagen2(wagen);
    //Test if copy
    EXPECT_EQ(wagen2.getVermogen(), wagen.getVermogen());
    // Deep copy cant be tested for vermogen because vermogen is not editable nor the pointer can be retrieved.
    // Test if deep copy
    EXPECT_NE(wagen2.getWiel(2), wagen.getWiel(2));
}

TEST(TestVrachtwagen, operator_assign)
{
	Wiel* w1;
	{
		Vrachtwagen wagen("Tesla Model S", "rubber", 19, 5, 80);
		Vrachtwagen wagen2("Tesla Model S", "rubber", 19, 5, 100);

		Wiel* w1 = wagen.getWiel(0);
		wagen = wagen2;

		//Test if copy
		EXPECT_EQ(wagen.getVermogen(), 100);
		//Test if deep copy
		Wiel* w2 = wagen2.getWiel(0);
		EXPECT_NE(wagen.getWiel(0), w2);
	}
	//Test if old wiel is gone
	// How else to test this?
    EXPECT_NE(w1->getDiameter(), 19);
}

