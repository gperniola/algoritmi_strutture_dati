#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_





template <class P, class N> class Arco{
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
    nodoPuntato = n;
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
//  todo

}

template <class P, class N>
bool Arco<P,N>::operator == (const Arco<P,N> &a) const{
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

template < class T, class P> class NodoGrafo{
    public:
    typedef T tipoElem;
    typedef P peso;
    typedef List_pointer<Arco<P,NodoGrafo>> Lista;


    NodoGrafo();
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);
    void addArco(NodoGrafo &);
    Lista* getArchi();



    NodoGrafo<T,P>& operator = (const NodoGrafo<T,P> &);
    bool operator == (const NodoGrafo<T,P> &) const;
    bool operator < (const NodoGrafo<T,P> &) const;
    bool operator <= (const NodoGrafo<T,P> &) const;
    bool operator > (const NodoGrafo<T,P> &) const;

    private:
    tipoElem etichetta;
    int numArchi;
    Lista* archi;

};


template <class T, class P>
NodoGrafo<T,P>::NodoGrafo(){
    archi = new List_pointer<Arco<P,NodoGrafo<T,P>>>();
}

template <class T, class P>
NodoGrafo<T,P>::~NodoGrafo(){
    //cout << "calling nodo dest" << endl;
}



template <class T, class P>
void NodoGrafo<T,P>::setEtichetta(tipoElem e){
    this->etichetta = e;
}

template <class T, class P>
typename NodoGrafo<T,P>::tipoElem NodoGrafo<T,P>::getEtichetta() const{
    return etichetta;
}

template <class T, class P>
void NodoGrafo<T,P>::addArco(NodoGrafo &n){
    typename Lista::position p;
    Arco<P,NodoGrafo> *new_arco = new Arco<P,NodoGrafo>();
    new_arco->setNodoPunt(n);
    //new_arco->setPeso(1);
    archi->insert_ordered(new_arco);
}



template <class T, class P>
NodoGrafo<T,P>& NodoGrafo<T,P>::operator = (const NodoGrafo<T,P> &n){
    etichetta = n.getEtichetta();

}

template <class T, class P>
bool NodoGrafo<T,P>::operator == (const NodoGrafo<T,P> &n) const{
    return this->getEtichetta() == n.getEtichetta();;
}

template <class T, class P>
bool NodoGrafo<T,P>::operator < (const NodoGrafo<T,P> &n) const{
    return this->getEtichetta() < n.getEtichetta();
}


template <class T, class P>
bool NodoGrafo<T,P>::operator <= (const NodoGrafo<T,P> &n) const{
    return this->getEtichetta() <= n.getEtichetta();
}

template <class T, class P>
bool NodoGrafo<T,P>::operator > (const NodoGrafo<T,P> &n) const{
    return getEtichetta() > n.getEtichetta();
}


template< class T, class P >
ostream& operator<<(ostream& os, const NodoGrafo<T,P> &n){
    os << "eti: " << n.getEtichetta();
    return os;
}

#endif
