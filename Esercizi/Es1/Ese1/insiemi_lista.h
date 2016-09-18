#ifndef INSIEMI_LISTA_H_
#define INSIEMI_LISTA_H_

#include "insieme.h"
#include "list_pointer.h"

template <class T>
class Insiemi_lista : public Insieme<T>  {

public:
	typedef typename Insieme<T>::tipoelem tipoelem;
	typedef typename Insieme<T>::insieme insieme;

	Insiemi_lista();
	~Insiemi_lista();
	//operatori
	void creaInsieme();
	bool insiemeVuoto();
	bool appartiene(tipoelem) const;
	void inserisci(tipoelem);
	void cancella(tipoelem);
	void unione(insieme &, insieme &);
	void intersezione(insieme &, insieme &);
	void differenza(insieme &, insieme &);

    /*****operators overload*****/
    Insiemi_lista<T>& operator = (const Insiemi_lista<T> &);

private:
	List_pointer<tipoelem> lista;

};

template <class T>
Insiemi_lista<T>::Insiemi_lista(){
	creaInsieme();
}

template <class T>
Insiemi_lista<T>::~Insiemi_lista(){
    lista.clear();
}

template <class T>
void Insiemi_lista<T>::creaInsieme(){
	lista.create();
}

template <class T>
bool Insiemi_lista<T>::insiemeVuoto(){
    return lista.empty();
}

template <class T>
bool Insiemi_lista<T>::appartiene(tipoelem x) const{
    if(lista.linear_search(x) == NULL)
        return false;
    else
        return true;
}

template <class T>
void Insiemi_lista<T>::inserisci(tipoelem x){
	if (!this->appartiene(x)){
        auto p = lista.begin();
        lista.insert(x, p);
    }
}

template <class T>
void Insiemi_lista<T>::cancella(tipoelem x){
	auto p = lista.linear_search(x);
	if (p != NULL)
        lista.erase(p);
}

template <class T>
void Insiemi_lista<T>::unione(insieme &A, insieme &B){
    auto lista_A =  dynamic_cast< Insiemi_lista<T>* >(&A)->lista;
    auto pA = lista_A.begin();
    auto lista_B =  dynamic_cast< Insiemi_lista<T>* >(&B)->lista;
    auto pB = lista_B.begin();
    lista.clear();

    while(!lista_A.end(pA)){
        this->inserisci(lista_A.read(pA));
        pA = lista_A.next(pA);
        }

    while(!lista_B.end(pB)){
        if (!this->appartiene(lista_B.read(pB)))
            this->inserisci(lista_B.read(pB));
        pB = lista_B.next(pB);
    }
}

template <class T>
void Insiemi_lista<T>::intersezione(insieme &A, insieme &B){
    auto lista_A =  dynamic_cast< Insiemi_lista<T>* >(&A)->lista;
    auto pA = lista_A.begin();
    lista.clear();

    while(!lista_A.end(pA)){
        if (B.appartiene(lista_A.read(pA)))
            this->inserisci(lista_A.read(pA));
        pA = lista_A.next(pA);
    }
}

template <class T>
void Insiemi_lista<T>::differenza(insieme &A, insieme &B){
    auto lista_A =  dynamic_cast< Insiemi_lista<T>* >(&A)->lista;
    auto pA = lista_A.begin();
    lista.clear();

     while(!lista_A.end(pA)){
        if (!B.appartiene(lista_A.read(pA)))
            this->inserisci(lista_A.read(pA));
        pA = lista_A.next(pA);
    }

}

template <class T>
Insiemi_lista<T>& Insiemi_lista<T>::operator = (const Insiemi_lista<T> &A){
    this->lista.clear();
    this-> lista = A.lista;

}









#endif /* INSIEMI_LISTA_H_ */
