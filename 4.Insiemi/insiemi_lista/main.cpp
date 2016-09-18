#include <iostream>

#include "insiemi_lista.h"


using namespace std;

int main()
{
    Insiemi_lista<int> A, B, C, D;
    int i;
    cout << "A is vuoto: " << A.insiemeVuoto() << endl;
    i = 1;
    cout << "A contiene 1: " << A.appartiene(i) << endl;
    A.inserisci(1);
    cout << "Inserito 1, A contiene 1: " << A.appartiene(i) << endl;
    A.cancella(1);
    cout << "Cancello 1, A contiene 1: " << A.appartiene(i) << endl << endl;

    A.inserisci(1); A.inserisci(2); A.inserisci(3); A.inserisci(4);
    B.inserisci(3); B.inserisci(4); B.inserisci(5); B.inserisci(6);
    cout << "A = {1,2,3,4} , B = {3,4,5,6}" << endl << endl;

    cout << "A U B = ";
    C.unione(A,B);
    for (int i = 1; i < 11; i++)
        if(C.appartiene(i))
            cout << i << ", ";
    cout << endl;

    cout << "A ^ B = ";
    C.intersezione(A,B);
    for (int i = 1; i < 11; i++)
        if(C.appartiene(i))
            cout << i << ", ";
    cout << endl;

    cout << "A / B = ";
    C.differenza(A,B);
    for (int i = 1; i < 11; i++)
        if(C.appartiene(i))
            cout << i << ", ";
    cout << endl;

    cout << "D is vuoto? " << D.insiemeVuoto() << endl;
    D = A;
    cout << "D is vuoto? " << D.insiemeVuoto() << endl;
    cout << "D = ";
    for (int i = 1; i < 11; i++)
        if(D.appartiene(i))
            cout << i << ", ";
    cout << endl;
    return 0;
}
