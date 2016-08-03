#ifndef GRAFOPUNT_H_
#define GRAFOPUNT_H_


#include "grafo.h"
#include "nodoGrafo.h"


template < class T, class P >
class GrafoPunt: public Grafo<T, NodoGrafo<T,P>, P>{

public:
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::nodo nodo;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::tipoElem tipoElem;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::peso peso;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::List List;

	/*** constructors ***/
    GrafoPunt();

    /*****copy constructor*****/
    GrafoPunt(const GrafoPunt<T,P> &);

    /*****destructor*****/
    ~GrafoPunt();

    /*****operators*****/










private:
    List nodi;

};







#endif
