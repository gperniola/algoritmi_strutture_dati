#ifndef GRAFOPUNT_H_
#define GRAFOPUNT_H_


#include "grafo.h"
#include "nodoGrafo.h"


template < class T, class P >
class GrafoPunt: public Grafo<T, NodoGrafo<T>, P>{

public:
    //typedef P int;
	typedef typename Grafo<T, NodoGrafo<T>, int>::nodo nodo;
	typedef typename Grafo<T, NodoGrafo<T>, int>::tipoElem tipoElem;
	typedef typename Grafo<T, NodoGrafo<T>, int>::peso peso;
	typedef typename Grafo<T, NodoGrafo<T>, int>::List ListaAdiacenti;
	typedef List_pointer<nodo> List;

	/*** constructors ***/
    GrafoPunt();

    /*****copy constructor*****/
    //GrafoPunt(const GrafoPunt<T> &);

    /*****destructor*****/
    ~GrafoPunt();

    /*****operators*****/
    void crea();
    bool vuoto();
    void insNodo(nodo &);
    void insArco(nodo &, nodo &);
    void cancNodo(nodo &);
    bool esisteNodo(nodo &);
    bool esisteArco(nodo &, nodo &);

    tipoElem leggiNodo(nodo &);
    void scriviNodo(nodo &, tipoElem);

    void print();

private:
    List* nodi;

};

template <class T, class P>
GrafoPunt<T,P>::GrafoPunt(){
    this->crea();
}

template <class T, class P>
GrafoPunt<T,P>::~GrafoPunt(){
    nodi->clear();
}

template <class T, class P>
void GrafoPunt<T,P>::crea(){
    nodi = new List();
}

template <class T, class P>
bool GrafoPunt<T,P>::vuoto(){
    return nodi->empty();
}

template <class T, class P>
void GrafoPunt<T,P>::insNodo(nodo &n){
    if(!esisteNodo(n))
        nodi->insert_ordered(n);
}

template <class T, class P>
void GrafoPunt<T,P>::insArco(nodo &n, nodo &m){
        if(!esisteArco(n,m)){
            n.addArco(m);
        }
}




template <class T, class P>
void GrafoPunt<T,P>::cancNodo(nodo &n){
    if(esisteNodo(n))
        nodi->erase(nodi->linear_ord_search(n));
}

template <class T, class P>
bool GrafoPunt<T,P>::esisteNodo(nodo &n){

    if(nodi->linear_search(n) == NULL)
        return false;
    else
        return true;
}


template <class T, class P>
bool GrafoPunt<T,P>::esisteArco(nodo &n, nodo &m){

    if(esisteNodo(n) && esisteNodo(m)){
        return n.cercaArco(m);
    }
    else return false;
}





template <class T, class P>
typename GrafoPunt<T,P>::tipoElem GrafoPunt<T,P>::leggiNodo(nodo &n){
    if(esisteNodo(n))
        return n.getEtichetta();
}

template <class T, class P>
void GrafoPunt<T,P>::scriviNodo(nodo &n, tipoElem e){
        n.setEtichetta(e);
}

template <class T, class P>
void GrafoPunt<T,P>::print(){
       cout << "Nodi: " << *nodi;
}

#endif
