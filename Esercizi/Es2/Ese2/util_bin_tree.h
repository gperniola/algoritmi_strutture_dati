#include "alberoBinPunt.h"

template <class T>
using bintree = AlberoBinPunt<T>;

//typedef typename bintree<T>::nodo nodo;

int odd(bintree<int> &T, int k);
int even_nodes(bintree<int> &T);
int even_leafs(bintree<int> &T);
int leafs_with_even_parent(bintree<int> &T);
int multipli(bintree<int> &T);

int odd_nodo(bintree<int> &T, bintree<int>::nodo &n, int k);
int even_nodo(bintree<int> &T, bintree<int>::nodo &n);
int even_leaf(bintree<int> &T, bintree<int>::nodo &n);
int multipli_nodo(bintree<int> &T, bintree<int>::nodo &n);



int odd_nodo(bintree<int> &T, bintree<int>::nodo &n, int k){
    if(T.getLivello(n) == k)
        return T.leggiNodo(n) % 2;
    else{
        if(!T.sinVuoto(n) && !T.desVuoto(n)){
            auto n1 = T.binFiglioSin(n); auto n2 = T.binFiglioDes(n);
            return (odd_nodo(T, n1,k) + odd_nodo(T,n2,k));
            }else if (!T.sinVuoto(n)){
                auto n1 = T.binFiglioSin(n);
                return (odd_nodo(T,n1,k));
                }else if (!T.desVuoto(n)){
                    auto n2 = T.binFiglioDes(n);
                    return (odd_nodo(T,n2,k));
                    }else return 0;
    }
}

int even_nodo(bintree<int> &T, bintree<int>::nodo &n){
    int even_nodes = 0;
    if(T.leggiNodo(n) % 2 == 0)
        even_nodes = 1;

    if(!T.sinVuoto(n) && !T.desVuoto(n)){
        auto n1 = T.binFiglioSin(n); auto n2 = T.binFiglioDes(n);
        even_nodes = even_nodes + even_nodo(T, n1) + even_nodo(T,n2);
        }else if (!T.sinVuoto(n)){
            auto n1 = T.binFiglioSin(n);
            even_nodes = even_nodes + even_nodo(T, n1);
            }else if (!T.desVuoto(n)){
                auto n2 = T.binFiglioDes(n);
                even_nodes = even_nodes + even_nodo(T, n2);
                }
    return even_nodes;
}

int even_leaf(bintree<int> &T, bintree<int>::nodo &n){

    if(T.sinVuoto(n) && T.desVuoto(n)){
        if(T.leggiNodo(n) % 2 == 0)
            return 1;
        else return 0;
    }
    else{
    if(!T.sinVuoto(n) && !T.desVuoto(n)){
        auto n1 = T.binFiglioSin(n); auto n2 = T.binFiglioDes(n);
        return even_leaf(T, n1) + even_leaf(T,n2);
        }else if (!T.sinVuoto(n)){
            auto n1 = T.binFiglioSin(n);
            return even_leaf(T, n1);
            }else if (!T.desVuoto(n)){
                auto n2 = T.binFiglioDes(n);
                return even_leaf(T, n2);
                }
    }
}

int leaf_with_even_parent(bintree<int> &T, bintree<int>::nodo &n){

    if(T.sinVuoto(n) && T.desVuoto(n)){
        if(T.leggiNodo(T.binPadre(n)) % 2 == 0)
            return 1;
        else return 0;
    }
    else{
        int s = 0;
        if (!T.sinVuoto(n)){
            auto n1 = T.binFiglioSin(n);
            s = s + leaf_with_even_parent(T, n1);
        }
        if (!T.desVuoto(n)){
            auto n2 = T.binFiglioDes(n);
            s = s + leaf_with_even_parent(T, n2);
        }
        return s;
    }
}

int multipli_nodo(bintree<int> &T, bintree<int>::nodo &n){
    int s = 0;
    if (!T.sinVuoto(n)){
        auto n1 = T.binFiglioSin(n);
        s = s + multipli_nodo(T, n1);
    }
    if (!T.desVuoto(n)){
        auto n2 = T.binFiglioDes(n);
        s = s + multipli_nodo(T, n2);
    }
    int r = 0;
    if(T.leggiNodo(n) % 2 == 0)
        r = 1;
    T.scriviNodo(s, n);
    return s+r;
}



int odd(bintree<int> &T, int k){
    if(!T.alberoBinVuoto()){
        bintree<int>::nodo root = T.binRadice();
        return odd_nodo(T,root, k);
    }
    else return 0;
}

int even_nodes(bintree<int> &T){
    if(!T.alberoBinVuoto()){
        bintree<int>::nodo root = T.binRadice();
        return even_nodo(T,root);
    }
    else return 0;
}

int even_leafs(bintree<int> &T){
    if(!T.alberoBinVuoto()){
        bintree<int>::nodo root = T.binRadice();
        return even_leaf(T,root);
    }
    else return 0;
}

int leafs_with_even_parent(bintree<int> &T){
    int n = 0;
    if(!T.alberoBinVuoto()){
        auto root = T.binRadice();
        if (!T.sinVuoto(root)){
            auto n1 = T.binFiglioSin(root);
            n = n + leaf_with_even_parent(T, n1);
        }
        if (!T.desVuoto(root)){
            auto n2 = T.binFiglioDes(root);
            n = n + leaf_with_even_parent(T, n2);
        }
    }
    return n;
}

int multipli(bintree<int> &T){
    if(!T.alberoBinVuoto()){
        bintree<int>::nodo root = T.binRadice();
        return multipli_nodo(T,root);
    }
    else return 0;
}
