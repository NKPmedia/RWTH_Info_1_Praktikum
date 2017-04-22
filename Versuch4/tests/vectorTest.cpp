#include "../../googletest/include/gtest/gtest.h"
#include "../source/Vector.h"
#include "cmath"

TEST(vector,vectorAdd) {

	Vector vecotr1(1,2,3);
	Vector vector2(1,1,1);

	Vector add = vecotr1.add(vector2);
	ASSERT_TRUE(add.hasValues(2,3,4));

}

TEST(vector,vectorSub) {
	Vector vecotr1(1,2,3);
	Vector vector2(1,1,1);

	Vector sub = vecotr1.sub(vector2);
	ASSERT_TRUE(sub.hasValues(0,1,2));

}

TEST(vector,vectorOrth) {

	Vector vecotr1(0,1,0);
	Vector vector2(0,0,1);

	ASSERT_TRUE(vecotr1.ortho(vector2));

}

TEST(vector,vectorAngle) {

	Vector vecotr1(0,1,0);
	Vector vector2(0,0,1);

	double angle = vecotr1.angle(vector2);

	ASSERT_DOUBLE_EQ(angle,M_PI/2);
}

TEST(vector,vectorScalar) {

	Vector vecotr1(0,1,3);
	Vector vector2(0,2,-1);

	double scalar = vecotr1.scalarProd(vector2);

	ASSERT_DOUBLE_EQ(scalar,-1.0);
}

TEST(vector,vectorLength) {

	Vector vecotr1(0,1,3);
	double length = vecotr1.length();

	EXPECT_DOUBLE_EQ(length,3.1622776601683795);
}

TEST(vector,vectorRotZ) {

	Vector vecotr1(0,1,6);
	Vector result = vecotr1.rotZ(M_PI/2);

	EXPECT_DOUBLE_EQ(result.getX(),-1);
	EXPECT_DOUBLE_EQ(result.getY(),6.123233995736766e-17);
	EXPECT_DOUBLE_EQ(result.getZ(),6);
}
