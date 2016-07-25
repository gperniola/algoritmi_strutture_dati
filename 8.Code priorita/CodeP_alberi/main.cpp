#include <iostream>
#include "CodaPAlberoBin.h"

using namespace std;

int main()
{
    CodaPAlberoBin<int> coda;
    coda.inserisci(3);
    coda.inserisci(2);
    coda.inserisci(4);
    coda.inserisci(5);
    coda.inserisci(3);
    coda.inserisci(7);
    coda.inserisci(6);
    coda.inserisci(1);
    coda.print();
    cout << coda.min() << endl;
    return 0;
}
