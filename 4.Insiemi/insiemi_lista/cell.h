#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

template <class T>
class Cell{

public:
    typedef T value_type;

    /*****constructors*****/
    Cell();

    /*****destructor*****/
    ~Cell();

    /*****getters*****/
    value_type get_element() const;
    Cell<T>* get_next() const;
    Cell<T>* get_prev() const;

    /*****setters*****/
    void set_element(value_type);
    void set_next(Cell<T>*);
    void set_prev(Cell<T>*);

    /*****operators overload*****/
    Cell<T>& operator = (const Cell<T> &);

private:
    value_type element;
    Cell<T>* next;
    Cell<T>* previous;
};

/***********implementation*************/

template <class T>
Cell<T>::Cell(){
    this->next = nullptr;
    this->previous = nullptr;
    }

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
Cell<T>* Cell<T>::get_prev() const{
    return previous;
    }

template <class T>
void Cell<T>::set_element(value_type value){
    this->element = value;
}

template <class T>
void Cell<T>::set_prev(Cell<T>* p){
    this->previous = p;
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
