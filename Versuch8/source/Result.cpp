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

/**
 * @brief returns result of the expression
 * @return the result
 */
double Result::evaluate() const
{
	return this->expression->evaluate();
}

/**
 * @brief prints a representation of the expressionn to cout
 */
void Result::print() const
{
	this->expression->print();
}
