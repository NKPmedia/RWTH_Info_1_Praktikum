//
// Created by paul on 19.04.17.
//

/*
 * Formel für Fibonacci:
 * f(0) = 0
 * f(1) = 1
 * f(b) = f(n-1) + f(n-2)
 *
 *
 */

#include <iostream>

int fibonacci(int i);

/**
 * @brief Berechnet die Fibonacci Zahlen von 0 bis 25
 * @return
 */
int main()
{
    for(int i = 0; i < 26 ; i++)
    {
        std::cout << fibonacci(i) << std::endl;
    }
    return 0;
}

/*!
 * @brief Berechnet die Fibonacci-Zahl
 * @param i Zu berechnede Fibonacci Zahl
 * @return
 *
 * Schlechte Implementierung, da viel doppelt berechnet wird!!!
 */
int fibonacci(int i) {
    if(i == 0) return 0;
    else if(i==1) return 1;
    else return fibonacci(i-1) + fibonacci(i-2);
}
