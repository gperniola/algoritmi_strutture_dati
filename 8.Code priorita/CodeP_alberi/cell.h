#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

template <class T>
class Cell{

public:
    typedef T value_type;

    /*****constructors*****/
    Cell();
    //Cell(const value_type &);
    //Cell(value_type &, Cell<T>* p, Cell<T>* n);

    /*****destructor*****/
    ~Cell();

    /*****getters*****/
    value_type get_element() const;
    Cell<T>* get_figlioSin() const;
    Cell<T>* get_figlioDes() const;
    Cell<T>* get_padre() const;
    int get_livello() const;

    /*****setters*****/
    void set_element(value_type);
    void set_figlioSin(Cell<T>*);
    void set_figlioDes(Cell<T>*);
    void set_padre(Cell<T>*);
    void set_livello(int);

    /*****operators overload*****/
    Cell<T>& operator = (const Cell<T> &);

private:
    int livello;
    value_type element;
    Cell<T>* figlioSin;
    Cell<T>* figlioDes;
    Cell<T>* padre;
};

/***********implementation*************/

template <class T>
Cell<T>::Cell(){
    this->figlioSin = nullptr;
    this->figlioDes = nullptr;
    this->padre = nullptr;
    }

/*template <class T>
Cell<T>::Cell(const value_type &value){
    this->element = value;
    Cell();
    }*/

/*template <class T>
Cell<T>::Cell(value_type &value, Cell<T>* p, Cell<T>* n){
    this->element = value;
    this->next = n;
    this->previous = p;
    }*/

template <class T>
Cell<T>::~Cell(){
    //this->figlioSin = nullptr;
    //this->figlioDes = nullptr;
    //this->padre = nullptr;
}

template <class T>
typename Cell<T>::value_type Cell<T>::get_element() const{
    return this->element;
    }

template <class T>
Cell<T>* Cell<T>::get_figlioSin() const{
    return this->figlioSin;
    }

template <class T>
Cell<T>* Cell<T>::get_figlioDes() const{
    return this->figlioDes;
    }

template <class T>
Cell<T>* Cell<T>::get_padre() const{
    return this->padre;
    }


template <class T>
int Cell<T>::get_livello() const{
    return this->livello;
    }

template <class T>
void Cell<T>::set_element(value_type value){
    this->element = value;
}

template <class T>
void Cell<T>::set_figlioSin(Cell<T>* p){
    this->figlioSin = p;
}

template <class T>
void Cell<T>::set_figlioDes(Cell<T>* p){
    this->figlioDes = p;
}

template <class T>
void Cell<T>::set_padre(Cell<T>* p){
    this->padre = p;
}

template <class T>
void Cell<T>::set_livello(int liv){
    this->livello = liv;
}

/*****operators*****/

template <class T>
Cell<T>& Cell<T>::operator = (const Cell<T> &c){
    this->element = c.get_element();
    this->figlioSin = c.get_figlioSin();
    this->figlioDes = c.get_figlioDes();
    this->padre = c.get_padre();
}

#endif // CELL_H_INCLUDED
