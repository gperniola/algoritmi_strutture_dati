#ifndef HASH_TRABOCCO_H_INCLUDED
#define HASH_TRABOCCO_H_INCLUDED

#include <string>
#include <typeinfo>
#include <iostream>

#include "dizionario.h"
#include "list_pointer.h"

#define MAX 100

using namespace std;

template<class T>
class hash_{
public:
  size_t operator()(const T the_key) const;
};

/* a specialization with type string */
template<>
class hash_<string>
{
public:
  size_t operator()(const string the_key) const {
    unsigned long hash_value = 0;
    int length = (int) the_key.length();
    for (int i=0; i<length; i++)
      hash_value = 5 * hash_value + the_key.at(i);
    return size_t(hash_value);
  }
};

template <class K, class E>
class Hash_trabocco: public Dizionario <K,E>{

public:

    Hash_trabocco();
    Hash_trabocco(int);
    ~Hash_trabocco();

    void creaDizionario();
    bool dizionarioVuoto() const;
    bool appartiene(K&) const;
    void inserisci(mypair<K,E>);
    void cancella(K&);
    E recupera(K&) const;

    int size() const;
    void stampaDizionario() const;

private:

    int searchBucket(const K&) const;

    List_pointer<mypair<K,E>>* table;
    hash_<K> hashm;		            // maps type K to nonnegative integer
    int dsize;		                // number of pairs in dictionary
    int divisor;		            // hash function divisor
};

template <class K, class E>
Hash_trabocco<K,E>::Hash_trabocco(){
    divisor = MAX;
    creaDizionario();
    }

template <class K, class E>
Hash_trabocco<K,E>::Hash_trabocco(int dimensione){
    divisor = dimensione;
    creaDizionario();
    }

template <class K, class E>
Hash_trabocco<K,E>::~Hash_trabocco(){
    for (int i = 0; i < divisor; i++)
        table[i].clear();
    delete[] table;
    }

template <class K, class E>
void Hash_trabocco<K,E>::creaDizionario(){
    dsize = 0;
    table = new List_pointer<mypair<K,E>> [divisor];
    for (int i = 0; i < divisor; i++ )
        table[i].create();
}

template <class K, class E>
bool Hash_trabocco<K,E>::dizionarioVuoto() const{
    return (dsize == 0);
}

template <class K, class E>
int Hash_trabocco<K,E>::searchBucket(const K& the_key) const{
    int i;
    i = (int) hashm(the_key) % divisor;
    return i;   // the home bucket
}

template <class K, class E>
int Hash_trabocco<K,E>::size() const{
    return dsize;
}

template <class K, class E>
bool Hash_trabocco<K,E>::appartiene(K& the_key) const{
    mypair<K,E> pair_in_list(the_key);
    typename List_pointer<mypair<K,E>>::position p;
    int i = searchBucket(the_key);   // the home bucket

    p = table[i].linear_ord_search(pair_in_list);
    if (p != NULL)
        return true;
    return false;
}


template <class K, class E>
void Hash_trabocco<K,E>::inserisci(mypair<K,E> the_pair){

    int b = searchBucket(the_pair.first);
    auto p = table[b].linear_ord_search(the_pair);
    if (p != NULL)
        table[b].write(the_pair,p);
    else{
        table[b].insert_ordered(the_pair);
        dsize++;
    }
}

template <class K, class E>
E Hash_trabocco<K,E>::recupera(K& the_key) const{
    mypair<K,E> pair_in_list(the_key);
    typename List_pointer<mypair<K,E>>::position p;
    int i = searchBucket(the_key);   // the home bucket
    p = table[i].linear_ord_search(pair_in_list);
    E out;
    if (p != NULL){
        mypair<K,E> pair_;
        pair_ = table[i].read(p);
        out = pair_.second;
        return out;
    }
    if(typeid(out) != typeid(string))
        return NULL;
    else
        return "";
}

template <class K, class E>
void Hash_trabocco<K,E>::cancella(K& the_key){
    mypair<K,E> pair_in_list(the_key);
    //auto p;
    bool found = false;
    int i = searchBucket(the_key);   // the home bucket
    auto p = table[i].linear_ord_search(pair_in_list);
    if (p != NULL){
        table[i].erase(p);
        dsize--;
        }
}

template< class K, class E >
void Hash_trabocco<K,E>::stampaDizionario() const{
    for (int i = 0; i < divisor; i++){
        if (!table[i].empty()){
            typename List_pointer<mypair<K,E>>::position p;
            p = table[i].begin();
            cout << "Position " << i << " = [";
            while(!table[i].end(p)){
                cout << (table[i].read(p)).second <<", ";
                p = table[i].next(p);
                }
            cout << "]" << endl;
            }
        }
        cout << "DICT SIZE: " << dsize << "  HASH TABLE SIZE: " << divisor << endl << endl;
}

#endif // HASH_TRABOCCO_H_INCLUDED
