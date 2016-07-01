#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

/*****************************
CLASSE ASTRATTA PILA
*****************************/

template <class T>
class Pila{

public:
typedef T value_type;

    //*****operators*****
    virtual void creaPila() = 0;
    virtual bool pilaVuota() const = 0;
    virtual value_type leggiPila() const = 0;
    virtual void fuoriPila() = 0;
    virtual void inPila(value_type) = 0;

    //*****service functions******
    virtual void stampaPila() = 0;
};

//*****implementations******
template< class T>
ostream& operator<<(ostream& os, const Pila<T> &p){
	os << "top: ";
	os << p.leggiPila();
	return os;
}



#endif // PILA_H_INCLUDED
