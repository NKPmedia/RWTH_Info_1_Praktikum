/*
 * Div.h
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#ifndef VERSUCH8_SOURCE_DIV_H_
#define VERSUCH8_SOURCE_DIV_H_

#include "expression.h"

class Div : public Expression
{
public:
	Div(Expression *left , Expression *right);
	virtual ~Div();
	virtual double evaluate() const; // calculates and returns the value of expression
	virtual void print() const;

private:
	Expression *leftOperand;
	Expression *rightOperand;
};

#endif /* VERSUCH8_SOURCE_DIV_H_ */
