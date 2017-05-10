//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vector.h"
#include "config.h"
#include "../../googletest/include/gtest/gtest.h"
#include <unistd.h>

/**
 *
 * @param argc
 * @param argv
 *
 * This program starts the tests if TEST is 1
 * Then it calculates the distance a person is able to see if he stands on a 500m high tower
 *
 * @return
 */
int main2(int argc, char **argv)
{ 
	if(TEST)
	{
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}

	double earthAngle = -M_PI/10000;
	int steps = 0;

	Vector person(0,501.8,0);
	Vector earth(0,6371000,0);
	Vector eye = earth.add(person);

	Vector view(0,0,0);
	int viewLength = 1;
	//As long as the view vector is under the eye of the person
	while(view.getY() < eye.getY())
	{
		//Creates new earth vector and rotates it
		earth = Vector(0,6371000,0);
		earth = earth.rotZ(earthAngle);

		viewLength = 1;
		//As long as the view vector did not reach x = 0
		do{
			//Creates new view vector and rotates it
			view = Vector(-viewLength,0,0);
			view = view.rotZ(earthAngle);

			view = earth.add(view);

			//Prepare the next try
			viewLength++;
			steps++;
		}
		while(view.getX() > 0);
		earthAngle -= M_PI/10000;
	}

	std :: cout << std :: fixed ;

	std::cout << "Sie können so weit sehen: " << viewLength << std::endl;
	std::cout << "Sie sind so viel Meter hoch: " << eye.getY() << std::endl;
	std::cout << "Der Wingel beträgt: " << earthAngle << std::endl;
	std::cout << "Steps: " << steps << std::endl;

	/*
	 * Das Ergebniss ist in etwa 80066m bei 500m Höhe
	 * Ergebniss im Internet überprüft!
	 * Intenet Höhe = 8848 => 360km Blick
	 * Programm Höhe = 8848 => 336km Blick
	 */


	return 0;

}

/**
 *
 * @param argc
 * @param argv
 *
 * This program starts the tests if TEST is 1
 * Then it calculates the distance a person is able to see if he stands on a 500m high tower
 *
 * @return
 */
int main(int argc, char **argv)
{
	if(TEST)
	{
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}

	double earthAngle = -1/100000;
	int steps = 0;

	Vector person(0,501.8,0);
	Vector earth(0,6371000,0);
	Vector eye = earth.add(person);

	Vector view = eye.sub(earth);
	int viewLength = 1;
	//As long as the view vector is under the eye of the person
	std::cout << view.scalarProd(earth) << std::endl;
	while(view.scalarProd(earth) >= 0.01 || view.scalarProd(earth) <= -0.01)
	{
		viewLength = view.length();
		std::cout << view.scalarProd(earth) << std::endl;
		//Creates new earth vector and rotates it
		earth = Vector(0,6371000,0);
		earth = earth.rotZ(earthAngle);

		view = eye.sub(earth);
		earthAngle -= 1/100000;

		steps++;
	}

	std :: cout << std :: fixed ;

	viewLength = view.length();

	std::cout << "Sie können so weit sehen: " << viewLength << std::endl;
	std::cout << "Sie sind so viel Meter hoch: " << eye.getY() << std::endl;
	std::cout << "Der Wingel beträgt: " << earthAngle << std::endl;
	std::cout << "Steps: " << steps << std::endl;

	/*
	 * Das Ergebniss ist in etwa 80066m bei 500m Höhe
	 * Ergebniss im Internet überprüft!
	 * Intenet Höhe = 8848 => 360km Blick
	 * Programm Höhe = 8848 => 336km Blick
	 */


	return 0;

}
