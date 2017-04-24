/*
 * Add.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Add.h"
#include "expression.h"
#include <iostream>

Add::Add(Expression *left, Expression *right) : leftOperand(left), rightOperand(right)
{
}

double Add::evaluate() const
{
	return this->leftOperand->evaluate() + this->rightOperand->evaluate();
}

void Add::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " + ";
	this->rightOperand->print();
	std::cout << ")";
}
