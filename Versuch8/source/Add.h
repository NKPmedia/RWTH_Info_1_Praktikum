/*
 * Add.h
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#ifndef VERSUCH8_SOURCE_ADD_H_
#define VERSUCH8_SOURCE_ADD_H_

#include "expression.h"

class Add : public Expression
{
public:
	Add(Expression *left , Expression *right);
	virtual ~Add();
	virtual double evaluate() const; // calculates and returns the value of expression
	virtual void print() const;

private:
	Expression *leftOperand;
	Expression *rightOperand;
};

#endif /* VERSUCH8_SOURCE_ADD_H_ */
