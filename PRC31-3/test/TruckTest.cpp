#include "gtest/gtest.h"
#include "TruckTest.h"

TEST(TestTruck, destructor)
{
    Truck* wagen = new Truck("Tesla Model S", "rubber", 19, 5, 100);
    EXPECT_EQ(wagen->getVermogen(), 100);
    delete wagen;
    // Vermogen is deleted so shouldn't point to 100.
    // How else to test this?
    EXPECT_NE(wagen->getVermogen(), 100);
}

TEST(TestTruck, copy_constructor)
{
    Truck wagen("Tesla Model S", "rubber", 19, 5, 100);
    Truck wagen2(wagen);
    //Test if copy
    EXPECT_EQ(wagen2.getVermogen(), wagen.getVermogen());
    // Deep copy cant be tested for vermogen because vermogen is not editable nor the pointer can be retrieved.
    // Test if deep copy
    EXPECT_NE(wagen2.getWheel(2), wagen.getWheel(2));
}

TEST(TestTruck, operator_assign)
{
	Wheel* w1;
	{
		Truck wagen("Tesla Model S", "rubber", 19, 5, 80);
		Truck wagen2("Tesla Model S", "rubber", 19, 5, 100);

		Wheel* w1 = wagen.getWheel(0);
		wagen = wagen2;

		//Test if copy
		EXPECT_EQ(wagen.getVermogen(), 100);
		//Test if deep copy
		Wheel* w2 = wagen2.getWheel(0);
		EXPECT_NE(wagen.getWheel(0), w2);
	}
	//Test if old wiel is gone
	// How else to test this?
    EXPECT_NE(w1->getDiameter(), 19);
}

