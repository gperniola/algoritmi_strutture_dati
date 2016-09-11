#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_


#include <iostream>


/*template <class P, class N> class Arco{
public:
    typedef P peso;
    typedef N nodoPunt;

    Arco();
    ~Arco();

    void setNodoPunt(nodoPunt &);
    void setPeso(peso);

    nodoPunt getNodoPunt() const;
    peso getPeso() const;

    Arco<P,N>& operator = (const Arco<P,N> &);
    bool operator == (const Arco<P,N> &) const;
    bool operator < (const Arco<P,N> &) const;
    bool operator <= (const Arco<P,N> &) const;
    bool operator > (const Arco<P,N> &) const;

private:
    peso pe;
    nodoPunt* nodoPuntato;

};

template <class P, class N>
Arco<P,N>::Arco(){
}

template <class P, class N>
Arco<P,N>::~Arco(){
    //cout << "calling nodo dest" << endl;
}

template <class P, class N>
void Arco<P,N>::setNodoPunt(nodoPunt &n){
    nodoPuntato = &n;
}

template <class P, class N>
void Arco<P,N>::setPeso(peso p){
    pe = p;
}

template <class P, class N>
typename Arco<P,N>::nodoPunt Arco<P,N>::getNodoPunt() const{
    return *nodoPuntato;
}

template <class P, class N>
typename Arco<P,N>::peso Arco<P,N>::getPeso() const{
    return pe;
}

template <class P, class N>
Arco<P,N>& Arco<P,N>::operator = (const Arco<P,N> &a){

}

template <class P, class N>
bool Arco<P,N>::operator == (const Arco<P,N> &a) const{
    //return this->getNodoPunt() == a.getNodoPunt();
    cout << "BOOM : "<< this->getNodoPunt() << " --- " << a.getNodoPunt() << endl;
    return this->getNodoPunt() == a.getNodoPunt();
}

template <class P, class N>
bool Arco<P,N>::operator < (const Arco<P,N> &a) const{
    return this->getPeso() < a.getPeso();
}

template <class P, class N>
bool Arco<P,N>::operator <= (const Arco<P,N> &a) const{
    return this->getPeso() <= a.getPeso();
}

template <class P, class N>
bool Arco<P,N>::operator > (const Arco<P,N> &a) const{
    return this->getPeso() > a.getPeso();
}

template< class P, class N >
ostream& operator<<(ostream& os, const Arco<P,N> &a){
    os <<"--> " << a.getNodoPunt() << " - peso: " << a.getPeso();
    return os;
}*/



template <class T> class NodoGrafo{
public:
    typedef T tipoElem;

    struct arco{
        unsigned int peso;
        NodoGrafo *nodoPunt;
    };
    typedef List_pointer<arco> listaArchi;





    NodoGrafo();
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);
    void addArco(NodoGrafo &);
    listaArchi* getArchi();
    bool cercaArco(NodoGrafo &);

    NodoGrafo<T>& operator = (const NodoGrafo<T> &);
    bool operator == (const NodoGrafo<T> &) const;
    bool operator < (const NodoGrafo<T> &) const;
    bool operator <= (const NodoGrafo<T> &) const;
    bool operator > (const NodoGrafo<T> &) const;

    bool operator == (const typename NodoGrafo<T>::arco &) const;
    bool operator < (const typename NodoGrafo<T>::arco &) const;
    bool operator <= (const typename NodoGrafo<T>::arco &) const;
    bool operator > (const typename NodoGrafo<T>::arco &) const;

private:
    tipoElem etichetta;
    int numArchi;
    listaArchi* archi;

};


template <class T>
NodoGrafo<T>::NodoGrafo(){
    archi = new listaArchi();
}

template <class T>
NodoGrafo<T>::~NodoGrafo(){
    //cout << "calling nodo dest" << endl;
}



template <class T>
void NodoGrafo<T>::setEtichetta(tipoElem e){
    this->etichetta = e;
}

template <class T>
typename NodoGrafo<T>::tipoElem NodoGrafo<T>::getEtichetta() const{
    return etichetta;
}

template <class T>
void NodoGrafo<T>::addArco(NodoGrafo &n){
    arco *new_arco = new arco();
    new_arco->nodoPunt = &n;
    new_arco->peso = 1;
    archi->insert_ordered(*new_arco);
}

template <class T>
bool NodoGrafo<T>::cercaArco(NodoGrafo &m){
    arco *a = new arco();
    a->nodoPunt = &m;
    a->peso = 1;
    cout << "searching in NodoGrafo.cercaArco():" <<endl << "new arco is: " << a << endl;
    if(archi->linear_ord_search(*a) == NULL){
        cout << "searched false" << endl;
        return false;
        }
    else{
        cout << "searched true" << endl;
        return true;
        }
        //cout << "doing this" << endl;
        //return false;
}


template <class T>
NodoGrafo<T>& NodoGrafo<T>::operator = (const NodoGrafo<T> &n){
    etichetta = n.getEtichetta();

}


template <class T>
bool NodoGrafo<T>::operator == (const NodoGrafo<T> &n) const{
    return this->getEtichetta() == n.getEtichetta();;
}

template <class T>
bool NodoGrafo<T>::operator < (const NodoGrafo<T> &n) const{
    return this->getEtichetta() < n.getEtichetta();
}


template <class T>
bool NodoGrafo<T>::operator <= (const NodoGrafo<T> &n) const{
    return this->getEtichetta() <= n.getEtichetta();
}

template <class T>
bool NodoGrafo<T>::operator > (const NodoGrafo<T> &n) const{
    return getEtichetta() > n.getEtichetta();
}


template< class T >
ostream& operator<<(ostream& os, const NodoGrafo<T> &n){
    os << "eti: " << n.getEtichetta();
    return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,const typename NodoGrafo<T>::arco &a){
        os <<"--> " << a.nodoPunt << " - peso: " << a.peso;
        return os;
}


template<class T>
bool NodoGrafo<T>::operator == (const typename NodoGrafo<T>::arco &a) const{
    //return this->getNodoPunt() == a.getNodoPunt();
    //cout << "BOOM : "<< this->getNodoPunt() << " --- " << a.getNodoPunt() << endl;
    return this->nodoPunt == a.nodoPunt;
}

template<class T>
bool NodoGrafo<T>::operator < (const typename NodoGrafo<T>::arco &a) const{
    return this->peso < a.peso;
}

template<class T>
bool NodoGrafo<T>::operator <= (const typename NodoGrafo<T>::arco &a) const{
    return this->peso <= a.peso;
}

template<class T>
bool NodoGrafo<T>::operator > (const typename NodoGrafo<T>::arco &a) const{
    return this->peso > a.peso;
}





#endif
