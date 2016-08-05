#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_





template <class P, class N> class Arco{
public:
    typedef P peso;
    typedef N nodoPunt;

    Arco();
    ~Arco();

    void setNodoPunt(nodoPunt &);
    nodoPunt getNodoPunt();

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
typename Arco<P,N>::nodoPunt Arco<P,N>::getNodoPunt(){
    return &nodoPuntato;
}









template < class T, class P> class NodoGrafo{
    public:
    typedef T tipoElem;
    typedef P peso;



    NodoGrafo();
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);
    void addArco(NodoGrafo &);



    NodoGrafo<T,P>& operator = (const NodoGrafo<T,P> &);
    bool operator == (const NodoGrafo<T,P> &) const;
    bool operator < (const NodoGrafo<T,P> &) const;
    bool operator <= (const NodoGrafo<T,P> &) const;
    bool operator > (const NodoGrafo<T,P> &) const;

    private:
    tipoElem etichetta;
    int numArchi;
    List_pointer<Arco<P,NodoGrafo<T,P>>>* archi;

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
   //// typename List_pointer<Arco<P,NodoGrafo<T,P>>>*::position p;
   // Arco *new_arco = new Arco();
 //   new_arco->setNodoPunt(n);
  //  archi->insert(new_arco, p = archi->begin());
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
