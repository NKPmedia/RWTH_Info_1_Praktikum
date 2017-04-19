///@file Complex.cpp
//
// Praktikum Informatik 1 SS2017
// Testprogramm_Eclipse_Doxygen:
// Versuch00: Vorbereitung auf Praktikum
//
// Datei:  Complex.cpp
// Inhalt: Implementierungsdatei
//



#include <iostream>
#include "Complex.h"

/**
 *  @brief Konstruktor 1.
 *  Realteil mit 0.0 initialisiert.
 *  Imaginaerteil mit 0.0 initialisiert.
 */
Complex::Complex()
{
	real = 0.0;
	imag = 0.0;
}

/**
 *  @brief Konstruktor 2
 *  @param r - initialisiert Membervariable real
 *  @param i - initialisiert Membervariable imag
 */
Complex::Complex (double r, double i)
{
	real = r;
	imag = i;
}

/**
 *  @brief Addition zweier komplexer Zahlen.
 *  Ueberladen von Operator "+".
 *  @param c2 rechter Operand
 */
Complex Complex::operator+(Complex c2)
{
   return Complex(real + c2.real, imag + c2.imag);
}

/**
 *  @brief Ausgabe einer komplexen Zahl
 *  @param output - Ausgabestream
 */
std::ostream& Complex::print(std::ostream& output)
{
	output << "(" << real << "+" << imag << "i)" << std::endl;
	return output;
}

/**
 * @brief Globale Ueberladung des Ausgabeoperators fuer die Klasse Complex
 * @param output - Ausgabestream
 * @param c - Komplexe Zahl, die mittels der print()-Funktion ausgegeben werden soll
 */
std::ostream& operator<<(std::ostream& output, Complex& c)
{
	return c.print(output);
}


