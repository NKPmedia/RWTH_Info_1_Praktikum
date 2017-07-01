/*
 * Mul.h
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#ifndef VERSUCH8_SOURCE_MUL_H_
#define VERSUCH8_SOURCE_MUL_H_

#include "expression.h"

class Mul : public Expression
{
public:
	Mul(Expression *left , Expression *right);
	virtual ~Mul();
	virtual double evaluate() const; // calculates and returns the value of expression
	virtual void print() const;

private:
	Expression *leftOperand;
	Expression *rightOperand;
};

#endif /* VERSUCH8_SOURCE_MUL_H_ */
