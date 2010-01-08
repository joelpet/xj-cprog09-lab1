#include "vector.h"             // inkludera din headerfil här
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <iostream>


namespace {
template<class T> void printVector(const Vector<T> & vector, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << std::endl;
}
}

// void asignToVector(Vector & vector, int size, unsigned int a) {
    // for (int i = 0; i < size; i++) {
        // vector[i] = a;
    // }
// }


int main()
{
    Vector<double> v;           // ok: defaultkonstruktor ger vektor med flyttal
    Vector<char> *a = new Vector<char>[3];  // dynamiskt allokerade ser ut så här
    delete [] a;


    assert(v.size() == 0);      // tom från början
    v.push_back(3.14);          // lägg till ett element sist 

    assert(v.size() == 1);      // nu ligger ett element i vektorn
    v.insert(0, 2.10);          // lägg till före element 0, dvs först

    assert(v[0] == 2.10 &&      // hamnade de rätt?
	   v[1] == 3.14);       

    assert(v.size() == 2);      // nu ligger två element i vektorn
    v.sort(false);              // sortera i fallande ordning


    assert(v[0] == 3.14 &&      // hamnade de rätt?
	   v[1] == 2.10);       

    assert(v.size() == 2);      // ingenting ändrat?
    v[1] = 2.11;                // tilldelning av enstaka element;

    const Vector<double> &vc = v;  // skapa konstant referens
    assert(vc.size() == 2);     // ok: ändrar ej vektorn som är konstant
    assert(vc[0] == 3.14 &&     // ok: ändrar ej vektorn som är konstant
	   vc[1] == 2.11);

    Vector<double> vd = v;

    vd[0] =5;
    
    v.erase(0);                 // ta bort första elementet               
    assert(v.size() == 1);      // rätt antal elelment
    v.clear();                  // töm hela vektorn
    assert(v.size() == 0);      // tom när alla element är borttagna

    v.push_back( double(5.2) );
    v.push_back( 4.9 );
    v.push_back( 5.2 );
    v.push_back( 3.8 );
    v.push_back( 9.2 );
    v.push_back( 9.2 );
    v.push_back( -5.2 );
    v.push_back( 9.2 );
    v.push_back( 9.2 );
    v.push_back( -9.2 );
    v.push_back( 9.2 );

    v.printVector();

    //v.sort(true);

    //v.printVector();

    v.sort(false);

    v.printVector();

    
    // kontrollera att följande rader inte går att kompilera
#if 0
    vc[0] = 3.1415;             // fel: tilldelning av konstant objekt
    Vector<char> c = v;         // fel: tilldelning av olika typer
    vc.sort();                  // fel: ändrar konstant objekt
#endif

    return 0;
}
