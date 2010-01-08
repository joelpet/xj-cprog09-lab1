#include <iostream>
#include "matrix.h"     // inkludera din headerfil här


int main()
{
    // Några saker som ska fungera:
    std::cout << "Matrix a(7, 4)" << std::endl;
    Matrix a(7, 4);        // initiering med 7 rader och 4 kolumner med nollor

    std::cout << "a[5][2] = 7"<< std::endl;
    a[5][2] = 7;           // tilldelning till element

    std::cout << "a = " << std::endl << a << std::endl;

    std::cout << "=====================================" << std::endl;
    
    // Att testa:

    // att ett konstant matrisobjekt returnerar skrivskyddat element
    // att matrisen är nollindexerad
    
    // tilldelning fungerar
    // operator++ på ett element fungerar

    // ogiltig åtkomst inte fungerar

    return 0;
}

