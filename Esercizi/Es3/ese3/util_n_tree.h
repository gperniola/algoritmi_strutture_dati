#include "alberoNPunt.h"

template <class T>
using Tree = AlberoNPunt<T>;

int max_level(Tree<int> &T);
int sum_level(Tree<int> &T, int k);
int sum_etichette(Tree<int> &T);
int inVisita_even(Tree<int> &T, int i);

int sum_level_nodo(Tree<int> &T, Tree<int>::nodo &n, int k);
int sum_etichette_nodo(Tree<int> &T, Tree<int>::nodo &n);
int inVisita_even_nodo(Tree<int> &T, Tree<int>::nodo &n, int i);

int sum_level_nodo(Tree<int> &T, Tree<int>::nodo &n, int k){
    int s = 0;
    if(T.getLivello(n) == k){
        s = s + T.leggiNodo(n);
        auto fr = n;
        while(!T.ultimoFratello(fr)){
            fr = T.succFratello(fr);
            s = s + T.leggiNodo(fr);
        }
    }
    else{
        if(!T.foglia(n)){
            auto figlio = T.primoFiglio(n);
            return sum_level_nodo(T, figlio, k);
        }
    }
    return s;
}

int sum_etichette_nodo(Tree<int> &T, Tree<int>::nodo &n){
    int s = 0;
    int self = T.leggiNodo(n);
    if(T.foglia(n)){
        T.scriviNodo(0,n);
    }
    else{
        auto son = T.primoFiglio(n);
        s = s + sum_etichette_nodo(T, son);
        while(!T.ultimoFratello(son)){
            son = T.succFratello(son);
            s = s + sum_etichette_nodo(T, son);
        }
        T.scriviNodo(s,n);
    }
    return s + self;
}

int inVisita_even_nodo(Tree<int> &T, Tree<int>::nodo &n, int i){
    int sum = 0;
    if (!T.alberoVuoto()){
        if(!T.foglia(n)){
            if( i < 1) i = 1;
            auto m = T.primoFiglio(n);
            sum = sum + inVisita_even_nodo(T, m, i);

            int k = 2;
            while (k <= i && !T.ultimoFratello(m)){
                m = T.succFratello(m);
                sum = sum + inVisita_even_nodo(T, m, i);
                k++;
            }
            if(T.padre(n) != NULL){
                if(T.leggiNodo(T.padre(n)) % 2 == 0)
                    sum++;
            }
            while(!T.ultimoFratello(m)){
                m = T.succFratello(m);
                sum = sum + inVisita_even_nodo(T, m, i);
            }
        }
        else{
            if(T.leggiNodo(T.padre(n)) % 2 == 0)
                sum++;
        }
    }
    return sum;
}





int sum_level(Tree<int> &T, int k){
    if(!T.alberoVuoto()){
        auto root = T.getRadice();
        return sum_level_nodo(T, root, k);
    }
    else return 0;
}

int max_level(Tree<int> &T){
    if(!T.alberoVuoto()){
        int max_depth = T.maxLivello();
        int livelli[max_depth + 1];
        for(int i = 0; i < max_depth + 1; i++)
            livelli[i] = sum_level(T,i);
        int max_sum = livelli[0];
        int max_i = 0;
        for(int i = 1; i < max_depth + 1; i++)
            if(max_sum < livelli[i]){
                max_sum = livelli[i];
                max_i = i;
            }
        return max_i;
    }
    return 0;
}

int sum_etichette(Tree<int> &T){
    if(!T.alberoVuoto()){
        auto root = T.getRadice();
        return sum_etichette_nodo(T, root);
    }
    else return 0;
}

int inVisita_even(Tree<int> &T, int i){
    if(!T.alberoVuoto()){
        auto root = T.getRadice();
        return inVisita_even_nodo(T, root, i);
    }
    else return 0;
}

