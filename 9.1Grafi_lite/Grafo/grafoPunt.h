#ifndef GRAFOPUNT_H_
#define GRAFOPUNT_H_


#include "grafo.h"
#include "nodoGrafo.h"
using namespace std;

template < class T >
class GrafoPunt: public Grafo<T, NodoGrafo<T>, int>{

public:
	typedef typename Grafo<T, NodoGrafo<T>, int>::nodo nodo;
	typedef typename Grafo<T, NodoGrafo<T>, int>::tipoElem tipoElem;
	typedef typename Grafo<T, NodoGrafo<T>, int>::peso peso;

	/*** constructors ***/
    GrafoPunt();

    /*****copy constructor*****/
    //GrafoPunt(const GrafoPunt<T,P> &);

    /*****destructor*****/
    ~GrafoPunt();

    /*****operators*****/
    void crea();
    bool vuoto();
    void insNodo(nodo);
    void insArco(nodo, nodo, peso);
    void cancNodo(nodo);
    bool esisteNodo(nodo);
    bool esisteArco(nodo, nodo);

    tipoElem leggiNodo(nodo);
    void scriviNodo(nodo, tipoElem);

    void print();

private:
    int numNodi;
    nodo* primoNodo;
    nodo* ultimoNodo;

    nodo* cercaNodo(nodo n);

};

template <class T>
GrafoPunt<T>::GrafoPunt(){this->crea();}

template <class T>
GrafoPunt<T>::~GrafoPunt(){}

template <class T>
void GrafoPunt<T>::crea(){
    primoNodo = NULL;
    ultimoNodo = NULL;
    numNodi = 0;
}

template <class T>
bool GrafoPunt<T>::vuoto(){return (primoNodo == NULL);}

template <class T>
void GrafoPunt<T>::insNodo(nodo n){
    if(!esisteNodo(n)){
        if(this->vuoto()){
            primoNodo = new nodo();
            ultimoNodo = primoNodo;
        }
        else{
            ultimoNodo->setSucc(new nodo());
            ultimoNodo = ultimoNodo->getSucc();
        }
        numNodi++;
    } else cout << "Errore: nodo già presente nel grafo" << endl;
}

template <class T>
void GrafoPunt<T>::insArco(nodo n, nodo m, peso p){
        if(!esisteArco(n,m)){
            nodo* np = cercaNodo(n);
            nodo* mp = cercaNodo(m);
            typename NodoGrafo<T>::arco* newArco = new typename NodoGrafo<T>::arco();
            newArco->nodoPunt = mp;
            newArco->p = p;
            newArco->arcoSucc = NULL;
            if(np->getPrimoArco() == NULL)
                np->addArco(newArco);
            else{
                typename NodoGrafo<T>::arco* temp = np->getPrimoArco();
                while(temp->arcoSucc != NULL)
                    temp = temp->arcoSucc;
                temp->arcoSucc = newArco;

            }
            delete(newArco);
        }
       else cout << "Errore: arco già presente oppure nodi non presenti nel grafo" << endl;
}




/*template <class T>
void GrafoPunt<T,P>::cancNodo(nodo &n){
    if(esisteNodo(n))
        nodi->erase(nodi->linear_ord_search(n));
}*/

template <class T>
bool GrafoPunt<T>::esisteNodo(nodo n){

    nodo* temp = primoNodo;
    while(temp != NULL){
        if(n.getEtichetta() == temp->getEtichetta())
            return true;
        temp = temp->getSucc();
    }
    return false;
}


template <class T>
bool GrafoPunt<T>::esisteArco(nodo n, nodo m){

    if(esisteNodo(n) && esisteNodo(m)){
        return n.cercaArco(cercaNodo(m));
    }
    else return false;
}

template <class T>
typename GrafoPunt<T>::tipoElem GrafoPunt<T>::leggiNodo(nodo n){
    if(esisteNodo(n))
        return n.getEtichetta();
}

template <class T>
void GrafoPunt<T>::scriviNodo(nodo n, tipoElem e){
        nodo temp;
        temp.setEtichetta(e);
        if(!esisteNodo(temp) && esisteNodo(n)){
            cercaNodo(n)->setEtichetta(e);
        }
        else cout << "Errore: etichetta già presente in altro nodo oppure nodo non presente nel grafo" << endl;
}

/*template <class T>
void GrafoPunt<T>::print(){
}*/

#endif
