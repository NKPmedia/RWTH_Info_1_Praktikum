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
}

double Const::evaluate() const
{
	return this->value;
}
void Const::print() const
{
	std::cout << this->value;
}
