#ifndef ALBEROBINPUNT_H
#define ALBEROBINPUNT_H


#include "alberoBin.h"
#include "cell.h"


template <class T>
class AlberoBinPunt : public AlberoBin<T, Cell<T>*>{

public:
    typedef typename AlberoBin<T, Cell<T>*>::tipoElem tipoElem;
    typedef typename AlberoBin<T, Cell<T>*>::nodo nodo;

    /*****constructors*****/
    AlberoBinPunt();

    /*****copy constructor*****/
    //AlberoBinPunt(const AlberoBinPunt<T> &);

    /*****destructor*****/
    ~AlberoBinPunt();

    /*****operators*****/
    void creaAlberoBin();
    bool alberoBinVuoto() const;
    nodo binRadice() const;
    nodo binPadre(nodo) const;
    nodo binFiglioSin(nodo) const;
    nodo binFiglioDes(nodo) const;
    bool sinVuoto(nodo) const;
    bool desVuoto(nodo) const;

    void scriviNodo(tipoElem, nodo);
    tipoElem leggiNodo(nodo) const;

    void costrBinAlbero(AlberoBin<T,Cell<T>*>&, AlberoBin<T,Cell<T>*>&);
    void cancsottoAlbero(nodo);

    void insBinRadice();
    void insFiglioSin(nodo, AlberoBin<T,Cell<T>*>&);
    void insFiglioDes(nodo, AlberoBin<T,Cell<T>*>&);

    int getLivello(nodo) const;

private:
    nodo radice;
};

template <class T>
AlberoBinPunt<T>::AlberoBinPunt() {
    this->creaAlberoBin();
}

template <class T>
AlberoBinPunt<T>::~AlberoBinPunt(){
    cancsottoAlbero(radice);
}

template <class T>
void AlberoBinPunt<T>::creaAlberoBin() {
    radice = nullptr;
}

template <class T>
bool AlberoBinPunt<T>::alberoBinVuoto() const{
    if(radice == nullptr)
        return true;
    else
        return false;
}

template <class T>
typename AlberoBinPunt<T>::nodo AlberoBinPunt<T>::binRadice() const {
    return radice;
}

template <class T>
typename AlberoBinPunt<T>::nodo AlberoBinPunt<T>::binPadre(nodo n) const{
    return n->get_padre();
}

template <class T>
typename AlberoBinPunt<T>::nodo AlberoBinPunt<T>::binFiglioSin(nodo n) const{
    return n->get_figlioSin();
}

template <class T>
typename AlberoBinPunt<T>::nodo AlberoBinPunt<T>::binFiglioDes(nodo n) const{
    return n->get_figlioDes();
}

template <class T>
bool AlberoBinPunt<T>::sinVuoto(nodo n) const{
    if(n->get_figlioSin() == nullptr)
        return true;
    else
        return false;
}

template <class T>
bool AlberoBinPunt<T>::desVuoto(nodo n) const{
    if(n->get_figlioDes() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void AlberoBinPunt<T>::scriviNodo(tipoElem e, nodo n) {
    n->set_element(e);
}

template <class T>
typename AlberoBinPunt<T>::tipoElem AlberoBinPunt<T>::leggiNodo(nodo n) const{
    //cout << "lvl: " << n->get_livello() << " value: ";
    return n->get_element();
}

template <class T>
void AlberoBinPunt<T>::costrBinAlbero(AlberoBin<T,Cell<T>*>& A, AlberoBin<T,Cell<T>*>& B){
    if (this->alberoBinVuoto()){
        this->insBinRadice();

        if(!A.alberoBinVuoto())
            this->insFiglioSin(radice, A);
        if(!B.alberoBinVuoto())
            this->insFiglioDes(radice, B);
    }

}

template <class T>
void AlberoBinPunt<T>::cancsottoAlbero(nodo n){
    if(!alberoBinVuoto()){
        //cout << "FALSE" << endl;
        if (n->get_padre() != nullptr){
        if(n->get_padre()->get_figlioSin() == n){
            //cout << n->get_element() << " is figliosx of " << n->get_padre()->get_element() << endl;
            n->get_padre()->set_figlioSin(nullptr);
            }
        else if (n->get_padre()->get_figlioDes() == n){
            //cout << n->get_element() << " is figliosx of " << n->get_padre()->get_element() << endl;
            n->get_padre()->set_figlioDes(nullptr);
            }
        }
        //cout << "getting sons..." << endl;
        if(n->get_figlioSin() != nullptr)
            cancsottoAlbero(n->get_figlioSin());
        if(n->get_figlioDes() != nullptr)
            cancsottoAlbero(n->get_figlioDes());

        //cout << "deleting " << n->get_element() << "..." << endl;
        delete n;
        }
}

template <class T>
void AlberoBinPunt<T>::insBinRadice(){
    if (this->alberoBinVuoto()){
        radice = new Cell<T>();
        radice->set_livello(0);
    }
}

template <class T>
void AlberoBinPunt<T>::insFiglioSin(nodo n, AlberoBin<T,Cell<T>*>& A){
    if (n->get_figlioSin() == nullptr){
        if(A.alberoBinVuoto())
            A.insBinRadice();

        nodo sinRad = A.binRadice();
        sinRad->set_padre(n);
        sinRad->set_livello(n->get_livello() + 1);
        n->set_figlioSin(sinRad);
    }
}

template <class T>
void AlberoBinPunt<T>::insFiglioDes(nodo n, AlberoBin<T,Cell<T>*>& A){
    if (n->get_figlioDes() == nullptr){
        if(A.alberoBinVuoto())
            A.insBinRadice();

        nodo desRad = A.binRadice();
        desRad->set_padre(n);
        desRad->set_livello(n->get_livello() + 1);
        n->set_figlioDes(desRad);
    }
}

template <class T>
int AlberoBinPunt<T>::getLivello(nodo n) const{
    return n->get_livello();
}




#endif
