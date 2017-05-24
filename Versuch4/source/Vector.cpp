//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vector.cpp
// Inhalt: Sourcedatei der Klasse Vector
//////////////////////////////////////////////////////////////////////////////

#include "Vector.h"

#include <cmath>
#include <iostream>

Vector::Vector(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vector::~Vector()
{

}

/**
 * @brief calculates the angle between two vectors
 * @param input the input vector
 * @return the angle in rad
 */
double Vector::angle(const Vector& input) const
{
	return acos(this->scalarProd(input)/(this->length()*input.length()));
}

/**
 * @brief calculates the angle between two vectors
 * @param input the input vector
 * @return the angle in degree
 */
double Vector::angleInDegree(const Vector& input) const
{
	return acos(this->scalarProd(input)/(this->length()*input.length()))*180/M_PI;
}

/**
 * @brief test if two vectors are orthogonal
 * @param input another vector
 * @return true if they are orthogonal
 */
bool Vector::ortho(const Vector& input) const
{
	if(this->scalarProd(input) == 0) return true;
	else return false;
}

/**
 * @brief calculates the scalar product of this and another vector
 * @param input another vector
 * @return the scalar product
 */
double Vector::scalarProd(const Vector& input) const
{
	return this->getX() * input.getX() + this->getY() * input.getY() +this->getZ() * input.getZ();
}

/**
 * @brief subtracts a Vector from this one
 * @param input the subtrahend
 * @return a new vector with the result
 */
Vector Vector::sub(const Vector& input) const
{
	double x = this->getX() - input.getX();
	double y = this->getY() - input.getY();
	double z = this->getZ() - input.getZ();

	Vector v(x,y,z);

	return v;
}

/**
 * @brief adds a Vector to this one
 * @param input the summand
 * @return a new vector with the result
 */
Vector Vector::add(const Vector& input) const
{
	double x = this->getX() + input.getX();
	double y = this->getY() + input.getY();
	double z = this->getZ() + input.getZ();

	Vector v(x,y,z);

	return v;
}

/**
 * Calculates the length of the vector
 * @return the length in double
 */
double Vector::length() const
{
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));
}

/**
 * @brief returns the x attribute
 * @return x attribute
 */
double Vector::getX() const
{
	return this->x;
}

/**
 * @brief returns the y attribute
 * @return y attribute
 */
double Vector::getY() const
{
	return this->y;
}

/**
 * @brief returns the z attribute
 * @return z attribute
 */
double Vector::getZ() const
{
	return this->z;
}

/**
 * @brief prints the x,y,z values at std::cout
 */
void Vector::ausgabe() const
{
	std::cout << "Vector : " << std::endl;
	std::cout << "X : " << this->getX() << std::endl;
	std::cout << "Y : " << this->getY() << std::endl;
	std::cout << "Z : " << this->getZ() << std::endl;
}

/**
 * @brief checks if a vector has given x,y,z values
 * @param x
 * @param y
 * @param z
 * @return
 */
bool Vector::hasValues(int x, int y, int z) const
{
	if(x == this->getX() && y == this->getY() && z == this->getZ()) return true;
	return false;
}

/**
 * @brief rotates a vector around the Z axis
 * @param angle in radiant
 * @return new rotated vector
 */
Vector Vector::rotZ(double angle) const
{
	double x = cos(angle)*this->getX() -sin(angle)*this->getY();
	double y = sin(angle)*this->getX() +cos(angle)*this->getY();
	double z = this->getZ();

	return Vector(x,y,z);
}

/**
 * @brief rotates a vector around the Z axis
 * @param angle in Degree
 * @return new rotated vector
 */
Vector Vector::rotZInDegree(double angle) const
{
	double x = cos(angle/180*M_PI)*this->getX() -sin(angle/180*M_PI)*this->getY();
	double y = sin(angle/180*M_PI)*this->getX() +cos(angle/180*M_PI)*this->getY();
	double z = this->getZ();

	return Vector(x,y,z);
}
