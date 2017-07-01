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

/**
 * @brief returns the sum of left and right expression
 * @return the sum of right and left
 */
double Add::evaluate() const
{
	return this->leftOperand->evaluate() + this->rightOperand->evaluate();
}

/**
 * @brief prints a representation of the calculation to cout
 */
void Add::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " + ";
	this->rightOperand->print();
	std::cout << ")";
}

Add::~Add()
{
	std::cout << "Deleted Add" << std::endl;
}
