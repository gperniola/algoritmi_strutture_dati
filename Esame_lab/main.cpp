#include "sparsa.h"
#include <cstdlib>
using namespace std;

int main()
{
    cout << "---- Esame di A.S.D. Giuseppe Perniola m.542844 ----"<<endl<<endl;
    sparsa sp;
    cout << "Inserisco valori da <1,1> fino a <3,3>..."<<endl<<endl;
    sp.inserisci(1,1,5.67); sp.inserisci(1,2,2.3);  sp.inserisci(1,3,4.5);
    sp.inserisci(2,1,1);    sp.inserisci(2,2,5.3);  sp.inserisci(2,3,6);
    sp.inserisci(3,1,1.3);  sp.inserisci(3,2,1);    sp.inserisci(3,3,8);

    cout << "(1)Tento di reinserire <1,1,2> con un valore diverso..."<<endl;
    sp.inserisci(1,1,2);

    cout <<endl<< "(2)Cancello <3,2>..."<<endl;
    sp.rimuovi(3,2);

    cout <<endl<< "(3)Tento di ricancellare <3,2>..."<<endl;
    sp.rimuovi(3,2);

    cout << endl<< "(4)Reinserisco <3,2,32>..."<<endl;
    sp.inserisci(3,2,32);

    cout << endl<< "(5)Leggo <3,2>: "<< sp.leggi(3,2) <<endl;
    cout << endl<< "(6)Leggo <5,2>..." << endl;
    double b = sp.leggi(5,2);
    cout << endl<< "(7)Valore restituito da <5,2>: " << b << endl;
    cout << endl<< "(8)Stampa della lista contenente la matrice..."<<endl;
    sp.print();
    system("pause");
    return 0;
}
