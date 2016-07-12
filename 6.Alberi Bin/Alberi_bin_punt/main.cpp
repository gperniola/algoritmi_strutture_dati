#include <iostream>


#include "alberoBinPunt.h"

using namespace std;

int main()
{
    /*AlberoBinPunt<int> A, B;
    cout << A.alberoBinVuoto() << endl;
    A.insBinRadice();
    cout << A.alberoBinVuoto() << endl;

    A.scriviNodo(15,A.binRadice());
    cout << A.leggiNodo(A.binRadice()) << endl;
    A.insFiglioSin(A.binRadice(),B);
    A.scriviNodo(16,A.binFiglioSin(A.binRadice()));
    cout << A.leggiNodo(A.binFiglioSin(A.binRadice())) << endl;
    A.print();
    */


    int dim = 8;
    AlberoBinPunt<int> A[dim];

    for (int i = 0; i < dim; i++ ){
        A[i].insBinRadice();
        A[i].scriviNodo(i,A[i].binRadice());
    }

    int s = 1;
    int i = 0;
    bool sinVuoto = false;
    while (s < dim){
        if (sinVuoto == false){
            A[i].insFiglioSin(A[i].binRadice(),A[s]);
            sinVuoto = true;

        }
        else{
            A[i].insFiglioDes(A[i].binRadice(),A[s]);
            sinVuoto = false;
            i++;
        }
        s++;
    }


    /*A[0].insFiglioSin(A[0].binRadice(),A[1]);
    A[0].insFiglioDes(A[0].binRadice(),A[2]);

    A[1].insFiglioSin(A[1].binRadice(),A[3]);
    A[1].insFiglioDes(A[1].binRadice(),A[4]);
    A[2].insFiglioSin(A[2].binRadice(),A[5]);
    A[2].insFiglioDes(A[2].binRadice(),A[6]);*/



    A[0].print();
    A[0].preVisita(A[0].binRadice());
    cout << endl;
    A[0].postVisita(A[0].binRadice());
    cout << endl;
    A[0].inVisita(A[0].binRadice());
    cout << endl;
    cout << "max livello: " << A[0].maxLivello() << endl;
    cout << "dim da radice: " << A[0].dimAlbero(A[0].binRadice()) << endl;
    cout << "dim da figlioSin di radice: " << A[0].dimAlbero(A[0].binFiglioSin(A[0].binRadice())) << endl;
    return 0;
}
