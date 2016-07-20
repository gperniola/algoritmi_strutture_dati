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
    bool ultimoFratello(nodo)const;
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

template <class T>
AlberoNPunt<T>::AlberoNPunt() {
    this->creaAlbero();
}

template <class T>
AlberoNPunt<T>::~AlberoNPunt(){
    cancSottoalbero(radice);
}

template <class T>
void AlberoNPunt<T>::creaAlbero() {
    radice = nullptr;
}

template <class T>
bool AlberoNPunt<T>::alberoVuoto() const{
    if(radice == nullptr)
        return true;
    else
        return false;
}

template <class T>
typename AlberoNPunt<T>::nodo AlberoNPunt<T>::radice() const {
    if(!alberoVuoto())
        return radice;
    else throw EmptyTree();
}

template <class T>
typename AlberoNPunt<T>::nodo AlberoNPunt<T>::padre(nodo n) const{
    if(!alberoVuoto()){
        if (n->get_livello() > 0)
            return n->get_padre();
        else return n;
    }else throw EmptyTree();
}

template <class T>
typename AlberoNPunt<T>::bool AlberoNPunt<T>::foglia(nodo n) const{
    if (n->get_primoFiglio() == nullptr)
        return true;
    else return false;
}

template <class T>
typename AlberoNPunt<T>::bool AlberoNPunt<T>::ultimoFratello(nodo n) const{
    if (n->get_succFratello() == nullptr)
        return true;
    else return false;
}

template <class T>
typename AlberoNPunt<T>::nodo AlberoNPunt<T>::primoFiglio(nodo n) const{
        if(!alberoVuoto()){
            if(!foglia(n))
                return n->get_primoFiglio();
            else return NULL;
        }else throw EmptyTree();
}

template <class T>
typename AlberoNPunt<T>::bool AlberoNPunt<T>::succFratello(nodo n) const{
        if(!alberoVuoto()){
            if(!ultimoFratello(n))
                return n->get_succFratello();
            else return NULL;
        }else throw EmptyTree();
}

template <class T>
void AlberoNPunt<T>::insRadice(){
    if (this->alberoVuoto()){
        radice = new Cell<T>();
        radice->set_livello(0);
    }
    else throw RootExists();
}

template <class T>
void AlberoNPunt<T>::insRadice(nodo n){
    if (this->alberoVuoto()){
        radice = n;
        radice->set_livello(0);
    }
    else throw RootExists();
}

template <class T>
void AlberoNPunt<T>::insPrimoSottoalbero(nodo n, AlberoN<T,N>& T){
    if (!alberoVuoto() && !T.alberoVuoto()){
        if(foglia(n)){
            n->set_primoFiglio(T.radice());
        }
        else{
            T.radice()->set_succFratello(n->get_primoFiglio());
            n->set_primoFiglio(T.radice());
        }
        T.radice()->set_padre(n);
    }else throw EmptyTree();
}

template <class T>
void AlberoNPunt<T>::insSottoalbero(nodo n, AlberoN<T,N>& T){
        if (!alberoVuoto() && !T.alberoVuoto()){
            if(ultimoFratello(n)){
                n->set_succFratello(T.radice());
            }
            else{
                T.radice()->set_succFratello(n->get_succFratello());
                n->set_succFratello(T.radice());
            }
            T.radice()->set_padre(n->get_padre());
        }else throw EmptyTree();
}

template <class T>
void AlberoNPunt<T>::cancSottoalbero(nodo n){
    if (!alberoVuoto()){
        if (padre(n) != nullptr){
            if(primoFiglio(padre(n)) == n){
            //è primofiglio
                if(!ultimoFratello(n))
                    padre(n)->set_primoFiglio(succFratello(n));
            }else{
            // è un figlio successivo e ha dei fratelli precedenti
                nodo temp = primoFiglio(padre(n));
                bool found = false;
                while(!ultimoFratello(temp) && found == false){
                    if(temp->get_succFratello() == n){
                            temp->set_succFratello(n->get_succFratello());
                            found = true;
                    }
                temp = temp->get_succFratello();
                }
            }
        }
        while(!foglia(n))
            cancSottoalbero(primoFiglio(n));
        delete n;
    }else throw EmptyTree();
}

template <class T>
void AlberoNPunt<T>::scriviNodo(tipoElem e, nodo n) {
    n->set_element(e);
}

template <class T>
typename AlberoNPunt<T>::tipoElem AlberoNPunt<T>::leggiNodo(nodo n) const{
    return n->get_element();
}

#endif
