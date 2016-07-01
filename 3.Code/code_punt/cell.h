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
    Cell<T>* get_next() const;

    /*****setters*****/
    void set_element(value_type);
    void set_next(Cell<T>*);

    /*****operators overload*****/
    Cell<T>& operator = (const Cell<T> &);

private:
    value_type element;
    Cell<T>* next;
};

/***********implementation*************/

template <class T>
Cell<T>::Cell(){
    this->next = nullptr;
    this ->element = NULL;
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
Cell<T>::~Cell(){}

template <class T>
typename Cell<T>::value_type Cell<T>::get_element() const{
    return this->element;
    }

template <class T>
Cell<T>* Cell<T>::get_next() const{
    return this->next;
    }


template <class T>
void Cell<T>::set_element(value_type value){
    this->element = value;
}


template <class T>
void Cell<T>::set_next(Cell<T>* n){
    this->next = n;
}

/*****operators*****/

template <class T>
Cell<T>& Cell<T>::operator = (const Cell<T> &c){
    this->element = c.get_element();
    this->previous = c.get_prev();
    this->next = c.get_next();
}

#endif // CELL_H_INCLUDED
