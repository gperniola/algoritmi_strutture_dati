#ifndef GRAFO_H_
#define GRAFO_H_

#include "list_pointer.h"

template < class T, class N, class P > class Grafo {
public:

	/*** Tipi ***/
	typedef T tipoElem;
	typedef N nodo;
    typedef P peso;
    typedef List_pointer<nodo> List;

    /*** Operatori ***/
    virtual void crea() = 0;
    virtual bool vuoto() = 0;
    virtual void insNodo(nodo &) = 0;
    virtual void insArco(nodo &, nodo &) = 0;
    virtual void cancNodo(nodo &) = 0;
    //virtual void cancArco(nodo, nodo) = 0;
    //virtual List adiacenti(nodo) = 0;
    virtual bool esisteNodo(nodo &) = 0;
    virtual bool esisteArco(nodo &, nodo &) = 0;

    virtual tipoElem leggiNodo(nodo &) = 0;
    virtual void scriviNodo(nodo &, tipoElem) = 0;
    /*virtual peso leggiPeso(nodo, nodo) = 0;
    virtual void scriviPeso(nodo, nodo) = 0;

    virtual int numNodi() = 0;
    virtual int numArchi() = 0;


    /*** Visite ***/
   /* virtual void DFS(nodo);
    virtual void BFS(nodo);*/

};

#endif
