# RWTH_Info_1_Praktikum

Alle Verusch des Info 1 Praktikums der RWTH des WS2017

Das Projekt beinhaltet alle Versuche in eigenen Unterverzeichnissen.
Jeder Versuch beseitzt ein eigenes Makefile, mit dem er compiliert werden kann.
Im root Ordner befindet sich ein Makefile, welches alle Versuche compiliert.

Orderstrucktur:

    ├── Makefile            //Makerfile des gesamten projekts
    ├── README.md           //Readme
    ├── Versuch0            //Ein Versuch
    │   ├── bin             //Beinhaltet die ausführbare Datei
    │   ├── Makefile        //Makefile des Versuches

    │   ├── obj             //Beinhaltet die .o Dateien

    │   └── source          //Beinhaltet den Source-code (das eigentliche Programm)

    └── Versuch4

        ├── bin

        ├── googletest      //Beinhaltet den googletest code

        ├── Makefile

        ├── obj

        ├── source

        ├── testObj         //Beinhaltet die .o Dateien der tests

        ├── tests           //Beinhaltet den Source der tests

        └── Versuch4.doxyfile
    


Ein paar Versuche beinhalten mehr Ordner als andere. Diese beinhalten zusätzliche Dateien für die UnitTest.

Falls das Projekt sich nicht compilieren lässt, einfach den source-Ordner anschauen und vom Code inspirieren lassen.
