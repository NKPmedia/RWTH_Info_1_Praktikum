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

/**
 * @brief returns the product of left and right expression
 * @return the product of right and left
 */
double Mul::evaluate() const
{
	return this->leftOperand->evaluate() * this->rightOperand->evaluate();
}

/**
 * @brief prints a representation of the calculation to cout
 */
void Mul::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " * ";
	this->rightOperand->print();
	std::cout << ")";
}

Mul::~Mul()
{
	std::cout << "Deleted Mul" << std::endl;
}
