#include <iostream>

#include "coda_punt.h"

#include "Bins.h"

using namespace std;

int main()
{
    /*Coda_punt<int> cp;
    cp.inCoda(4);
    cp.inCoda(3);
    cp.inCoda(2);
    cp.inCoda(1);
    cp.stampaCoda();
    cp.fuoriCoda();
    cp.stampaCoda();
    cp.inCoda(4);
    cp.stampaCoda();
    //cp.leggiCoda();*/

    Bins B;
    B.insert(1);B.insert(4);
    B.insert(2);B.insert(5);
    B.insert(4);B.insert(8);
    B.insert(10);B.insert(9);
    B.insert(4);B.insert(1);
    B.insert(6);B.insert(7);
    B.insert(8);B.insert(5);
    B.insert(2);B.insert(9);
    B.insert(6);B.insert(12);
    B.print();
    B.Delete(1);
    B.Delete(3);
    B.print();
    cout << "media 0: "<< B.mean(0) << " freq: "<< B.freq(0) <<endl;
    cout << "media 1: "<< B.mean(1)<< " freq: "<< B.freq(1) << endl;
    cout << "media 2: "<< B.mean(2)<< " freq: "<< B.freq(2) << endl;

    return 0;
}
