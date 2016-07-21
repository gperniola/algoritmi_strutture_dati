#include <iostream>

#include "alberoNPunt.h"

using namespace std;

int main()
{
    AlberoNPunt<int> A, B, C, D;
    AlberoNPunt<int>::nodo n = new Cell<int>();
    n->set_element(2);
    A.print();
    A.insRadice();
    A.print();
    A.scriviNodo(1,A.getRadice());
    A.print();
    B.insRadice(n);
    B.print();
    A.insPrimoSottoalbero(A.getRadice(),B);
    A.print();
    n = new Cell<int>();
    n->set_element(3);
    C.insRadice(n);
    A.insSottoalbero(B.getRadice(),C);
    A.print();
    D.insRadice();
    D.scriviNodo(4,D.getRadice());
    B.insPrimoSottoalbero(B.getRadice(),D);
    A.print();

    cout << A.leggiNodo(A.padre(D.getRadice())) << " è padre di " << A.leggiNodo(D.getRadice()) << endl;
    cout << A.leggiNodo(A.padre(B.getRadice())) << " è padre di " << A.leggiNodo(B.getRadice()) << endl;
    cout << A.leggiNodo(A.padre(C.getRadice())) << " è padre di " << A.leggiNodo(C.getRadice()) << endl;
    return 0;
}
