#ifndef GRAFO_H_
#define GRAFO_H_

#include "list_pointer.h"
#include "coda_punt.h"
#include "patch.h"

using namespace std;

template < class T, class N, class P > class Grafo {
public:

	/*** Tipi ***/
	typedef T tipoElem;
	typedef N nodo;
    typedef P peso;
    typedef List_pointer<nodo*> List;
    typedef Coda_punt<nodo*> Coda;

    /*** Operatori ***/
    virtual void crea() = 0;
    virtual bool vuoto() = 0;
    virtual void insNodo(nodo&) = 0;
    virtual void insArco(nodo&, nodo&, peso) = 0;
    virtual void cancNodo(nodo&) = 0;
    virtual void cancArco(nodo&, nodo&) = 0;

    virtual bool esisteNodo(nodo&) = 0;
    virtual bool esisteArco(nodo&, nodo&) = 0;

    virtual tipoElem leggiNodo(nodo&) = 0;
    virtual void scriviNodo(nodo&,tipoElem) = 0;

    virtual List* adiacenti(nodo&) = 0;
    virtual peso leggiPeso(nodo&, nodo&) = 0;
    virtual void scriviPeso(nodo&, nodo&, peso) = 0;

    /*** Visite ***/
    virtual void DFS(nodo&);
    virtual void BFS(nodo&);

    /*** Funzioni di servizio ***/
    static void printAdiacenti(List*);
    virtual bool getVisitato(nodo&) = 0;
    virtual void setVisitato(nodo&, bool) = 0;
    virtual void setAllVisitato(bool) = 0;

    virtual void trovaCammino(nodo, nodo, string);
    virtual bool uniformColorPath(nodo&, nodo&, string);
};

/*template <class T, class N,class P>
void Grafo<T,N,P>::DFS2(nodo &n){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p))
                cout <<"("<<leggiNodo(n)<<")" << endl;
            else{
                while(!ad->end(p)){
                    cout <<"("<<leggiNodo(n)<<")--"<< leggiPeso(n,*ad->read(p)) <<"-->";
                    DFS(*ad->read(p));
                    p = ad->next(p);
                }
            }
            delete(ad);
        }else cout <<"("<<leggiNodo(n)<<")"<<" [already visited]" << endl;
    }
}*/

template <class T, class N,class P>
void Grafo<T,N,P>::DFS(nodo &n){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            cout <<"("<<leggiNodo(n)<<")";
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            while(!ad->end(p)){
                DFS(*ad->read(p));
                p = ad->next(p);
            }
            delete(ad);
        }
    }
}

template <class T, class N,class P>
void Grafo<T,N,P>::BFS(nodo &n){
    if(esisteNodo(n)){
        Coda codaNodi;
        codaNodi.inCoda(&n);
        setVisitato(n,true);
        while(!codaNodi.codaVuota()){
            nodo *m = codaNodi.leggiCoda();
            /****THIS IS BAD: non tiene conto degli elementi in coda in attesa, quindi "già visitati",
            quindi alcuni nodi raggiungibili da piu' archi possono essere inseriti in coda più volte,
            fino a quando non vengono tirati fuori dalla coda la prima volta.
            setVisitato(*codaNodi.leggiCoda(),true);
            *****/
            cout <<"("<<leggiNodo(*m)<<")";
            codaNodi.fuoriCoda();
            List* ad = adiacenti(*m);
            auto p = ad->begin();
            while(!ad->end(p)){
               if(!getVisitato(*ad->read(p))){
                    setVisitato(*ad->read(p),true);
                    codaNodi.inCoda(ad->read(p));;
                }
                p = ad->next(p);
            }
            delete(ad);
        }
    }
}

/*template <class T, class N,class P>
void Grafo<T,N,P>::BFS(nodo n){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p))
                cout <<"("<<leggiNodo(n)<<")" << endl;
            else{
                while(!ad->end(p)){
                    cout <<"("<<leggiNodo(n)<<")--"<< leggiPeso(n,*ad->read(p)) <<"-->("<< leggiNodo(*ad->read(p)) << "), ";
                    if(!getVisitato(*ad->read(p))){
                        codaNodi->inCoda(ad->read(p));
                    }
                    p = ad->next(p);
                }
                cout << endl;
                while(!codaNodi->codaVuota()){
                    nodo* np = codaNodi->leggiCoda();
                    codaNodi->fuoriCoda();
                    BFS(*np);
                }
            }
            delete(ad);
        }//else cout <<"("<<leggiNodo(n)<<")"<<" [already visited]" << endl;
    }
}*/


template <class T, class N,class P>
void Grafo<T,N,P>::printAdiacenti(List* l){
    auto p = l->begin();
    while(!l->end(p)){
        cout << l->read(p)->getEtichetta() << ", ";
        p = l->next(p);
    }
}

template <class T, class N,class P>
void Grafo<T,N,P>::trovaCammino(nodo n, nodo m, string path){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p)){
                path = path + "(" + patch::to_string(leggiNodo(n)) + ")[BACKTRACK - LEAF]";
                cout << path << endl;
                return;
            }
            else{
                while(!ad->end(p)){
                    if(ad->read(p)->getEtichetta() == m.getEtichetta()){
                        path = path + "(" + patch::to_string(leggiNodo(n)) + ")--" + patch::to_string(leggiPeso(n,*ad->read(p))) +
                                    "-->(" + patch::to_string(ad->read(p)->getEtichetta()) + ")[FOUND]";
                        cout << path << endl;
                        return;
                    }
                    p = ad->next(p);
                }
                p = ad->begin();
                while(!ad->end(p)){
                    string new_path = path + "(" + patch::to_string(leggiNodo(n)) + ")--" + patch::to_string(leggiPeso(n,*ad->read(p))) + "-->";
                    trovaCammino(*ad->read(p), m, new_path);
                    p = ad->next(p);
                }
            }
            delete(ad);
        }else{
         path = path + "(" + patch::to_string(leggiNodo(n)) + ")" + " [BACKTRACK - VISITED]";
         cout << path << endl;
         return;
        }
    }
}





/*template <class T, class N,class P>
bool Grafo<T,N,P>::uniformColorPath(nodo n, nodo m, string path){
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            if(ad->end(p)){
                path = path + "(" + patch::to_string(leggiNodo(n)) + ")[BACKTRACK - LEAF]";
                 cout << path << endl;
                return false;
            }
            else{
                while(!ad->end(p)){
                    if(ad->read(p)->getEtichetta() == m.getEtichetta()){
                        if(ad->read(p)->color != n.color){
                            path = path + "(" + n.color + patch::to_string(leggiNodo(n)) + ")-->(" + ad->read(p)->color + patch::to_string(ad->read(p)->getEtichetta()) + ")[FOUND]";
                            cout << path << endl;
                            return true;
                        }
                    }
                    p = ad->next(p);
                }
                p = ad->begin();
                bool found = false;
                while(!ad->end(p) && !found){
                    if(ad->read(p)->getEtichetta() != m.getEtichetta() && ad->read(p)->color != n.color ){
                        string new_path = path + "(" + n.color + patch::to_string(leggiNodo(n)) + ")-->";
                        found = uniformColorPath(*ad->read(p), m, new_path);
                    }
                    p = ad->next(p);
                }
            }
            delete(ad);
        }else{
         path = path + "(" + n.color + patch::to_string(leggiNodo(n)) + ")" + " [BACKTRACK - VISITED]";
         cout << path << endl;
         return false;
        }
    }*/

template <class T, class N,class P>
bool Grafo<T,N,P>::uniformColorPath(nodo& n, nodo& m, string path){
    bool found = false;
    if(esisteNodo(n)){
        if(!getVisitato(n)){
            path = path + "(" + n.color + ":" + patch::to_string(leggiNodo(n)) + ")";
            setVisitato(n,true);
            List* ad = adiacenti(n);
            auto p = ad->begin();
            while(!ad->end(p)){
                if(*ad->read(p) == m && n.color != ad->read(p)->color){
                    cout << path <<"("<< m.color << ":" << m.getEtichetta() << ")"<<endl;
                    found =  true;
                }
                p = ad->next(p);
            }
            p = ad->begin();
            /*** ATTENZIONE: L'algoritmo termina di controllare i nodi adiacenti non appena viene
             trovato un path che soddisfa le condizioni, per trovare tutti i path che soddisfano
             la condizione è necessario eliminare il (!found) ***/
            while(!ad->end(p) && !found){
                if (n.color != ad->read(p)->color && ad->read(p)->getEtichetta() != m.getEtichetta() ){
                    found = uniformColorPath(*ad->read(p), m, path);
                }
                p = ad->next(p);
            }
            delete(ad);
        }
        return found;
    }
}

#endif
