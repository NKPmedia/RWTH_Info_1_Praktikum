/*
 * Const.h
 *
 *  Created on: 23.04.2017
 *      Author: paul
 */

#ifndef VERSUCH8_SOURCE_CONST_H_
#define VERSUCH8_SOURCE_CONST_H_

#include "expression.h"

class Const : public Expression
{
public:
	Const(double value);
	virtual ~Const();
	virtual double evaluate() const; // calculates and returns the value of expression
	virtual void print() const;

private:
	double value;
};

#endif /* VERSUCH8_SOURCE_CONST_H_ */
