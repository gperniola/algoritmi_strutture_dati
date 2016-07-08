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
    virtual bool alberoBinVuoto() = 0;
    virtual nodo binRadice() = 0;
    virtual nodo binPadre(nodo) = 0;
    virtual nodo binFiglioSin(nodo) = 0;
    virtual nodo binFiglioDes(nodo) = 0;
    virtual bool sinVuoto(nodo) = 0;
    virtual bool desVuoto(nodo) = 0;

    virtual void scriviNodo(tipoElem, nodo) = 0;
    virtual tipoElem leggiNodo(nodo) = 0;

    virtual void costrBinAlbero(AlberoBin<T,N>, AlberoBin<T,N>) = 0
    virtual void cancsottoAlbero(nodo) = 0;

    virtual void insBinRadice(nodo) = 0;
    virtual void insFiglioSin(nodo) = 0;
    virtual void insFiglioDes(nodo) = 0;

    // funzioni di servizio da implementare qui
    //virtual void preVisita(nodo);
    //virtual void inVisita(nodo);
    //virtual void postVisita(nodo);

    virtual void print() const;

private:
    virtual void printSubTree(const Nodo) const;

};




template <class T, class N>
void Bin_tree<T,N>::print() const{
	if (!empty())
		printSubTree(root());
	else
		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}

template <class T, class N>
void Bin_tree<T,N>::printSubTree(const Nodo n) const{
	std::cout << "[" << read(n) << ", ";
	if (!sx_empty(n))
		printSubTree(sx(n));
	else std::cout << "NIL";
	std::cout << ", ";
	if (!dx_empty(n))
		printSubTree(dx(n));
	else std::cout << "NIL";
	std::cout << " ]";
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Bin_tree<T, N>& t) {
    t.print();
    return out;
}






































#endif
