//
// Praktikum Informatik 1 SS2017
// Testprogramm_Eclipse_Doxygen:
// Versuch00: Vorbereitung auf Praktikum
//
// Datei:  Complex.h
// Inhalt: Headerdatei
//

/**
 * Complex - Basisklasse fuer komplexe Zahlen.<BR>
 * Klasse fuer komplexe Zahlen mit Real- und
 * Imaginaerteil als double-Werte.
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex
{
	public:
		Complex();
		Complex (double r, double i);

		Complex operator+(Complex c2);
		std::ostream& print(std::ostream& output);

	private:
		double real;	//! Realteil
		double imag;	//! Imaginaerteil
};

std::ostream& operator<<(std::ostream& output, Complex& c);


#endif /* COMPLEX_H_ */
