#ifndef CODA_H_INCLUDED
#define CODA_H_INCLUDED

#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

/*****************************
CLASSE ASTRATTA CODA
*****************************/

template <class T>
class Coda{

public:
typedef T value_type;

    //*****operators*****
    virtual void creaCoda() = 0;
    virtual bool codaVuota() const = 0;
    virtual value_type leggiCoda() const = 0;
    virtual void fuoriCoda() = 0;
    virtual void inCoda(value_type) = 0;

    //*****service functions******
    virtual void stampaCoda() = 0;

};
    //*****implementations******
    template< class T>
    ostream& operator<<(ostream& os, const Coda<T> &c){
	os << "coda: ";
	os << c.leggiCoda();
	return os;
}


#endif // CODA_H_INCLUDED
