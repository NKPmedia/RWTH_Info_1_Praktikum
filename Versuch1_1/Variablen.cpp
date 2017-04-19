//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	int iErste = 0;
	int iZweite = 0;

	std::cout << "Geben sie eine Zahl ein: ";
	std::cin >> iErste;
	std::cout << "Geben sie eine Zahl ein: ";
	std::cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;

	std::cout << "Die Summe ist: " << iSumme << std::endl;
	std::cout << "Der Quotient ist: " << iQuotient << std::endl;
	return 0;
	
}