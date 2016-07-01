#include "nodopv.h"

using namespace std;

Nodo::Nodo()
{}

Nodo::~Nodo()
{}

Nodo::Nodo(tipoelem label)
{
  elemento=label;
}

void Nodo::setElemento(tipoelem label)
{
  elemento=label;
}

tipoelem Nodo::getElemento() const
{
    return elemento;
}

bool Nodo::operator==(Nodo & n)
{
  return (getElemento() == n.getElemento());
}

std::ostream & operator<<(std::ostream & out, const Nodo & nodo)
{
  return out << nodo.getElemento();
}
