#include <iostream>

#include "grafoPunt.h"

using namespace std;


int main()
{
    GrafoPunt<int> G;
    //NodoGrafo<int> a1(1), a2(2), a3(3), a4(4);

    NodoGrafo<int>b[10];
    for(int i = 0; i < 10; i++){
        b[i] = NodoGrafo<int>(i);
        G.insNodo(b[i]);
    }
    G.insArco(b[0],b[4],1);
    G.insArco(b[0],b[9],3);
    G.insArco(b[0],b[5],8);
    G.insArco(b[1],b[4],4);
    G.insArco(b[1],b[8],1);
    G.insArco(b[1],b[2],2);
    G.insArco(b[2],b[3],9);
    G.insArco(b[2],b[8],6);
    G.insArco(b[3],b[1],2);
    G.insArco(b[4],b[9],6);
    G.insArco(b[4],b[2],8);
    G.insArco(b[4],b[6],1);
    G.insArco(b[4],b[7],2);
    G.insArco(b[5],b[4],4);
    G.insArco(b[5],b[9],5);
    G.insArco(b[5],b[6],2);
    G.insArco(b[5],b[7],8);
    G.insArco(b[8],b[9],6);
    G.insArco(b[7],b[3],5);

    /*G.insNodo(a1);
    G.insNodo(a2);
    G.insNodo(a3);
    G.insNodo(a4);

    G.insArco(a1,a2,10);
    G.insArco(a1,a3,12);
    G.insArco(a3,a4,14);
    G.insArco(a3,a2,16);*/
    //G.insArco(a1,a2,12);

    //cout << "esiste? " << G.esisteArco(a1,a2) << endl;
    //G.insArco(NodoGrafo<int>(1),NodoGrafo<int>(3),10);
    //G.insArco(NodoGrafo<int>(1),NodoGrafo<int>(4),10);
    //G.insArco(NodoGrafo<int>(1),NodoGrafo<int>(2),10);


    G.print();
    cout << endl <<endl;
    G.DFS(b[0]);

    cout << "----" <<endl;
    G.setAllVisitato(false);
    G.BFS(b[0]);

    //cout << "esiste? " << G.esisteArco(a1,a2) << endl;
    //G.cancArco(a1,a1);
    //G.cancNodo(a2);
    //cout << G.leggiPeso(a1,a3);
    //cout <<endl;
    //G.scriviPeso(a1,a3,20);
    //G.print();
    //cout << "esiste? " << G.esisteArco(a1,a2) << endl;
    //GrafoPunt<int>::List* l = G.adiacenti(a1);
    //GrafoPunt<int>::printAdiacenti(l);

    return 0;
}
