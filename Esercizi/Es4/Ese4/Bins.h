#include "coda_punt.h"

template <class T>
using coda = Coda_punt<T>;

class Bins {
public:
    // inserisce l'intero k nella corrispondente coda
    void insert(int k);
    // effettua un fuoriCoda dalla coda c
    void Delete(int c);
    // restituisce la media dei valori attualmente memorizzati nella coda c
    double mean(int c);
    // restituisce il numero di elementi inseriti nella coda c
    int freq(int c);

    void print();
private:
    coda<int> bin[3];
};

void Bins::insert(int k){
    if(k >= 1 && k <= 9){
        if(k <= 3) bin[0].inCoda(k);
        else if(k <= 6) bin[1].inCoda(k);
            else bin[2].inCoda(k);
    }
    else cout << "errore di inserimento dati "<<endl;
}

void Bins::Delete(int c){
    if(c >= 0 && c <= 2) bin[c].fuoriCoda();
    else cout << "inserire un numero di coda da 0 a 2"<<endl;
}

double Bins::mean(int c){
    if(c >= 0 && c <= 2){
        coda<int> temp;
        int sum = 0; int n = 0;
        while(!bin[c].codaVuota()){
            sum = sum + bin[c].leggiCoda();
            temp.inCoda(bin[c].leggiCoda());
            bin[c].fuoriCoda();
            n++;
        }
        while(!temp.codaVuota()){
            bin[c].inCoda(temp.leggiCoda());
            temp.fuoriCoda();
        }
        return (double)sum / n;
    }
    else{
        cout << "inserire un numero di coda da 0 a 2"<<endl;
        return 0;
    }
}

int Bins::freq(int c){
    if(c >= 0 && c <= 2){
        coda<int> temp;
        int n = 0;
        while(!bin[c].codaVuota()){
            temp.inCoda(bin[c].leggiCoda());
            bin[c].fuoriCoda();
            n++;
        }
        while(!temp.codaVuota()){
            bin[c].inCoda(temp.leggiCoda());
            temp.fuoriCoda();
        }
        return n;
    }
    else{
        cout << "inserire un numero di coda da 0 a 2"<<endl;
        return 0;
    }
}

void Bins::print(){
    bin[0].stampaCoda();
    bin[1].stampaCoda();
    bin[2].stampaCoda();
}
