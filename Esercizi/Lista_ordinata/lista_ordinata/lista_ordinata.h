#include "list_pointer.h"

template <class T>
using List = List_pointer<T>;

template <class T> void inserisci(List<T> &L, T elem);
template <class T> void rimuovi(List<T> &L, T elem);
template <class T> void differenza(List<T> &L1, List<T> &L2);
template <class T> bool sottolista(List<T> &L1, List<T> &L2);

template <class T> typename List<T>::position linear_ord_search(List<T> L1, T elem);

template <class T> void inserisci(List<T> &L, T elem){
    auto pos = L.begin();
    bool inserted = false;
    while(!L.end(pos) && inserted == false){
        if (elem > L.read(pos)){
            pos = L.next(pos);
            }
        else{
            L.insert(elem, pos);
            inserted = true;
        }

    }
    if (L.end(pos) && inserted == false)
        L.insert(elem,pos);
}

template <class T> typename List<T>::position linear_ord_search(List<T> &L, T elem){
    auto pos = L.begin();
    bool found = false;
    bool not_here = false;

    while(!L.end(pos) && found == false && not_here == false){
        if (elem == L.read(pos)){
            found = true;
        }
        else if (elem < L.read(pos)){
            not_here = true;
            }
            else
                pos = L.next(pos);
    }
    if (found == false || not_here == true)
        return NULL;
    else if (found == true)
        return pos;
}

template <class T> void rimuovi(List<T> &L, T elem){
    auto p = linear_ord_search(L,elem);
    if(p != NULL)
        L.erase(p);
}

template <class T> void differenza(List<T> &L1, List<T> &L2){
    auto p1 = L1.begin();
    auto p2 = L2.begin();

    while(!L2.end(p2) && !L1.end(p1)){
        if(L1.read(p1) == L2.read(p2)){
            auto p_temp = p1;
            p1 = L1.next(p1);
            L1.erase(p_temp);
        }else if(L1.read(p1) < L2.read(p2)){
            p1 = L1.next(p1);
        }else p2 = L2.next(p2);
    }
}

template <class T> bool sottolista(List<T> &L1, List<T> &L2){
    auto pos_stringa = L2.begin();
    auto pos_sottostringa = L1.begin();
    while(!L2.end(pos_stringa)){
       auto temp_stringa = pos_stringa;
       while(L2.read(temp_stringa) == L1.read(pos_sottostringa)){
            pos_sottostringa = L1.next(pos_sottostringa);
            if(L1.end(pos_sottostringa)) return true;
            temp_stringa = L2.next(temp_stringa);
       }
       pos_sottostringa = L1.begin();
       pos_stringa = L2.next(pos_stringa);
    }
    return false;
}
