/*
 * Result.h
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#ifndef VERSUCH8_SOURCE_RESULT_H_
#define VERSUCH8_SOURCE_RESULT_H_

#include "expression.h"

class Result : public Expression
{
public:
	Result(Expression *expression);
	~Result();
	virtual double evaluate() const; // calculates and returns the value of expression
	virtual void print() const; // returns the mathematical expression as string

private:
	Expression *expression;
};

#endif /* VERSUCH8_SOURCE_RESULT_H_ */
