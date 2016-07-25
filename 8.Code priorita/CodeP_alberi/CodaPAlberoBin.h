#ifndef CODAPALBEROBIN_H_
#define CODAPALBEROBIN_H_

#include "CodaP.h"
#include "alberoBinPunt.h"

template <class T>
class CodaPAlberoBin : public CodaP<T>{

public:
    typedef typename CodaP<T>::tipoElem tipoElem;

     /*****constructors*****/
    CodaPAlberoBin();

    /*****copy constructor*****/
    //CodaPAlberoBin(const CodaPAlberoBin<T> &);

    /*****destructor*****/
    ~CodaPAlberoBin();

    /*****operators*****/
    void creaPrioriCoda ();
    void inserisci (tipoElem);
    tipoElem min ();
    void cancellaMin ();

    void print();
    /*void fixUp ();
    void fixDown (int, int);*/

private:
    AlberoBinPunt<T> alberoCoda;
    typename AlberoBinPunt<T>::nodo ultimo;
};

template <class T>
CodaPAlberoBin<T>::CodaPAlberoBin() {
    this->creaPrioriCoda();
}

template <class T>
CodaPAlberoBin<T>::~CodaPAlberoBin(){
    //alberoCoda.~AlberoBinPunt();
}

template <class T>
void CodaPAlberoBin<T>::creaPrioriCoda() {
//    alberoCoda = new AlberoBinPunt<T>();
    ultimo = nullptr;
}

template <class T>
void CodaPAlberoBin<T>::inserisci(tipoElem e) {
    if(alberoCoda.alberoBinVuoto()){    //caso1: l'albero è vuoto, inserisco e come radice
        cout << "inserting " << e << " in root" << endl;
        alberoCoda.insBinRadice();
        ultimo = alberoCoda.binRadice();
        alberoCoda.scriviNodo(e,ultimo);
    }else if(ultimo == alberoCoda.binRadice()){ //caso2: ultimo è la radice, inserisco in sin
        cout << "inserting " << e << " in root-left" << endl;
        AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
        newAlbero->insBinRadice();
        alberoCoda.scriviNodo(e,newAlbero->binRadice());
        alberoCoda.insFiglioSin(alberoCoda.binRadice(), *newAlbero);
        ultimo = alberoCoda.binFiglioSin(alberoCoda.binRadice());
    }else{
        int passiUp = 0;


    }

}

template <class T>
typename CodaPAlberoBin<T>::tipoElem CodaPAlberoBin<T>::min() {
}

template <class T>
void CodaPAlberoBin<T>::cancellaMin() {
}

template <class T>
void CodaPAlberoBin<T>::print() {
    alberoCoda.print();
}
#endif
