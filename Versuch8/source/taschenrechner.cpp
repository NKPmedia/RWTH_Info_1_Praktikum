/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 08: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include "expression.h"
#include "Const.h"
#include "Result.h"
#include "Add.h"
#include "Mul.h"
#include "Sub.h"
#include "Div.h"

/**
 * @brief tests the const class
 */
void testConst()
{
	Const c(4);
	c.print();
	std::cout << " = " << c.evaluate() << std::endl;
}

/**
 * @brief tests the Result class
 */
void testResult()
{
	Result res ( new Const(4) );
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief tests the Add and Const class
 */
void testAddConst()
{
	Result res (new Add (
				new Const(7),
				new Const(8)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief tests the Mul Add and Cost class
 */
void testMulAddConst()
{
	Result res (	new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Const(5)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief tests the Sub Mul Add and Const class
 */
void testSubMulAddConst()
{
	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Const(2)
						)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}


/**
 * @brief tests all classes
 */
void finalTest()
{



	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Div (
								new Const(10),
								new Const(5)
								)
							)
						)
					)
		   );

	res.print();
	std::cout << " = ";
	std::cout << res.evaluate();
	std::cout << std::endl;

// Das Ergebnis sollte etwa so aussehen:
// (4 + (9 * (7 - (10 / 5)))) = 49

}

/**
 * @brief test the classes
 * @return
 */
int main()
{
	// Implementieren Sie zuerst die Klassen Const und Result und testen Sie das Ergebnis.
	testConst();
	testResult();
	
	// Erg�nzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	testAddConst();
	testMulAddConst();
	testSubMulAddConst();
	std::cout << "Der finale Test: kommt noch..." << std::endl;
	finalTest();

	return 0;
}

