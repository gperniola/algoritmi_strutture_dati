#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

using namespace std;

template <class T> class NodoGrafo{
public:
    typedef T tipoElem;
    typedef int peso;
    typedef struct Arco{
        peso p;
        NodoGrafo<T>* nodoPunt;
        Arco* arcoSucc;
    } arco;

    NodoGrafo();
    NodoGrafo(tipoElem);
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);
    NodoGrafo* getSucc();
    void setSucc(NodoGrafo*);
    void addArco(arco*);
    arco* getPrimoArco();
    bool cercaArco(NodoGrafo*);

    void print();
    bool getVisitato();
    void setVisitato(bool);
    bool operator == (const NodoGrafo<T>&) const;

private:
    tipoElem etichetta;
    NodoGrafo* nodoSucc;
    arco* listaArchi;
    bool visitato;
};


template <class T>
NodoGrafo<T>::NodoGrafo(){nodoSucc = NULL; listaArchi = NULL; visitato = false;}
template <class T>
NodoGrafo<T>::NodoGrafo(tipoElem e){nodoSucc = NULL; listaArchi = NULL; visitato = false; setEtichetta(e);}
template <class T> NodoGrafo<T>::~NodoGrafo(){}

template <class T>
void NodoGrafo<T>::setEtichetta(tipoElem e){this->etichetta = e;}
template <class T>
typename NodoGrafo<T>::tipoElem NodoGrafo<T>::getEtichetta() const{return etichetta;}

template <class T>
NodoGrafo<T>* NodoGrafo<T>::getSucc(){return nodoSucc;}
template <class T>
void NodoGrafo<T>::setSucc(NodoGrafo* n){nodoSucc = n;}

template <class T>
void NodoGrafo<T>::addArco(arco* a){listaArchi = a;}
template <class T>
typename NodoGrafo<T>::arco* NodoGrafo<T>::getPrimoArco(){return listaArchi;}

template <class T>
bool NodoGrafo<T>::cercaArco(NodoGrafo* m){
    arco* temp = listaArchi;
    while(temp != NULL){
        if (m->getEtichetta() == (temp->nodoPunt)->getEtichetta())
            return true;
        else temp = temp->arcoSucc;
    }
    return false;
}

template <class T> bool NodoGrafo<T>::getVisitato(){return visitato;}
template <class T> void NodoGrafo<T>::setVisitato(bool b){visitato = b;}

template <class T>
bool NodoGrafo<T>::operator == (const NodoGrafo<T> &n) const{
    return (this->getEtichetta() == n.getEtichetta());
}



template <class T>
void NodoGrafo<T>::print(){
    cout << "etichetta: " << etichetta << endl;
    if (listaArchi != NULL){
        arco* temp = listaArchi;
        cout << "--" << temp->p << "--> " << temp->nodoPunt->getEtichetta() << endl;
        while(temp->arcoSucc != NULL){
            temp = temp->arcoSucc;
            cout << "--" << temp->p << "--> " << temp->nodoPunt->getEtichetta() << endl;
        }
    }
    else cout << "--x no archi for " << etichetta << endl;
}


#endif
