#ifndef ALBERONPUNT_H
#define ALBERONPUNT_H


#include "alberoN.h"
#include "cell.h"
#include "exceptions.h"

template <class T>
class AlberoNPunt : public AlberoN<T, Cell<T>*>{

public:
    typedef typename AlberoN<T, Cell<T>*>::tipoElem tipoElem;
    typedef typename AlberoN<T, Cell<T>*>::nodo nodo;

    /*****constructors*****/
    AlberoNPunt();

    /*****copy constructor*****/
    //AlberoNPunt(const AlberoNPunt<T> &);

    /*****destructor*****/
    ~AlberoNPunt();

    /*****operators*****/
    void creaAlbero();
    bool alberoVuoto() const;
    nodo radice()const;
    nodo padre(nodo)const;
    bool foglia(nodo)const;
    nodo primoFiglio(nodo)const;
    nodo succFratello(nodo)const;

    void insRadice();
    void insRadice(nodo);

    void insPrimoSottoalbero(nodo, AlberoN<T,N>&);
    void insSottoalbero(nodo, AlberoN<T,N>&);
    void cancSottoalbero(nodo);

    void scriviNodo(tipoElem, nodo);
    tipoElem leggiNodo(nodo) const;

    int getLivello(nodo) const;

private:
    nodo radice;
};








#endif
