#include <iostream>


#include "alberoBinPunt.h"

using namespace std;

int main()
{


    int dim = 8;
    AlberoBinPunt<int> A[dim];

    //A[0].insFiglioSin(A[0].binRadice(), A[1]);

    //A[0].insBinRadice();
    //AlberoBinPunt<int>::nodo n;
    //n = A[0].binRadice();
    //cout << n;
   for (int i = 0; i < dim; i++ ){
        A[i].insBinRadice();
        A[i].scriviNodo(i,A[i].binRadice());
    }

   // A[0].costrBinAlbero(A[1],A[2]);


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


    A[0].print();


   // A[0].cancsottoAlbero(A[0].binFiglioSin(A[0].binFiglioSin(A[0].binRadice())));

    A[0].print();

    A[0].preVisita(A[0].binRadice());
    cout << endl;
    A[0].postVisita(A[0].binRadice());
    cout << endl;
    A[0].inVisita(A[0].binRadice());
    cout << endl;
    cout << "max livello: " << A[0].maxLivello() << endl;
    cout << "dim da radice: " << A[0].dimAlbero(A[0].binRadice()) << endl;

    cout << A[0].leggiNodo(A[0].binPadre(A[3].binRadice())) << " è padre di " << A[0].leggiNodo(A[3].binRadice()) << endl;
    cout << A[0].leggiNodo(A[0].binPadre(A[5].binRadice())) << " è padre di " << A[0].leggiNodo(A[5].binRadice()) << endl;
    //cout << "dim da figlioSin di radice: " << A[0].dimAlbero(A[0].binFiglioSin(A[0].binRadice())) << endl;
    return 0;
}
