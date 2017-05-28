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
 * @brief lame test function that tests the vector class
 * @return returns true if every test passed, false if not
 */
bool lametestFunction()
{
	{
		Vector vecotr1(1,2,3);
		Vector vector2(1,1,1);

		Vector add = vecotr1.add(vector2);
		if(!add.hasValues(2,3,4)) return false;
	}

	{
		Vector vecotr1(1,2,3);
		Vector vector2(1,1,1);

		Vector sub = vecotr1.sub(vector2);
		if(!sub.hasValues(0,1,2)) return false;
	}

	{
		Vector vecotr1(0,1,0);
		Vector vector2(0,0,1);

		if(!vecotr1.ortho(vector2)) return false;
	}

	{
		Vector vecotr1(0,1,0);
		Vector vector2(0,0,1);

		double angle = vecotr1.angle(vector2);

		if(angle != M_PI/2) return false;
	}

	{
		Vector vecotr1(0,1,3);
		Vector vector2(0,2,-1);

		double scalar = vecotr1.scalarProd(vector2);

		if(scalar != -1.0) return false;
	}

	{
		Vector vecotr1(0,1,3);
		double length = vecotr1.length();

		if(length != 3.1622776601683795) return false;
	}

	{
		Vector vecotr1(0,1,6);
		Vector result = vecotr1.rotZ(M_PI/2);

		if(result.getX() != -1)return false;
		if(result.getY() != 6.123233995736766e-17)return false;
		if(result.getZ() != 6)return false;
	}

	return true;
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
 * Better implementation with angle
 *
 * @return
 */
int main(int argc, char **argv)
{
	if(TEST)
	{
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();

		if(!lametestFunction())
		{
			std::cout << "Fehler!" << std::endl;
		}
		else
		{
			std::cout << "Alles gut!" << std::endl;
		}
	}

	double earthAngle = -(1.0/10000);
	int steps = 0;

	Vector person(0,501.8,0);
	Vector earth(0,6371000,0);
	Vector eye = earth.add(person);

	Vector view = eye.sub(earth);
	int viewLength = 1;


	//Until the angle is bigger than 90 degree
	while(earth.angleInDegree(view) <= 90)
	{
		viewLength = view.length();

		//Creates new earth vector and rotates it
		earth = Vector(0,6371000,0);
		earth = earth.rotZInDegree(earthAngle);

		view = eye.sub(earth);
		earthAngle -= (1.0/10000);

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


