#ifndef GRAFO_H_
#define GRAFO_H_

#include "list_pointer.h"
#include "coda_punt.h"

template < class T, class N, class P > class Grafo {
public:

	/*** Tipi ***/
	typedef T tipoElem;
	typedef N nodo;
    typedef P peso;
    typedef List_pointer<nodo*> List;
    typedef Coda_punt<nodo*> Coda;

    /*** Operatori ***/
    virtual void crea() = 0;
    virtual bool vuoto() = 0;
    virtual void insNodo(nodo) = 0;
    virtual void insArco(nodo, nodo, peso) = 0;
    virtual void cancNodo(nodo) = 0;
    virtual void cancArco(nodo, nodo) = 0;

    virtual bool esisteNodo(nodo) = 0;
    virtual bool esisteArco(nodo, nodo) = 0;

    virtual tipoElem leggiNodo(nodo) = 0;
    virtual void scriviNodo(nodo,tipoElem) = 0;

    virtual List* adiacenti(nodo) = 0;
    virtual peso leggiPeso(nodo, nodo) = 0;
    virtual void scriviPeso(nodo, nodo, peso) = 0;

    /*** Visite ***/
    virtual void DFS(nodo);
    virtual void BFS(nodo);
    /*** Funzioni di servizio ***/
    static void printAdiacenti(List*);
    virtual bool getVisitato(nodo) = 0;
    virtual void setVisitato(nodo, bool) = 0;
    virtual void setAllVisitato(bool) = 0;

private:
    Coda* codaNodi = new Coda();
};

template <class T, class N,class P>
void Grafo<T,N,P>::DFS(nodo n){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p))
                cout <<"("<<leggiNodo(n)<<")" << endl;
            else{
                while(!ad->end(p)){
                    cout <<"("<<leggiNodo(n)<<")--"<< leggiPeso(n,*ad->read(p)) <<"-->";
                    DFS(*ad->read(p));
                    p = ad->next(p);
                }
            }
            delete(ad);
        }else cout <<"("<<leggiNodo(n)<<")"<<" [already visited]" << endl;
    }
}

template <class T, class N,class P>
void Grafo<T,N,P>::BFS(nodo n){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p))
                cout <<"("<<leggiNodo(n)<<")" << endl;
            else{
                while(!ad->end(p)){
                    cout <<"("<<leggiNodo(n)<<")--"<< leggiPeso(n,*ad->read(p)) <<"-->("<< leggiNodo(*ad->read(p)) << "), ";
                    if(!getVisitato(*ad->read(p))){
                        codaNodi->inCoda(ad->read(p));
                    }
                    p = ad->next(p);
                }
                cout << endl;
                while(!codaNodi->codaVuota()){
                    nodo* np = codaNodi->leggiCoda();
                    codaNodi->fuoriCoda();
                    BFS(*np);
                }
            }
            delete(ad);
        }//else cout <<"("<<leggiNodo(n)<<")"<<" [already visited]" << endl;
    }
}


template <class T, class N,class P>
void Grafo<T,N,P>::printAdiacenti(List* l){
    auto p = l->begin();
    while(!l->end(p)){
        cout << l->read(p)->getEtichetta() << ", ";
        p = l->next(p);
    }
}

#endif
