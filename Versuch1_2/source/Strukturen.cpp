/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person
{
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

int main()
{
    Person nBenutzer;

    std::cout << "Geben sie ihren Vorname ein: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Geben sie ihren Nachnamen ein: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Geben sie ihr Geburtsjahr ein: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Geben sie ihr Alter ein: ";
    std::cin >> nBenutzer.iAlter;

    std::cout << "Benutzer normal" << std::endl;
    std::cout << "Name " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname " << nBenutzer.sVorname << std::endl;
    std::cout << "Geburtsjahr " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter " << nBenutzer.iAlter << std::endl;

    Person nKopieGesamt = nBenutzer;
    Person nKopieEinzeln;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;

    std::cout << "Benutzerkopie gesamt" << std::endl;
    std::cout << "Name " << nKopieGesamt.sNachname << std::endl;
    std::cout << "Vorname " << nKopieGesamt.sVorname << std::endl;
    std::cout << "Geburtsjahr " << nKopieGesamt.iGeburtsjahr << std::endl;
    std::cout << "Alter " << nKopieGesamt.iAlter << std::endl;

    std::cout << "Benutzerkopie einzeln" << std::endl;
    std::cout << "Name " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Vorname " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Geburtsjahr " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << "Alter " << nKopieEinzeln.iAlter << std::endl;
    return 0;

}
