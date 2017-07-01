/*
 * Const.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Const.h"
#include "expression.h"
#include <iostream>

Const::Const(double value) : value(value)
{
}

Const::~Const()
{
	std::cout << "Deleted Const" << std::endl;
}

/**
 * @brief returns value of the const
 * @return the sum of right and left
 */
double Const::evaluate() const
{
	return this->value;
}

/**
 * @brief prints a representation of the calculation to cout
 */
void Const::print() const
{
	std::cout << this->value;
}
