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

    NodoGrafo<T,P>& operator = (const NodoGrafo<T,P> &);
    bool operator == (const NodoGrafo<T,P> &) const;
    bool operator < (const NodoGrafo<T,P> &) const;
    bool operator <= (const NodoGrafo<T,P> &) const;
    bool operator > (const NodoGrafo<T,P> &) const;

    private:
    tipoElem etichetta;
    int numArchi;
    List_pointer<NodoGrafo<T,P>>* archi;

};



template <class T, class P>
NodoGrafo<T,P>& NodoGrafo<T,P>::operator = (const NodoGrafo<T,P> &n){}

template <class T, class P>
bool NodoGrafo<T,P>::operator == (const NodoGrafo<T,P> &n) const{}

template <class T, class P>
bool NodoGrafo<T,P>::operator < (const NodoGrafo<T,P> &n) const{}

template <class T, class P>
bool NodoGrafo<T,P>::operator <= (const NodoGrafo<T,P> &n) const{}

template <class T, class P>
bool NodoGrafo<T,P>::operator > (const NodoGrafo<T,P> &n) const{}
