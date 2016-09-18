#include <iostream>

#include "list_pointer.h"
#include "lista_ordinata.h"

using namespace std;

int main()
{
    List_pointer<int> L1, L2;
    inserisci(L2,5);
    inserisci(L2,3);
    inserisci(L2,4);
    inserisci(L2,5);
    inserisci(L2,1);
    inserisci(L2,2);
    //inserisci(L2,3);
    //inserisci(L2,5);
    //inserisci(L2,4);
    inserisci(L1,5);
    inserisci(L1,3);
    inserisci(L1,4);
    cout << L1 << L2;
    //differenza(L1,L2);
    //cout << L1;
    cout << sottolista(L1,L2);
    return 0;
}
