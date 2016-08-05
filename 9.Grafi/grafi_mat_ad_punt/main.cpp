#include <iostream>

#include "grafoPunt.h"
#include "nodoGrafo.h"

using namespace std;

int main()
{

    GrafoPunt<int,int> g;
    NodoGrafo<int,int> n,m,z;

    n.setEtichetta(2);
    cout << n.getEtichetta() << endl;
    g.insNodo(n);

    m.setEtichetta(4);
    cout << m.getEtichetta() << endl;
    g.insNodo(m);

    z.setEtichetta(6);
    cout << z.getEtichetta() << endl;
    g.insNodo(z);

    g.print();
    //cout << m << endl;
    //cout << (m == n) << endl;
    //cout << "esiste 2? " << g.esisteNodo(n) << endl;
    //cout << "esiste 4? " << g.esisteNodo(m) << endl;
    cout << g.vuoto()<< endl;

    cout << g.vuoto()<< endl;



    //g.scriviNodo(n,3);
    cout << g.leggiNodo(n) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
