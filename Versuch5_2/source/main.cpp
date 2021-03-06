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
#include "Stack.h"
#include "Student.h"
#include "List.h"

/**
 * @brief starts a UI to interact with a List of students
 * @return
 */
int main()
{
	List testList;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    //Fills the list
    if (abfrage != 'j')
    {
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	testList.enqueue_head(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
    	testList.enqueue_head(student);
    	student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    	testList.enqueue_head(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzuf�gen head" << std::endl
                  << "(2): Datenelement abh�ngen" << std::endl
                  << "(3): Datenbank ausgeben for" << std::endl
				  << "(4): Datenbank ausgeben back" << std::endl
				  << "(5): Datenelement löschen" << std::endl
				  << "(6): Datenelement hinzuf�gen tail" << std::endl
                  << "(7): Beenden" << std::endl;
        std::cin >> abfrage;

        switch (abfrage)
        {
        	//Adds a student at the head
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

					testList.enqueue_head(student);
				}
				break;
			//Delets the last student
            case '2':
            	{
					Student delElem = Student();
					bool success = false;
					success = testList.dequeue(delElem);

					if(success)
					{
						std::cout << "Das letzte Datenelemt wird entfernt\n";
						delElem.print();
					}
					else
					{
						std::cout << "Der Stack ist leer!\n";
					}
            	}
                break;

            //Prints the list
            case '3':
                std::cout << "Inhalt des Stacks:\n";
                testList.print_forwards();
                break;

            //Prints the list backwords
            case '4':
                std::cout << "Inhalt des Stacks:\n";
                testList.print_backwards();
                break;

            //Delets a student by his number
            case '5':
            	{
					std::cout << "Welche Nummer wollen sie löschen:\n";
					unsigned int nummer = 0;
					std::cin >> nummer;
					Student delElem = Student();
					bool succ = testList.delElementByNr(delElem,nummer);
					if(succ) std::cout << "Wurde gelösche\n";
					else std::cout << "Error\n";
					break;
            	}

            //Adds a student at the tail
            case '6':
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

          			testList.enqueue_tail(student);
      			}
            	break;

            //Quit
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
