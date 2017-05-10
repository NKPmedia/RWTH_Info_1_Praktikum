/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 5: Dynamische Datenstrukturen
 *
 * *Die erklaerenden Texte wurden zum Teil von* wikipedia.org *uebernommen*@n
 * *Siehe hierzu die entsprechende* [Webseite][wikipedia].
 *
 * [wikipedia]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>

/**
 * @brief starts a UI the interact with a vecotr of students
 * @return
 */
int main()
{
	std::vector<Student> testvector;
	std::vector<Student>::iterator it;
	std::vector<Student>::reverse_iterator revIt;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    //Fills the vectors
    if (abfrage != 'j')
    {
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	testvector.push_back(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
    	testvector.push_back(student);
    	student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    	testvector.push_back(student);
    }

    //The UI loop
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzuf�gen" << std::endl
                  << "(2): Datenelement abh�ngen" << std::endl
                  << "(3): Datenbank ausgeben for" << std::endl
				  << "(4): Datenbank ausgeben back" << std::endl
                  << "(7): Beenden" << std::endl;
        std::cin >> abfrage;

        switch (abfrage)
        {
            case '1':
				{
					unsigned int matNr = 0;
					std::string name = "";
					std::string dateOfBirth = "";
					std::string address = "";

					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
					getline(std::cin, name);    // get entire line, including whitespace
					std::cout << "Geburtsdatum: ";
					getline(std::cin, dateOfBirth);
					std::cout << "Adresse: ";
					getline(std::cin, address);
					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;

					student = Student(matNr, name, dateOfBirth, address);

					testvector.push_back(student);
				}
				break;
            case '2':
            	{
					testvector.pop_back();
					std::cout << "Das letzte Datenelemt wird entfernt\n";
            	}
                break;

            case '3':
                std::cout << "Inhalt des Stacks:\n";
                for(it = testvector.begin();it !=testvector.end();it++)
                {
                	it->print();
                }
                break;

            case '4':
                std::cout << "Inhalt des Stacks:\n";
                for(revIt = testvector.rbegin();revIt !=testvector.rend();revIt++)
                {
                	revIt->print();
                }
                break;
            case '7':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

    return 0;
}
