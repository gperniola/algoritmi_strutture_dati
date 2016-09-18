#include "list_pointer.h"

class tripla{
public:
    int riga;
    int colonna;
    double valore;

    bool operator == (const tripla &t) const;
};
/****   operatore di uguaglianza tra elementi di tipo tripla, necessario per
        la funzione linear_search per la ricerca di un elemento in una lista ****/
bool tripla::operator == (const tripla &t) const{
    return (riga == t.riga && colonna == t.colonna);
}

/****   operatore per la stampa di ogni singolo elemento tripla
        nel formato <r,c,v>                                     ****/
ostream& operator<<(ostream& os, const tripla &t){
    os << "<" << t.riga <<","<<t.colonna<<","<<t.valore<<">";
    return os;
}


class sparsa {
public:
// aggiunge un valore non nullo alla matrice
    void inserisci(int riga, int colonna, double valore);
// rimuove un valore non nullo dalla matrice
    void rimuovi(int riga, int colonna);
// restituisce un valore dalla matrice
    double leggi(int riga, int colonna);
// stampa la lista contenente la matrice
    void print();
private:
    List_pointer<tripla> matrice;
};

void sparsa::inserisci(int riga, int colonna, double valore){
    tripla new_tripla;
    new_tripla.riga = riga;
    new_tripla.colonna = colonna;
    new_tripla.valore = valore;

    if(matrice.linear_search(new_tripla) == NULL){
        auto p = matrice.begin();
        matrice.insert(new_tripla, p);
    }else cout << "ATTENZIONE: elemento <" << riga <<","<<colonna
    <<"> occupato, cancellarlo prima di ritentare l'inserimento."<< endl;
}
void sparsa::rimuovi(int riga, int colonna){
    tripla temp_tripla;
    temp_tripla.riga = riga;
    temp_tripla.colonna = colonna;
    temp_tripla.valore = 0;
    auto p = matrice.linear_search(temp_tripla);
    if (p != NULL){
        matrice.erase(p);
        cout << "elemento <" << riga <<","<<colonna<<"> cancellato."<<endl;
    }else cout << "ATTENZIONE: elemento <" << riga <<","<<colonna<<"> non presente."<<endl;
}

double sparsa::leggi(int riga, int colonna){
    tripla temp_tripla;
    temp_tripla.riga = riga;
    temp_tripla.colonna = colonna;
    temp_tripla.valore = 0;
    auto p = matrice.linear_search(temp_tripla);
    if (p != NULL){
        return matrice.read(p).valore;
    }else cout << "ATTENZIONE: elemento <" << riga <<","<<colonna<<"> non presente."<<endl;
}

void sparsa::print(){
    cout << matrice;
}


