#include <iostream>
#include "CodaPAlberoBin.h"

using namespace std;

int main()
{
    CodaPAlberoBin<int> coda;
    coda.inserisci(1);
    coda.inserisci(2);
    coda.print();
    cout << "Hello world!" << endl;
    return 0;
}
