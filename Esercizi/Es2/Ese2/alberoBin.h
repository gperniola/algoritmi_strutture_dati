#ifndef ALBEROBIN_H
#define ALBEROBIN_H

#include <iostream>
using namespace std;


template <class T, class N>
class AlberoBin {
public:

    // tipi
    typedef T tipoElem;
    typedef N nodo;

    virtual void creaAlberoBin() = 0;
    virtual bool alberoBinVuoto() const = 0;
    virtual nodo binRadice() const = 0;
    virtual nodo binPadre(nodo) const = 0;
    virtual nodo binFiglioSin(nodo) const = 0;
    virtual nodo binFiglioDes(nodo) const = 0;
    virtual bool sinVuoto(nodo) const = 0;
    virtual bool desVuoto(nodo) const = 0;

    virtual void scriviNodo(tipoElem, nodo) = 0;
    virtual tipoElem leggiNodo(nodo) const = 0;

    virtual void costrBinAlbero(AlberoBin<T,N>&, AlberoBin<T,N>&) = 0;
    virtual void cancsottoAlbero(nodo) = 0;

    virtual void insBinRadice() = 0;
    virtual void insFiglioSin(nodo, AlberoBin<T,N>&) = 0;
    virtual void insFiglioDes(nodo, AlberoBin<T,N>&) = 0;

    virtual int getLivello(nodo) const = 0;    //todo

    // funzioni di servizio da implementare qui
    virtual void preVisita(nodo);
    virtual void inVisita(nodo);
    virtual void postVisita(nodo);

    virtual void print() const;

    virtual int maxLivello() const;
    virtual int dimAlbero(nodo) const;

private:
    virtual void printSubTree(const nodo) const;
    virtual int calcolaMaxLivello(nodo) const;



};


template <class T, class N>
int AlberoBin<T,N>::dimAlbero(nodo n) const{
    int dim = 0;
    if(!alberoBinVuoto()){
        dim++;
        if (!sinVuoto(n))
            dim = dim + dimAlbero(binFiglioSin(n));
        if (!desVuoto(n))
            dim = dim + dimAlbero(binFiglioDes(n));
    }
    return dim;

}


template <class T, class N>
int AlberoBin<T,N>::maxLivello() const{
    int maxLvl = 0;
    if(!alberoBinVuoto()){
        if (!sinVuoto(binRadice()))
            maxLvl = calcolaMaxLivello(binFiglioSin(binRadice()));

        if (!desVuoto(binRadice())){
            int calc = calcolaMaxLivello(binFiglioDes(binRadice()));
            if( calc > maxLvl)
                maxLvl = calc;
        }

    }
    return maxLvl;

}

template <class T, class N>
int AlberoBin<T,N>::calcolaMaxLivello(nodo n) const{
    int maxLvl = 0;

    if (!sinVuoto(n))
            maxLvl = calcolaMaxLivello(binFiglioSin(n));

        if (!desVuoto(n)){
            int calc = calcolaMaxLivello(binFiglioDes(n));
            if( calc > maxLvl)
                maxLvl = calc;
        }
        return maxLvl + 1;



}




template <class T, class N>
void AlberoBin<T,N>::preVisita(nodo n){
    if(!alberoBinVuoto()){
        cout << leggiNodo(n) << ", ";
        if (!sinVuoto(n))
            preVisita(binFiglioSin(n));
        if (!desVuoto(n))
            preVisita(binFiglioDes(n));
    }
}

template <class T, class N>
void AlberoBin<T,N>::inVisita(nodo n){
    if(!alberoBinVuoto()){
        if (!sinVuoto(n))
            inVisita(binFiglioSin(n));
        cout << leggiNodo(n) << ", ";
        if (!desVuoto(n))
            inVisita(binFiglioDes(n));
    }
}

template <class T, class N>
void AlberoBin<T,N>::postVisita(nodo n){
    if(!alberoBinVuoto()){
        if (!sinVuoto(n))
            postVisita(binFiglioSin(n));
        if (!desVuoto(n))
            postVisita(binFiglioDes(n));
        cout << leggiNodo(n) << ", ";
    }
}

template <class T, class N>
void AlberoBin<T,N>::print() const{
	if (!this->alberoBinVuoto())
		printSubTree(binRadice());
	else
		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}

template <class T, class N>
void AlberoBin<T,N>::printSubTree(const nodo n) const{
	std::cout << "[" << leggiNodo(n) << ", ";
	if (!sinVuoto(n))
		printSubTree(binFiglioSin(n));
	else std::cout << "N";
	std::cout << ", ";
	if (!desVuoto(n))
		printSubTree(binFiglioDes(n));
	else std::cout << "N";
	std::cout << " ]";
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const AlberoBin<T, N>& t) {
    t.print();
    return out;
}






































#endif
