//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 2_3
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>

/*!
 * @brief Gibt den zugewiesenen Buchstaben zurück
 * @param c zu suchender Buchstabe
 * @param lookUpTable die zu benutzende lookUpTable
 */
char getCharFromTable(char c,std::array<std::array<char, 26>, 2> lookUpTable)
{
	//Position bestimmen
	int pos = c  - 65;

	//Buchstabe von A - Z => dazugehörigen Buchstaben ausgeben
	if(pos >= 0 && pos < 26) return lookUpTable[1][pos];
	else  throw std::invalid_argument("Not a char of A - Z");
}

/*!
 * @brief Gibt den andersrum zugewiesenen Buchstaben zurück
 * @param c zu suchender Buchstabe
 * @param lookUpTable die zu benutzende lookUpTable
 */
char getCharFromTableReverse(char c,std::array<std::array<char, 26>, 2> lookUpTable)
{
	//Position im Alphabet bestimmen
	int posInAlphabet = c  - 65;

	//Buchstabe von A - Z
	if(posInAlphabet >= 0 && posInAlphabet < 26)
	{
		//Suche Position
		int pos = 0;
		for(auto& cl : lookUpTable[1])
		{
			//Wenn richtiger Buchstabe gefunden => Gebe dazugehörigen aus
			if(cl == c) return lookUpTable[0][pos];
			pos++;
		}
	}
	throw std::invalid_argument("Not a char of A - Z");
}

/*!
 * Main Methode
 *
 * Nimmt ein Wort und verschlüsselt bzw. entschlüsselt es
 */
int main ()
{
	//LookUpTable erstellen
	std::array<std::array<char, 26>, 2> lookUpTable = {{{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
														{'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}}};

	std::string word = "";

	//Wort eingeben lassen
	std::cout << "Gib ein Wort ein " << std::endl;
	std::cin >> word;

	//Wort verschlüsseln
	for(char& c : word)
	{
		std::cout << getCharFromTable(c,lookUpTable);
	}

	std::cout << std::endl;

	std::string word2 = "";

	//Wort eingeben lassen
	std::cout << "Gib ein verschlüsseltes Wort ein " << std::endl;
	std::cin >> word2;
	//Wort verschlüsseln
	for(char& c : word2)
	{
		std::cout << getCharFromTableReverse(c,lookUpTable);
	}

	return 0;
}
