#ifndef GRAFOPUNT_H_
#define GRAFOPUNT_H_


#include "grafo.h"
//#include "nodoGrafo.h"


template < class T, class P> class NodoGrafo{
    public:
    typedef T tipoElem;
    typedef P peso;

};


template < class T, class P >
class GrafoPunt: public Grafo<T, NodoGrafo<T,P>, P>{

public:
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::nodo nodo;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::tipoElem tipoElem;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::peso peso;
	typedef typename Grafo<T, NodoGrafo<T,P>, P>::List List;

private:
    List nodi;

};







#endif
