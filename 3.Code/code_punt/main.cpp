#include <iostream>

#include "coda_punt.h"

using namespace std;

int main()
{
    Coda_punt<int> cp;
    cp.inCoda(4);
    cp.inCoda(3);
    cp.inCoda(2);
    cp.inCoda(1);
    cp.stampaCoda();
    cp.fuoriCoda();
    cp.stampaCoda();
    cp.inCoda(4);
    cp.stampaCoda();
    //cp.leggiCoda();



    return 0;
}
