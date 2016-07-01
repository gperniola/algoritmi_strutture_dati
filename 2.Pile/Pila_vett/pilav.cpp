#include <iostream>
#include "pilav.h"

using namespace std;

Pila::Pila()
{
  creaPila();
}

Pila::~Pila()
{}


void Pila::creaPila()
{
  for (int i=0;i<MAXLUNGH;i++)
    {
      elementi[i].setElemento(0);
    }
  testa=0;
}

bool Pila::pilaVuota() const
  {
    return testa==0;
  }

tipoelem Pila::leggiPila() const
{
  return (elementi[testa-1].getElemento());
}

void Pila::fuoriPila()
{
  if (!pilaVuota())
    {
      testa-=1;
    }
  else
    {
      cout<<"nessun elemento nella pila"<<endl;
    }
}

void Pila::inPila(tipoelem el)
{
  if (testa==MAXLUNGH)
    {
      cout<<"raggiunta capacità massima della pila"<<endl;
    }
  else
    {
      elementi[testa].setElemento(el);
      testa++;
    }
}

void stampaPila(Pila & L)
{
  int i;
  for (i = 0; i< L.testa; i++)
    cout << L.elementi[i] << " ";
}
