#include <iostream>

#include "grafoPunt.h"
#include "nodoGrafo.h"

using namespace std;

int main()
{

    GrafoPunt<int,int> g;
    NodoGrafo<int,int> n;
    cout << g.vuoto()<< endl;
    g.insNodo(n);
    cout << g.vuoto()<< endl;
    cout << "Hello world!" << endl;
    return 0;
}
