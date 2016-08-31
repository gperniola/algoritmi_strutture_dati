#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_




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
    ~NodoGrafo();

    tipoElem getEtichetta() const;
    void setEtichetta(tipoElem);

    NodoGrafo* getSucc();
    void setSucc(NodoGrafo*);

    void addArco(arco*);
    arco* getPrimoArco();

    bool cercaArco(NodoGrafo*);

    private:
    tipoElem etichetta;
    NodoGrafo* nodoSucc;
    arco* listaArchi;
};


template <class T>
NodoGrafo<T>::NodoGrafo(){ nodoSucc = NULL; listaArchi = NULL;}

template <class T>
NodoGrafo<T>::~NodoGrafo(){}

template <class T>
void NodoGrafo<T>::setEtichetta(tipoElem e){this->etichetta = e;}

template <class T>
typename NodoGrafo<T>::tipoElem NodoGrafo<T>::getEtichetta() const{return etichetta;}

template <class T>
void NodoGrafo<T>::addArco(arco* a){listaArchi = a;}

template <class T>
typename NodoGrafo<T>::arco* NodoGrafo<T>::getPrimoArco(){return listaArchi;}

template <class T>
bool NodoGrafo<T>::cercaArco(NodoGrafo* m){
    arco* temp = listaArchi;
    while(temp != NULL){
        if (etichetta == (temp->nodoPunt)->getEtichetta())
            return true;
        else temp = temp->arcoSucc;
    }
    return false;
}

#endif
