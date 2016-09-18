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
    typedef typename Grafo<T, NodoGrafo<T>, int>::List List;

	/*** constructors ***/
    GrafoPunt();

    /*****copy constructor*****/
    //GrafoPunt(const GrafoPunt<T,P> &);

    /*****destructor*****/
    ~GrafoPunt();

    /*****operators*****/
    void crea();
    bool vuoto();
    void insNodo(nodo&);
    void insArco(nodo&, nodo&, peso);
    void cancNodo(nodo&);
    void cancArco(nodo&, nodo&);
    bool esisteNodo(nodo&);
    bool esisteArco(nodo&, nodo&);

    tipoElem leggiNodo(nodo&);
    void scriviNodo(nodo&, tipoElem);
    peso leggiPeso(nodo&, nodo&);
    void scriviPeso(nodo&, nodo&, peso);

    List* adiacenti(nodo&);
    void print();

    bool getVisitato(nodo&);
    void setVisitato(nodo&, bool);
    void setAllVisitato(bool);

    //nodo* cercaNodo(nodo n);

private:
    int numNodi;
    nodo* primoNodo;
    nodo* ultimoNodo;



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
void GrafoPunt<T>::insNodo(nodo &n){
    if(!esisteNodo(n)){
        if(this->vuoto()){
            //primoNodo = new nodo(n.getEtichetta());
            //nodo* np = &n;
            primoNodo = &n;
            //primoNodo->color = n.color; // esercizio
            ultimoNodo = primoNodo;
        }
        else{
            ultimoNodo->setSucc(&n);
            ultimoNodo = ultimoNodo->getSucc();
            //ultimoNodo->color = n.color;
        }
        numNodi++;
    } else cout << "Errore: nodo gia presente nel grafo" << endl;
}

template <class T>
void GrafoPunt<T>::insArco(nodo &n, nodo &m, peso p){
        if(esisteNodo(n) && esisteNodo(m)){
        if(!esisteArco(n,m)){
            //nodo* np = cercaNodo(n);
            //nodo* mp = cercaNodo(m);
            typename NodoGrafo<T>::arco* newArco = new typename NodoGrafo<T>::arco;
            newArco->nodoPunt = &m;
            newArco->p = p;
            newArco->arcoSucc = NULL;
            if(n.getPrimoArco() == NULL){
                n.addArco(newArco);
            }else{
                typename NodoGrafo<T>::arco* temp = n.getPrimoArco();
                while(temp->arcoSucc != NULL)
                    temp = temp->arcoSucc;
                temp->arcoSucc = newArco;
            }
        }else cout << "Errore: arco già presente nel grafo" << endl;
       }else cout << "Errore: uno o entrambi i nodi non sono presenti nel grafo" << endl;
}




template <class T>
void GrafoPunt<T>::cancNodo(nodo &n){
    if(esisteNodo(n)){
        nodo* nodoTemp = primoNodo;
        while(nodoTemp != NULL){
            List* l = adiacenti(*nodoTemp);
            auto p = l->begin();
            while(!l->end(p)){
                if(n.getEtichetta() == l->read(p)->getEtichetta()){
                    cout << "Errore: Il nodo" << l->read(p)->getEtichetta() << "è collegato al nodo " << n.getEtichetta()
                        <<". Prima di eliminare il nodo è necessario eliminare l'arco che li collega." << endl;
                    delete(l);
                    return;
                }
                p = l->next(p);
            }
            delete(l);
            nodoTemp = nodoTemp->getSucc();
        }
        nodoTemp = primoNodo;
        if(n == *nodoTemp){
            primoNodo = primoNodo->getSucc();
            delete (nodoTemp);
        }else{
            while(n.getEtichetta() != nodoTemp->getSucc()->getEtichetta())
                nodoTemp = nodoTemp->getSucc();
            nodo* nodoCanc = nodoTemp->getSucc();
            nodoTemp->setSucc(nodoTemp->getSucc()->getSucc());
            delete(nodoCanc);
        }
        numNodi--;
    }else cout << "Errore: il nodo non è presente nel grafo." << endl;
}

template <class T>
void GrafoPunt<T>::cancArco(nodo &n, nodo &m){
    if(esisteArco(n,m)){
        //nodo* np = cercaNodo(n);
        typename NodoGrafo<T>::arco* temp = n.getPrimoArco();
        if (m == *temp->nodoPunt){
            n.addArco(temp->arcoSucc);
            delete (temp);
        }else{
            while(m.getEtichetta() != temp->arcoSucc->nodoPunt->getEtichetta())
                temp = temp->arcoSucc;
            typename NodoGrafo<T>::arco* canc = temp->arcoSucc;
            (temp->arcoSucc) = temp->arcoSucc->arcoSucc;
            delete(canc);
        }
    }else cout << "Errore: non esiste un arco tra i due nodi" << endl;
}



template <class T>
bool GrafoPunt<T>::esisteNodo(nodo &n){

    nodo* temp = primoNodo;
    while(temp != NULL){
        if(n.getEtichetta() == temp->getEtichetta())
            return true;
        temp = temp->getSucc();
    }
    return false;
}


template <class T>
bool GrafoPunt<T>::esisteArco(nodo &n, nodo &m){

    if(esisteNodo(n) && esisteNodo(m)){
        nodo* mp = &m;
        return (n.cercaArco(&m));
    }

    else return false;
}

template <class T>
typename GrafoPunt<T>::tipoElem GrafoPunt<T>::leggiNodo(nodo &n){
    if(esisteNodo(n))
        return n.getEtichetta();
}

template <class T>
void GrafoPunt<T>::scriviNodo(nodo &n, tipoElem e){
        nodo temp;
        temp.setEtichetta(e);
        if(!esisteNodo(temp) && esisteNodo(n)){
            n.setEtichetta(e);
        }
        else cout << "Errore: etichetta già presente in altro nodo oppure nodo non presente nel grafo" << endl;
}

template <class T>
void GrafoPunt<T>::print(){
    cout << "||| printing grafo |||" << endl << "numNodi: " << numNodi << endl;
    nodo* temp = primoNodo;
    while (temp != NULL){
        temp->print();
        temp = temp->getSucc();
    }
    cout << "||| end grafo |||" << endl;
}

/*template <class T>
typename GrafoPunt<T>::nodo* GrafoPunt<T>::cercaNodo(nodo n){

    nodo* temp = primoNodo;
    while(temp != NULL){
        if(n.getEtichetta() == temp->getEtichetta())
            return temp;
        temp = temp->getSucc();
    }
    return NULL;
}*/

template <class T>
typename GrafoPunt<T>::List* GrafoPunt<T>::adiacenti(nodo &n){
    List* listPunt = new List();
    if(esisteNodo(n)){
        //nodo* np = cercaNodo(n);
        typename NodoGrafo<T>::arco* temp = n.getPrimoArco();
        auto p = listPunt->begin();
        while(temp != NULL){
            listPunt->insert(temp->nodoPunt, p);
            temp = temp->arcoSucc;
        }
    }
    return listPunt;
}

template <class T>
typename GrafoPunt<T>::peso GrafoPunt<T>::leggiPeso(nodo &n, nodo &m){
    if(esisteArco(n,m)){
        //nodo* np = cercaNodo(n);
        typename NodoGrafo<T>::arco* temp = n.getPrimoArco();
        while(temp != NULL){
            if (m == *temp->nodoPunt)
                return temp->p;
            temp = temp->arcoSucc;
        }
    }else cout << "Errore: arco non presente" << endl;
}

template <class T>
void GrafoPunt<T>::scriviPeso(nodo &n, nodo &m, peso pe){
    if(esisteArco(n,m)){
        //nodo* np = cercaNodo(n);
        typename NodoGrafo<T>::arco* temp = n.getPrimoArco();
        while(temp != NULL){
            if (m == *temp->nodoPunt)
                temp->p = pe;
            temp = temp->arcoSucc;
        }
    }else cout << "Errore: arco non presente" << endl;
    return;
}


template <class T>
bool GrafoPunt<T>::getVisitato(nodo &n){
    if(esisteNodo(n)){
        //nodo* np = cercaNodo(n);
        return n.getVisitato();
    }else return false;
}

template <class T>
void GrafoPunt<T>::setVisitato(nodo &n, bool b){
    if(esisteNodo(n)){
        //nodo* np = cercaNodo(n);
        n.setVisitato(b);
    }
}

template <class T>
void GrafoPunt<T>::setAllVisitato(bool b){
    nodo* temp = primoNodo;
    while(temp != NULL){
        temp->setVisitato(b);
        temp = temp->getSucc();
    }
}



#endif
