#include <iostream>
#include <stdexcept>
#include "vector.h"     // inkludera din headerfil h�r


void printVector(const Vector & vector, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << std::endl;
}

void asignToVector(Vector & vector, int size, unsigned int a) {
    for (int i = 0; i < size; i++) {
        vector[i] = a;
    }
}
int main()
{
    // N�gra saker som ska fungera:
    Vector a(7);           // initiering med 7 element
    asignToVector(a, 7, 1);
    // printVector(a, 7);
    Vector b(a);           // kopieringskonstruktor 
    asignToVector(b, 7, 2);
    // printVector(a, 7);
    Vector c = a;          // kopieringskonstruktor 
    asignToVector(c, 7, 3);
    // printVector(c, 7);

    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const k�rs
    i = a[0];              // vektorn �r nollindexerad
    i = a[5];              // int oper[](int) k�rs
    
    a[5]++;                // �ka v�rdet till 8

    try {
        i = e[10];             // f�rs�ker h�mta element som ligger utanf�r e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    
    asignToVector(a, 7, 1);
    
    printVector(b,7);
    b[3] = 5;
#if 1
    // Diverse saker att testa
    // e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall beh�llas frig�rs
#endif
    printVector(b,7);
    printVector(a,7);
    Vector z = a;
    z[0] = 5;
    a[0] = 1;     // b ska inte �ndras av denna sats.
    a[0]++;
    ++a[0];
    if (z[0] != 5 || z[0] == 1) {
        std::cout << "Copy constructor broken" << std::endl;
    }
    printVector(a,7);
    printVector(z,7);


    return 0;
}

