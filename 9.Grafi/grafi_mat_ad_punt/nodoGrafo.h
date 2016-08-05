#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_





/*template < class P> class Arco{
public:
    typedef P peso;
    //typedef N nodoPunt;

private:
    peso pe;
    //nodoPunt* n;



};*/


template < class T, class P> class NodoGrafo{
    public:
    typedef T tipoElem;
    typedef P peso;



    NodoGrafo();
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);



    NodoGrafo<T,P>& operator = (const NodoGrafo<T,P> &);
    bool operator == (const NodoGrafo<T,P> &) const;
    bool operator < (const NodoGrafo<T,P> &) const;
    bool operator <= (const NodoGrafo<T,P> &) const;
    bool operator > (const NodoGrafo<T,P> &) const;

    private:
    tipoElem etichetta;
    int numArchi;
    //List_pointer<NodoGrafo<T,P>*> archi;

};


template <class T, class P>
NodoGrafo<T,P>::NodoGrafo(){
}

template <class T, class P>
NodoGrafo<T,P>::~NodoGrafo(){
    cout << "calling nodo dest" << endl;
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
NodoGrafo<T,P>& NodoGrafo<T,P>::operator = (const NodoGrafo<T,P> &n){}

template <class T, class P>
bool NodoGrafo<T,P>::operator == (const NodoGrafo<T,P> &n) const{
    cout << this->getEtichetta() << " == " << n.getEtichetta() << endl;
    if(this->getEtichetta() == n.getEtichetta())
        return true;
    else
        return false;
}

template <class T, class P>
bool NodoGrafo<T,P>::operator < (const NodoGrafo<T,P> &n) const{
    if(this->getEtichetta() < n.getEtichetta())
        return true;
    else
        return false;
}

template <class T, class P>
bool NodoGrafo<T,P>::operator <= (const NodoGrafo<T,P> &n) const{
    if(this->getEtichetta() <= n.getEtichetta())
        return true;
    else
        return false;
}

template <class T, class P>
bool NodoGrafo<T,P>::operator > (const NodoGrafo<T,P> &n) const{
    cout << this->getEtichetta() << " > " << n.getEtichetta() << endl;
    if(getEtichetta() > n.getEtichetta())
            return true;
        else
            return false;
}


template< class T, class P >
ostream& operator<<(ostream& os, const NodoGrafo<T,P> &n){
    os << "eti: " << n.getEtichetta();
    return os;
}

#endif
