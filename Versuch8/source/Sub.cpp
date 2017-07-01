/*
 * Sub.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Sub.h"
#include "expression.h"
#include <iostream>

Sub::Sub(Expression *left, Expression *right) : leftOperand(left), rightOperand(right)
{
}

/**
 * @brief returns the difference of left and right expression
 * @return the difference of right and left
 */
double Sub::evaluate() const
{
	return this->leftOperand->evaluate() - this->rightOperand->evaluate();
}

/**
 * @brief prints a representation of the calculation to cout
 */
void Sub::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " - ";
	this->rightOperand->print();
	std::cout << ")";
}

Sub::~Sub()
{
	std::cout << "Deleted Sub" << std::endl;
}
