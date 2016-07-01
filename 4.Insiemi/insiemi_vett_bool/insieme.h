#ifndef INSIEME_H_
#define INSIEME_H_

#include <iostream>

template <class T>
class Insieme{

public:
	typedef T tipoelem;
    typedef Insieme<T> insieme;

	virtual void creaInsieme() = 0;
	virtual bool insiemeVuoto() = 0;
	virtual bool appartiene(tipoelem) const = 0;
	virtual void inserisci(tipoelem) = 0;
	virtual void cancella(tipoelem) = 0;
	virtual void unione(insieme &, insieme &) = 0;
	virtual void intersezione(insieme &, insieme &) = 0;
	virtual void differenza(insieme &, insieme &) = 0;

};
#endif /* INSIEME_H_ */
