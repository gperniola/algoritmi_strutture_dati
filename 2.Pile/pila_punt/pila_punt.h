#ifndef PILA_PUNT_H_INCLUDED
#define PILA_PUNT_H_INCLUDED

#include "pila.h"
#include "cell.h"

template <class T>
class Pila_punt : public Pila<T>{

public:

    //constructor
    Pila_punt();

    //copy constructor
    Pila_punt(const Pila_punt &p);

    //destructor
    ~Pila_punt();

    //*****operators*****
    void creaPila();
    bool pilaVuota() const;
    T leggiPila() const;
    void fuoriPila();
    void inPila(T);

    void stampaPila();

private:
    Cell<T>* top;
};

template <class T>
Pila_punt<T>::Pila_punt(){
    creaPila();
}

template <class T>
Pila_punt<T>::Pila_punt( const Pila_punt &p){
    //this.creaPila();
}

template <class T>
Pila_punt<T>::~Pila_punt(){
}

template <class T>
void Pila_punt<T>::creaPila(){
    top = new Cell<T>();
    top->set_next(nullptr);
    top->set_element(NULL);
}

template <class T>
bool Pila_punt<T>::pilaVuota() const{
    return (top->get_element() == NULL);
}

template <class T>
T Pila_punt<T>::leggiPila() const{
    return top->get_element();
}

template <class T>
void Pila_punt<T>::fuoriPila(){
    if (!pilaVuota()){
        Cell<T>* temp = top;
        top = top->get_next();
        delete temp;
    }
}

template <class T>
void Pila_punt<T>::inPila(T v){
        Cell<T>* new_top = new Cell<T>();
        new_top->set_element(v);
        new_top->set_next(top);
        top = new_top;
    //}
}

template <class T>
void Pila_punt<T>::stampaPila(){
    Pila_punt<T> p_supp;
    cout << "[";
    while(!this->pilaVuota()){
        cout << this->leggiPila() << ",";
        p_supp.inPila(this->leggiPila());
        this->fuoriPila();
    }
    cout << "]" << endl;

    while(!p_supp.pilaVuota()){
        this->inPila(p_supp.leggiPila());
        p_supp.fuoriPila();
    }
}

#endif // PILA_PUNT_H_INCLUDED
