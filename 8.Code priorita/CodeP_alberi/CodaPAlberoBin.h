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

    void fixUp (nodo);
    void fixDown(nodo);
    void switchElem(nodo, nodo);
};

template <class T>
CodaPAlberoBin<T>::CodaPAlberoBin() {
    this->creaPrioriCoda();
}

template <class T>
CodaPAlberoBin<T>::~CodaPAlberoBin(){
    alberoCoda.~AlberoBinPunt();
    delete ultimo;
}

template <class T>
void CodaPAlberoBin<T>::creaPrioriCoda() {
   // alberoCoda = new AlberoBinPunt<T>();
    ultimo = nullptr;
}

template <class T>
typename CodaPAlberoBin<T>::tipoElem CodaPAlberoBin<T>::min() {
    if(!alberoCoda.alberoBinVuoto())
        return alberoCoda.leggiNodo(alberoCoda.binRadice());
}

template <class T>
void CodaPAlberoBin<T>::inserisci(tipoElem e) {
    /*** caso1: l'albero è vuoto, inserisco e come radice ***/
    if(alberoCoda.alberoBinVuoto()){
        alberoCoda.insBinRadice();
        ultimo = alberoCoda.binRadice();
        alberoCoda.scriviNodo(e,ultimo);
    }
    else{
        AlberoBinPunt<T> *newAlbero = new AlberoBinPunt<T>();
        newAlbero->insBinRadice();
        alberoCoda.scriviNodo(e,newAlbero->binRadice());

        /*** caso2: ultimo è la radice, inserisco in sin ***/
        if(ultimo == alberoCoda.binRadice()){
            alberoCoda.insFiglioSin(alberoCoda.binRadice(), *newAlbero);
            ultimo = alberoCoda.binFiglioSin(alberoCoda.binRadice());
        }
        else{
            /*** caso3: è un figlio sin di un nodo, inserisce in fratello des ***/
            if(ultimo == alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo))){
                alberoCoda.insFiglioDes(alberoCoda.binPadre(ultimo), *newAlbero);
                ultimo = alberoCoda.binFiglioDes(alberoCoda.binPadre(ultimo));
            }
            else{
                /*** caso4: è un nodo destro, deve salire fino a radire e creare un nuovo livello oppure fino a che non è figliosin di qualche nodo ***/
                nodo temp = ultimo;
                while(temp == alberoCoda.binFiglioDes(alberoCoda.binPadre(temp)) && temp != alberoCoda.binRadice())
                    temp = alberoCoda.binPadre(temp);

                /*** ha raggiunto radice, inserisce un nuovo sin in fondo ***/
                if(temp == alberoCoda.binRadice()){
                    while(!alberoCoda.sinVuoto(temp))
                        temp = alberoCoda.binFiglioSin(temp);

                    alberoCoda.insFiglioSin(temp, *newAlbero);
                    ultimo = alberoCoda.binFiglioSin(temp);
                }
                else{
                    temp = alberoCoda.binFiglioDes(alberoCoda.binPadre(temp));
                    while(!alberoCoda.sinVuoto(temp))
                        temp = alberoCoda.binFiglioSin(temp);

                    alberoCoda.insFiglioSin(temp, *newAlbero);
                    ultimo = alberoCoda.binFiglioSin(temp);
                }
            }
        }

        /*** FASE 2 DI AGGIUSTAMENTO DELLA PRIORITA' ***/
        fixUp(ultimo);
    }
}


template <class T>
void CodaPAlberoBin<T>::cancellaMin() {

    if(!alberoCoda.alberoBinVuoto()){
        /*** l'albero ha solo la radice, cancello l'albero ***/
        if(ultimo == alberoCoda.binRadice()){
            ultimo = nullptr;
            alberoCoda.cancsottoAlbero(alberoCoda.binRadice());
        }
        else{
            /*** salviamo il contenuto di ultimo ***/
            tipoElem last_elem = alberoCoda.leggiNodo(ultimo);
            nodo temp = ultimo;

            /*** l'albero ha dei figli, controlliamo se ultimo è un figlioSin ***/
            if(ultimo == alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo))){

                /*** risaliamo l'albero finchè il nodo è un figlioSin o fino a raggiungere la radice ***/
                while(temp == alberoCoda.binFiglioSin(alberoCoda.binPadre(temp)) && temp != alberoCoda.binRadice())
                    temp = alberoCoda.binPadre(temp);

                /*** se abbiamo raggiunto la radice scendiamo da figlioDes ***/
                if(temp == alberoCoda.binRadice()){
                    while(!alberoCoda.desVuoto(temp))
                        temp = alberoCoda.binFiglioDes(temp);
                }

                /*** altrimenti se siamo diventati un figlioDes di qualche nodo passiamo al figlioSin
                del padre e scendiamo dai figliDes ***/
                else{
                    temp = alberoCoda.binFiglioSin(alberoCoda.binPadre(temp));
                    while(!alberoCoda.desVuoto(temp))
                        temp = alberoCoda.binFiglioDes(temp);
                }
            }

            /*** altrimenti è un figlio destro, quindi il nuovo ultimo sarà il figlioSin del padre ***/
            else{
                temp = alberoCoda.binFiglioSin(alberoCoda.binPadre(ultimo));
            }

            /*** cancelliamo il nodo in più e settiamo un nuovo ultimo ***/
            alberoCoda.cancsottoAlbero(ultimo);
            ultimo = temp;

            /*** FASE 2 DI AGGIUSTAMENTO DELLA PRIORITA' ***/
            alberoCoda.scriviNodo(last_elem,alberoCoda.binRadice());
            fixDown(alberoCoda.binRadice());
        }
    }
}

template <class T>
void CodaPAlberoBin<T>::fixUp(nodo n) {
    if(alberoCoda.binRadice() != n){
        if(alberoCoda.leggiNodo(n) < alberoCoda.leggiNodo(alberoCoda.binPadre(n))){
            switchElem(n,alberoCoda.binPadre(n));
            fixUp(alberoCoda.binPadre(n));
       }
    }
}

template <class T>
void CodaPAlberoBin<T>::fixDown(nodo n) {
    /*** assicuriamoci che n non sia un nodo foglia ma abbia dei figli con cui confrontarsi ***/
    if(!alberoCoda.sinVuoto(n)){
        /*** figlioDes è vuoto, quindi il nodo ha solo figlioSin per confronto priorità ***/
        if(alberoCoda.desVuoto(n)){
            if(alberoCoda.leggiNodo(n) > alberoCoda.leggiNodo(alberoCoda.binFiglioSin(n))){
                switchElem(n, alberoCoda.binFiglioSin(n));
                fixDown(alberoCoda.binFiglioSin(n));
            }
        }
        /*** figlioDes è occupato, quindi dobbiamo scambiare n con chi ha priorità piu' alta tra i figli ***/
        else{
            /*** controlliamo se figlioSin ha priorità più alta di figlioDes ***/
            if (alberoCoda.leggiNodo(alberoCoda.binFiglioSin(n)) < alberoCoda.leggiNodo(alberoCoda.binFiglioDes(n))){
                if(alberoCoda.leggiNodo(n) > alberoCoda.leggiNodo(alberoCoda.binFiglioSin(n))){
                    switchElem(n, alberoCoda.binFiglioSin(n));
                    fixDown(alberoCoda.binFiglioSin(n));
                }
            }
            /*** figlioDes ha priorità più alta di figlioSin, confrontiamolo con n ***/
            else{
                if(alberoCoda.leggiNodo(n) > alberoCoda.leggiNodo(alberoCoda.binFiglioDes(n))){
                    switchElem(n, alberoCoda.binFiglioDes(n));
                    fixDown(alberoCoda.binFiglioDes(n));
                }
            }
        }
    }
}

template <class T>
void CodaPAlberoBin<T>::print() {
    alberoCoda.print();
}


template <class T>
void CodaPAlberoBin<T>::switchElem(nodo n, nodo m) {
    tipoElem temp_e = alberoCoda.leggiNodo(n);
    alberoCoda.scriviNodo(alberoCoda.leggiNodo(m), n);
    alberoCoda.scriviNodo(temp_e, m);
}
#endif
