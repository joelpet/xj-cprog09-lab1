#include <iostream>
#include <stdexcept>
#include "vector.h"     // inkludera din headerfil här


int main()
{
    // Några saker som ska fungera:
    Vector a(7);           // initiering med 7 element
    Vector b(a);           // kopieringskonstruktor 
    Vector c = a;          // kopieringskonstruktor 

    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const körs
    i = a[0];              // vektorn är nollindexerad
    i = a[5];              // int oper[](int) körs
    
    a[5]++;                // öka värdet till 8

    try {
        i = e[10];             // försöker hämta element som ligger utanför e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    
#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall behållas frigörs
#endif

    return 0;
}
