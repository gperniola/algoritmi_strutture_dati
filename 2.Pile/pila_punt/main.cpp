#include <iostream>

#include "pila_punt.h"

using namespace std;

int main()
{
    Pila_punt<int> pl, pl2;
    pl.inPila(4);
    pl.inPila(3);
    pl.inPila(2);
    pl.inPila(1);
    cout << pl << endl;
    cout << pl.leggiPila() <<endl;
    pl.fuoriPila();
    pl.inPila(8);
    cout << pl << endl;
    pl.stampaPila();
    /*pl.fuoriPila();
    pl.inPila(8);
    cout << pl.leggiPila() << endl;
    cout << pl;*/
    return 0;
}
