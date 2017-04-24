/*
 * Result.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Result.h"
#include "expression.h"
#include <iostream>

Result::Result(Expression *expression) : expression(expression)
{
}

Result::~Result()
{
}

double Result::evaluate() const
{
	return this->expression->evaluate();
}
void Result::print() const
{
	this->expression->print();
}
