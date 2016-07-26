#include <iostream>
#include "CodaPAlberoBin.h"

using namespace std;

int main()
{
    AlberoBinPunt<int> a,b;
    a.insBinRadice();
    b.insBinRadice();
    a.scriviNodo(1, a.binRadice());
    b.scriviNodo(2, b.binRadice());
    a.insFiglioSin(a.binRadice(),b);
    a.print();
    a.cancsottoAlbero(b.binRadice());
    a.print();
    cout << endl << endl;

    CodaPAlberoBin<int> coda;
    coda.inserisci(2);
    //coda.inserisci(2);
    /*coda.inserisci(4);
    coda.inserisci(5);
    coda.inserisci(3);
    coda.inserisci(7);
    coda.inserisci(6);
    coda.inserisci(1);*/
    coda.print();
    cout << coda.min() << endl;
    coda.cancellaMin();
    coda.print();
    //cout << coda.min() << endl;
    return 0;



}
