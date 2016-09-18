#ifndef CODA_PUNT_H_INCLUDED
#define CODA_PUNT_H_INCLUDED

#include "coda.h"
#include "cell.h"

template <class T>
class Coda_punt : public Coda<T>{

public:

    //constructor
    Coda_punt();

    //copy constructor
    Coda_punt(const Coda_punt &p);

    //destructor
    ~Coda_punt();

    //*****operators*****
    void creaCoda();
    bool codaVuota() const;
    T leggiCoda() const;
    void fuoriCoda();
    void inCoda(T);

    void stampaCoda();

private:
    Cell<T>* testa;
    Cell<T>* coda;
};

template <class T>
Coda_punt<T>::Coda_punt(){
    creaCoda();
}

template <class T>
Coda_punt<T>::Coda_punt( const Coda_punt &p){
    //this.creaCoda();
}

template <class T>
Coda_punt<T>::~Coda_punt(){
    while (!codaVuota())
        fuoriCoda();
}

template <class T>
void Coda_punt<T>::creaCoda(){
    testa = new Cell<T>();
    coda = new Cell<T>();
    testa->set_next(nullptr);
    testa->set_element(NULL);
    coda = testa;
}

template <class T>
bool Coda_punt<T>::codaVuota() const{
    return (testa->get_element() == NULL);
}

template <class T>
T Coda_punt<T>::leggiCoda() const{
    return testa->get_element();
}

template <class T>
void Coda_punt<T>::fuoriCoda(){
    if (!codaVuota()){
        Cell<T>* temp = testa;
        if (testa == coda)
            coda = testa->get_next();
        testa = testa->get_next();
        delete temp;
    }
}

template <class T>
void Coda_punt<T>::inCoda(T v){
        Cell<T>* new_coda = new Cell<T>();
        new_coda->set_element(v);
        if (codaVuota()){
            new_coda->set_next(coda);
            coda = new_coda;
            testa = new_coda;
        }else{
            new_coda->set_next(coda->get_next());
            coda->set_next(new_coda);
            coda= new_coda;
        }
}

template <class T>
void Coda_punt<T>::stampaCoda(){
    Coda_punt<T> p_supp;
    cout << "[";
    while(!this->codaVuota()){
        cout << this->leggiCoda() << ",";
        p_supp.inCoda(this->leggiCoda());
        this->fuoriCoda();
    }
    cout << "]" << endl;

    while(!p_supp.codaVuota()){
        this->inCoda(p_supp.leggiCoda());
        p_supp.fuoriCoda();
    }
}


#endif // CODA_PUNT_H_INCLUDED
