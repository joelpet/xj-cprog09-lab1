#include <iostream>
#include "matrix.h"     // inkludera din headerfil h�r


int main()
{
    // N�gra saker som ska fungera:
    std::cout << "Matrix a(7, 4)" << std::endl;
    Matrix a(7, 4);        // initiering med 7 rader och 4 kolumner med nollor

    std::cout << "a[5][2] = 7"<< std::endl;
    a[5][2] = 7;           // tilldelning till element

    std::cout << "a = " << std::endl << a << std::endl;

    std::cout << "=====================================" << std::endl;
    
    // Att testa:

    // att ett konstant matrisobjekt returnerar skrivskyddat element
    // att matrisen �r nollindexerad
    
    // tilldelning fungerar
    // operator++ p� ett element fungerar

    // ogiltig �tkomst inte fungerar

    return 0;
}

