/*
 * Div.cpp
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#include "Div.h"
#include "expression.h"
#include <iostream>

Div::Div(Expression *left, Expression *right) : leftOperand(left), rightOperand(right)
{
}

double Div::evaluate() const
{
	return this->leftOperand->evaluate() / this->rightOperand->evaluate();
}

void Div::print() const
{
	std::cout << "(";
	this->leftOperand->print();
	std::cout << " / ";
	this->rightOperand->print();
	std::cout << ")";
}
