#ifndef INSIEME_VETT_BOOL_H_
#define INSIEME_VETT_BOOL_H_

#include "insieme.h"

#include <iostream>
using namespace std;

static const int DIM_MAX = 1000; //DIM_MAX del vettore booleano

class Insieme_vett_bool : public Insieme<int>  {

public:
	typedef Insieme<int>::tipoelem tipoelem;
	typedef Insieme<int>::insieme insieme;

	Insieme_vett_bool();
	~Insieme_vett_bool();
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
    Insieme_vett_bool& operator = (const Insieme_vett_bool &);

private:
	bool * vettore_bool;

};

Insieme_vett_bool::Insieme_vett_bool(){
	creaInsieme();
}

Insieme_vett_bool::~Insieme_vett_bool(){}

void Insieme_vett_bool::creaInsieme(){
	vettore_bool = new bool [DIM_MAX];

	for(int i=0; i<DIM_MAX; i++)
		vettore_bool[i] = false;
}


bool Insieme_vett_bool::insiemeVuoto(){
	bool valore_verit = true;
	int i = 0;
	while (i < DIM_MAX && valore_verit == true){
		valore_verit = !vettore_bool[i];
		i++;
	}
	return valore_verit;
}


bool Insieme_vett_bool::appartiene(tipoelem x) const{
	if(x >= 0 && x < DIM_MAX)
		return vettore_bool[x];
	else
		return false;
}

void Insieme_vett_bool::inserisci(tipoelem x){
	if(x >= 0 && x < DIM_MAX)
        vettore_bool[x]=true;
}

void Insieme_vett_bool::cancella(tipoelem x){
	if(x >= 0 && x < DIM_MAX)
        vettore_bool[x]=false;
}

void Insieme_vett_bool::unione(insieme &A, insieme &B){
   for (int i = 0; i < DIM_MAX; i++){
        if ((A.appartiene(i) || B.appartiene(i)))
            this->inserisci(i);
        else
            this->cancella(i);
   }
}

void Insieme_vett_bool::intersezione(insieme &A, insieme &B){
   for (int i = 0; i < DIM_MAX; i++){
      if ((A.appartiene(i) && B.appartiene(i)))
         this->inserisci(i);
        else
            this->cancella(i);
   }
}

void Insieme_vett_bool::differenza(insieme &A, insieme &B){
   for (int i = 0; i < DIM_MAX; i++){
      if ((A.appartiene(i) && !B.appartiene(i)))
         this->inserisci(i);
        else
            this->cancella(i);
   }
}

Insieme_vett_bool& Insieme_vett_bool::operator = (const Insieme_vett_bool &A){
    for (int i = 0; i < DIM_MAX; i++){
    cout << i;
        if (A.appartiene(i))
            this->inserisci(i);
        else
            this->cancella(i);
    }
	return *this;
}



#endif /* INSIEME_VETT_BOOL_H_ */
