#ifndef CODAPALBEROBIN_H_
#define CODAPALBEROBIN_H_

#include "CodaP.h"
#include "alberoBinPunt.h"

template <class T>
class CodaPAlberoBin : public CodaP<T>{

public:
    typedef typename CodaP<T>::tipoElem tipoElem;
    typedef typename AlberoBinPunt<T>::nodo nodo;
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



private:
    AlberoBinPunt<T> alberoCoda;
    nodo ultimo;

    //void fixUp ();
    void fixDown();
    void switchElem(nodo, nodo);
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
    //FASE 1 DI INSERIMENTO NODO
    if(alberoCoda.alberoBinVuoto()){    //caso1: l'albero è vuoto, inserisco e come radice
        //cout << "inserting " << e << " in root" << endl;
        alberoCoda.insBinRadice();
        ultimo = alberoCoda.binRadice();
        alberoCoda.scriviNodo(e,ultimo);
    }else if(ultimo == alberoCoda.binRadice()){ //caso2: ultimo è la radice, inserisco in sin
       // cout << "inserting " << e << " in root-left" << endl;
        AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
        newAlbero->insBinRadice();
        alberoCoda.scriviNodo(e,newAlbero->binRadice());
        alberoCoda.insFiglioSin(alberoCoda.binRadice(), *newAlbero);
        ultimo = alberoCoda.binFiglioSin(alberoCoda.binRadice());
    }else if(ultimo == alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo))){ //caso3: è un figlio sin di un nodo, inserisce in fratello des
        //cout << "inserting " << e << " in right brother" << endl;
        AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
        newAlbero->insBinRadice();
        alberoCoda.scriviNodo(e,newAlbero->binRadice());
        alberoCoda.insFiglioDes(alberoCoda.binPadre(ultimo), *newAlbero);
        ultimo = alberoCoda.binFiglioDes(alberoCoda.binPadre(ultimo));
    }else{ //caso4: è un nodo destro, deve salire fino a radire e creare un nuovo livello oppure fino a che non è figliosin di qualche nodo
        typename AlberoBinPunt<T>::nodo temp = ultimo;
        while(temp == alberoCoda.binFiglioDes(alberoCoda.binPadre(temp)) && temp != alberoCoda.binRadice()){
           // cout << "up one" << endl;
            temp = alberoCoda.binPadre(temp);
        }
        if(temp == alberoCoda.binRadice()){ //ha raggiunto radice, inserisce un nuovo sin in fondo
            while(!alberoCoda.sinVuoto(temp))
                temp = alberoCoda.binFiglioSin(temp);
            //cout << "inserting " << e << " in new level left" << endl;
            AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
            newAlbero->insBinRadice();
            alberoCoda.scriviNodo(e,newAlbero->binRadice());
            alberoCoda.insFiglioSin(temp, *newAlbero);
            ultimo = alberoCoda.binFiglioSin(temp);
        }else{
            temp = alberoCoda.binFiglioDes(alberoCoda.binPadre(temp));
            while(!alberoCoda.sinVuoto(temp))
                temp = alberoCoda.binFiglioSin(temp);
            //cout << "inserting " << e << " in left node of a right brother" << endl;
            AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
            newAlbero->insBinRadice();
            alberoCoda.scriviNodo(e,newAlbero->binRadice());
            alberoCoda.insFiglioSin(temp, *newAlbero);
            ultimo = alberoCoda.binFiglioSin(temp);
        }
    }
    // FASE 2 DI AGGIUSTAMENTO
    typename AlberoBinPunt<T>::nodo temp = ultimo;
    while(alberoCoda.leggiNodo(temp) < alberoCoda.leggiNodo(alberoCoda.binPadre(temp)) && temp != alberoCoda.binRadice()){
        //cout << "swapping " << alberoCoda.leggiNodo(temp) << " with " << alberoCoda.leggiNodo(alberoCoda.binPadre(temp)) << endl;
        tipoElem temp_e = alberoCoda.leggiNodo(alberoCoda.binPadre(temp));
        alberoCoda.scriviNodo(alberoCoda.leggiNodo(temp), alberoCoda.binPadre(temp));
        alberoCoda.scriviNodo(temp_e, temp);
        temp = alberoCoda.binPadre(temp);
    }
}

template <class T>
typename CodaPAlberoBin<T>::tipoElem CodaPAlberoBin<T>::min() {
    if(!alberoCoda.alberoBinVuoto())
        return alberoCoda.leggiNodo(alberoCoda.binRadice());
}

template <class T>
void CodaPAlberoBin<T>::cancellaMin() {
    if(!alberoCoda.alberoBinVuoto()){

        tipoElem last_elem;

        if(ultimo == alberoCoda.binRadice()){ //l'albero ha solo la radice, cancello l'albero
            cout << "do" << endl;
            ultimo = nullptr;
            alberoCoda.cancsottoAlbero(alberoCoda.binRadice());
        }else if(ultimo == alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo))){
            cout << "do2" << endl;
            last_elem = alberoCoda.leggiNodo(ultimo);
            //alberoCoda.scriviNodo(alberoCoda.leggiNodo(ultimo), alberoCoda.binRadice());
            nodo temp = ultimo;
            while(temp == alberoCoda.binFiglioSin(alberoCoda.binPadre(temp)) && temp != alberoCoda.binRadice()){
                cout << "up one" << endl;
                temp = alberoCoda.binPadre(temp);
            }
            if(temp == alberoCoda.binRadice()){ //ha raggiunto radice, inserisce un nuovo sin in fondo
                        cout << "do21" << endl;
                while(!alberoCoda.desVuoto(temp))
                    temp = alberoCoda.binFiglioDes(temp);
                //cout << "inserting " << e << " in new level left" << endl;
                alberoCoda.cancsottoAlbero(ultimo);
                ultimo = temp;
                delete temp;
            }else{
                        cout << "do22" << endl;
                temp = alberoCoda.binFiglioSin(alberoCoda.binPadre(temp));
                while(!alberoCoda.desVuoto(temp))
                    temp = alberoCoda.binFiglioDes(temp);
                //cout << "inserting " << e << " in left node of a right brother" << endl;
                alberoCoda.cancsottoAlbero(ultimo);
                ultimo = temp;
                delete temp;
            }
        }
        else if(ultimo == alberoCoda.binFiglioDes(alberoCoda.binPadre(ultimo))){
            alberoCoda.scriviNodo(alberoCoda.leggiNodo(ultimo), alberoCoda.binRadice());
            typename AlberoBinPunt<T>::nodo temp = alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo));
            alberoCoda.cancsottoAlbero(ultimo);
            ultimo = temp;
            delete temp;
        }
        cout  << "update" << endl;
        // FASE 2 DI AGGIUSTAMENTO
        alberoCoda.scriviNodo(last_elem,alberoCoda.binRadice());
        bool exit_loop = false;
        nodo temp;
        if(alberoCoda.alberoBinVuoto())
            exit_loop = true;
        else
            temp = alberoCoda.binRadice();
        while(!exit_loop){
            if(alberoCoda.sinVuoto(temp))
                exit_loop = true;
            else if(alberoCoda.desVuoto(temp)){
                if(alberoCoda.leggiNodo(temp) > alberoCoda.leggiNodo(alberoCoda.binFiglioSin(temp))){
                    switchElem(temp, alberoCoda.binFiglioSin(temp));
                    temp = alberoCoda.binFiglioSin(temp);
                }else exit_loop = true;
            }else{
                if (alberoCoda.leggiNodo(alberoCoda.binFiglioSin(temp)) < alberoCoda.leggiNodo(alberoCoda.binFiglioDes(temp))){
                    //scambia con figliosin
                    if(alberoCoda.leggiNodo(temp) > alberoCoda.leggiNodo(alberoCoda.binFiglioSin(temp))){
                        switchElem(temp, alberoCoda.binFiglioSin(temp));
                        temp = alberoCoda.binFiglioSin(temp);
                    }else exit_loop = true;
                }else{
                    //scambia con figliodes
                    if(alberoCoda.leggiNodo(temp) > alberoCoda.leggiNodo(alberoCoda.binFiglioDes(temp))){
                        switchElem(temp, alberoCoda.binFiglioDes(temp));
                        temp = alberoCoda.binFiglioDes(temp);
                    }else exit_loop = true;
                }
            }
        }
    }
}

template <class T>
void CodaPAlberoBin<T>::switchElem(nodo n, nodo m) {
    tipoElem temp_e = alberoCoda.leggiNodo(n);
    alberoCoda.scriviNodo(alberoCoda.leggiNodo(m), n);
    alberoCoda.scriviNodo(temp_e, m);
}

template <class T>
void CodaPAlberoBin<T>::fixDown() {
}

template <class T>
void CodaPAlberoBin<T>::print() {
    alberoCoda.print();
}
#endif
