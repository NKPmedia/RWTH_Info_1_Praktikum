/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 8: Taschenrechner
 *
 * Datei:  expression.h
 * Inhalt: Headerdatei Abstrakte Klasse Expression
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
	Expression();
	virtual ~Expression();
	virtual double evaluate() const = 0; // calculates and returns the value of expression
	virtual void print() const = 0; // returns the mathematical expression as string
};

#endif
