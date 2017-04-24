/*
 * Mul.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Mul.h"
#include "expression.h"
#include <iostream>

Mul::Mul(Expression *left, Expression *right) : leftOperand(left), rightOperand(right)
{
}

double Mul::evaluate() const
{
	return this->leftOperand->evaluate() * this->rightOperand->evaluate();
}

void Mul::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " * ";
	this->rightOperand->print();
	std::cout << ")";
}
