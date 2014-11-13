#include "gtest/gtest.h"
#include "CarTest.h"

TEST(TestCar, destructor)
{
    Car* wagen = new Car("Tesla Model S", "rubber", 19, 5);
    EXPECT_EQ(wagen->getAantalWheelen(), 5);
    delete wagen;
    // Wheel is deleted so shouldn't point to diameter 19.
    // How else to test this?
    EXPECT_NE(wagen->getWheel(1)->getDiameter(), 19);
}

TEST(TestCar, copy_constructor)
{
    Car wagen("Tesla Model S", "rubber", 19, 5);
    Car wagen2(wagen);
    //Test if copy
    EXPECT_EQ(wagen2.getAantalWheelen(), wagen.getAantalWheelen());
    // Test if deep copy
    EXPECT_NE(wagen2.getWheel(2), wagen.getWheel(2));
}

TEST(TestCar, operator_assign)
{
    Wheel* w1;
    {
        Car wagen("Tesla Model S", "rubber", 19, 5);
        Car wagen2("Tesla Model S2", "rubber", 19, 5);

        Wheel* w1 = wagen.getWheel(0);
        wagen = wagen2;

        //Test if copy
        EXPECT_EQ(wagen.getType(), "Tesla Model S2");
        //Test if deep copy
        Wheel* w2 = wagen2.getWheel(0);
        EXPECT_NE(wagen.getWheel(0), w2);
    }
    //Test if old wiel is gone
	// How else to test this?
    EXPECT_NE(w1->getDiameter(), 19);
}
