#ifndef DIZIONARIO_H_INCLUDED
#define DIZIONARIO_H_INCLUDED

using std::ostream;
using std::cout;
using std::endl;

//********************************************
//CLASS MYPAIR
//********************************************

template <class K, class E>
class mypair{
public:
    K first;
    E second;

    mypair(){}
    mypair(K&,E&);
    mypair(K&);

    mypair<K,E>& operator = (const mypair<K,E> &the_pair);
    bool operator == (const mypair<K,E> &the_pair) const;
    bool operator <= (const mypair<K,E> &the_pair) const;
    bool operator < (const mypair<K,E> &the_pair) const;
    bool operator > (const mypair<K,E> &the_pair) const;
};

template <class K, class E>
mypair<K,E>::mypair(K &the_key, E &the_value){
    first = the_key;
    second = the_value;
}

template <class K, class E>
mypair<K,E>::mypair(K &the_key){
    first = the_key;
}

template <class K, class E>
ostream& operator << (ostream& os, const mypair<K,E> &the_pair){
    os << "<" << the_pair.first << ", " << the_pair.second << ">";
    return os;
}


template <class K, class E>
mypair<K,E>& mypair<K,E>::operator = (const mypair<K,E> &the_pair){
        first = the_pair.first;
        second = the_pair.second;
        return *this;
}

template <class K, class E>
bool mypair<K,E>::operator == (const mypair<K,E> &the_pair) const{
    if(first == the_pair.first)
        return true;
    return false;
}

template <class K, class E>
bool mypair<K,E>::operator <= (const mypair<K,E> &the_pair) const{
    if(first <= the_pair.first)
        return true;
    return false;
}

template <class K, class E>
bool mypair<K,E>::operator < (const mypair<K,E> &the_pair) const{
    if(first < the_pair.first){
        return true;
        }
    return false;
}

template <class K, class E>
bool mypair<K,E>::operator > (const mypair<K,E> &the_pair) const{
    if(first > the_pair.first){
        return true;
        }
    return false;
}

//********************************************
//VIRTUAL CLASS DIZIONARIO
//********************************************

template <class K, class E>
class Dizionario{
public:

    virtual void creaDizionario() = 0;
    virtual bool dizionarioVuoto() const = 0;
    virtual bool appartiene(K&) const = 0;
    virtual void inserisci(mypair<K,E>) = 0;
    virtual void cancella(K&) = 0;
    virtual E recupera(K&) const = 0;

    virtual int size() const = 0;

    virtual void modifica(K, E);

};

template <class K, class E>
void Dizionario<K,E>::modifica(K the_key, E the_value){
    mypair<K,E> the_pair;
    the_pair.first = the_key;
    the_pair.second = the_value;

    cancella(the_key);
    inserisci(the_pair);

}



#endif // DIZIONARIO_H_INCLUDED
