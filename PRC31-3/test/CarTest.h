#ifndef WAGENTEST_H_
#define WAGENTEST_H_

#include "Car.h"

class CarTest : public ::testing::Test {
protected:
	Car wagen;
};


#endif /* WAGENTEST_H_ */
