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
#include <algorithm>

/**
 * @brief overload the << to better print student information
 * @param out the stream
 * @param student the student to print out
 * @return
 */
std::ostream& operator << (std::ostream& out ,Student student)
{
	return student.print(out);
}

int main()
{
	std::vector<Student> testvector;
	std::vector<Student>::iterator it;
	std::vector<Student>::reverse_iterator revIt;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	testvector.push_back(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
    	testvector.push_back(student);
    	student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    	testvector.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzuf�gen" << std::endl
                  << "(2): Datenelement abh�ngen" << std::endl
                  << "(3): Datenbank ausgeben for" << std::endl
				  << "(4): Datenbank ausgeben back" << std::endl
				  << "(5): Datenbank sortieren" << std::endl
				  << "(6): Datenelement löschen" << std::endl
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

					//Add a new student
					student = Student(matNr, name, dateOfBirth, address);

					testvector.push_back(student);
				}
				break;

            case '2':
            	{
            		//remove the last element
					testvector.pop_back();
					std::cout << "Das letzte Datenelemt wird entfernt\n";
            	}
                break;

            case '3':
            	//Print the database
                std::cout << "Inhalt des Stacks:\n";

                for(it = testvector.begin();it !=testvector.end();it++)
                {
                	std::cout << *it;
                }

                break;

            case '4':
            	//Print the database backwards
                std::cout << "Inhalt des Stacks:\n";
                for(revIt = testvector.rbegin();revIt !=testvector.rend();revIt++)
                {
                	std::cout << *revIt;
                }
                break;

            case '5':
            	stable_sort(testvector.begin(),testvector.end());

            	//Print the database
            	std::cout << "Inhalt des Stacks:\n";

            	for(it = testvector.begin();it !=testvector.end();it++)
            	{
            		std::cout << *it;
            	}

            	break;

            case '6':
				{
					std::cout << "Geben sit eine MatNr an:\n";
					unsigned int matNr = 0;
					std::cin >> matNr;

					//Search the matNr
					for(it = testvector.begin();it !=testvector.end();it++)
					{
						if(*it == matNr)
						{
							testvector.erase(it);
						}
					}

					//Print the database
					std::cout << "Inhalt des Stacks:\n";

					for(it = testvector.begin();it !=testvector.end();it++)
					{
						std::cout << *it;
					}
					break;
				}
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

