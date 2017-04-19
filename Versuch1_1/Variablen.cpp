//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>


void aufgabe1_3();
void aufgabe4_6_7();
void aufgabe5();
int getPosition(char);


int main()
{
	return 0;

}

/*!
 * @return
 *
 * @brief Lösung zur Aufgabe 5
 */
void aufgabe5()
{
	int iFeld[2] = {1,2};
	/*
	 * Die Werte kann man über 0 und 1 erreichen.
	 */
	int spielfeld[2][3] = {{1,2,3},
						   {4,5,6}};
	/*
	 * Die Elemente kann man über 0 bis 1 in der ersten und 0 bis 2 in der zweien Klammer erreichen.
	 * Bsp. spielfeld[1][0] oder spielfeld[0][2]
	 */

	std::cout << iFeld[0];
	std::cout << iFeld[1] << std::endl;

	for(int i = 0; i < 2 ; i++)
	{
		for(int j = 0; j < 3 ; j++)
		{
			std::cout << spielfeld[i][j];
		}
	}

	// !!!Besserer Weg!!!

	std::cout << std::endl;
	std::array<std::array<int,3>,2> spielfeld2 = {{{1,2,3}, {4,5,6}}};

	for(const auto& array : spielfeld2)
	{
		for(const auto& feld : array)
		{
			std::cout << feld;
		}
	}
}

/*!
 * @return
 *
 * @brief Lösung zur Aufgabe 4
 */
void aufgabe4_6_7()
{
	std::string sVorname = "";
	std::string sNachname = "";

	std::cout << "Geben sie ihren Vorname ein: ";
	std::cin >> sVorname;
	std::cout << "Geben sie ihren Nachnamen: ";
	std::cin >> sNachname;

	std::string sVornameNachname = sVorname + " " + sNachname;
	std::string sNachnameVorname = sNachname + ", " + sVorname;

	std::cout << sNachnameVorname << std::endl;
	std::cout << sVornameNachname << std::endl;

	int iName1 = sNachname[0];
	int iName2 = sNachname[1];
	std::cout << getPosition(sNachname[0]) << std::endl;
	std::cout << getPosition(sNachname[1]) << std::endl;
}

/*!
 * @brief Gibt die Position eines Buchstabens im Alphabet zurück
 * @param buchstabe
 * @return
 */
int getPosition(char buchstabe)
{
	if(buchstabe >= 97) return buchstabe - 96;
	else return buchstabe - 64;
}

/*!
 * @return
 *
 * @brief Lösung zur Aufgabe 1 bis 3
 */
void aufgabe1_3() {
	int iErste = 0;
	int iZweite = 0;

	std::cout << "Geben sie eine Zahl ein: ";
	std::cin >> iErste;
	std::cout << "Geben sie eine Zahl ein: ";
	std::cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;
	double dSummeCast = (double)iErste + (double)iZweite;
	double dQuotientCast = (double)iErste / (double)iZweite;

	std::cout << "Die Summe ist: " << iSumme << std::endl;
	std::cout << "Der Quotient ist: " << iQuotient << std::endl;
	std::cout << "Die Summe ist: " << dSumme << std::endl;
	std::cout << "Der Quotient ist: " << dQuotient << std::endl;
	std::cout << "Die Summe ist: " << dSummeCast << std::endl;
	std::cout << "Der Quotient ist: " << dQuotientCast << std::endl;

	/*
	 * Die Ergebnisse unterscheiden sich, da beid en Normalen Quotienten int Werte geteilt werden.
	 * Dadurch wird die Nachkommastelle abgeschnitten. Erst danach wird der Wert zu einem double umgewandelt.
	 * Ist aber min einer der Werte ein doubel so wird der andere auch zu diesem umgewandelt, bevor die Division
	 * ausgeführt wird und die Nachkommastelle wird berücksichtigt.
	 */
}
