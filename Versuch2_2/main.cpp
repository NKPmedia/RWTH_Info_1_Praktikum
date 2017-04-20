//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fib(int n);

int main ()
{
    std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
    for (int i = 1; i <= 48 ; i ++)
    {
        std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
    }
    return 0;
}

/*!
 * @brief Berechnet die Fibonacci Zahl
 * @param n
 * @return
 *
 * Bessere Version, da es keine doppelten Berechnungen gibt
 * Ab 45 gibt es falsche Ergebnisse, da dann der Wertebereich von dem Datentyp int zu ende ist.
 * Für größere Zahlen sollte man long long nehmen
 */
int fib(int n)
{
    int prevFib = 0;
    int currFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n; i++)
    {
        int newFib = prevFib + currFib ;
        prevFib = currFib ;
        currFib = newFib ;
    }
    return currFib ;
}