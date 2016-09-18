#ifndef LIST_POINTER_H_INCLUDED
#define LIST_POINTER_H_INCLUDED

#include "linear_list.h"
#include "cell.h"

template <class T>
class List_pointer : public Linear_list<T, Cell<T>*>{

public:
    typedef typename Linear_list<T, Cell<T>*>::value_type value_type;
    typedef typename Linear_list<T, Cell<T>*>::position position;

    /*****constructors*****/
    List_pointer();

    /*****copy constructor*****/
    List_pointer(const List_pointer<T> &);

    /*****destructor*****/
    ~List_pointer();

    /*****operators*****/
    void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position &);
	void erase(position);

    /*****operators overload*****/
    List_pointer<T>& operator = (const List_pointer<T> &);
    bool operator == (const List_pointer<T> &) const;

private:
    position list;
} ;

template <class T>
List_pointer<T>::List_pointer(){
    this->create();
    }

template <class T>
List_pointer<T>::List_pointer(const List_pointer<T> &l){
    this->create();

    List_pointer<T>::position p1, p2;
	p1=l.begin();
	p2=this->begin();
	 while(!l.end(p1)){
		this->insert(l.read(p1), p2);
		p1=l.next(p1);
		p2=this->next(p2);
	}
    }

template <class T>
List_pointer<T>::~List_pointer(){
    List_pointer<T>::position p;
    while(!this->empty())
        erase(p = begin());
    delete list;
    }

template <class T>
void List_pointer<T>::create(){
    value_type val;
    list = new Cell<T>();
    list->set_element(val);
    list->set_prev(list);
    list->set_next(list);
    }

template <class T>
bool List_pointer<T>::empty() const{
    if((list->get_next() == list) && (list->get_prev() == list))
        return 1;
    else
        return 0;
    }

template <class T>
typename List_pointer<T>::value_type List_pointer<T>::read(position p) const{
    return p->get_element();
}

template <class T>
void List_pointer<T>::write(const value_type &value, position p){
    p->set_element(value);
    }

template <class T>
typename List_pointer<T>::position List_pointer<T>::begin() const{
    return list->get_next();
    }

template <class T>
bool List_pointer<T>::end(position p) const{
    return (p == list);
    }

template <class T>
typename List_pointer<T>::position List_pointer<T>::next(position p) const{
    return p->get_next();
    }

template <class T>
typename List_pointer<T>::position List_pointer<T>::previous(position p) const{
    return p->get_prev();
    }

template <class T>
void List_pointer<T>::insert(const value_type &value, position &p){
    //create a new cell with value and pointers to p and p-1
    List_pointer<T>::position new_pos = new Cell<T>();
    new_pos->set_element(value);
    new_pos->set_prev(p->get_prev());
    new_pos->set_next(p);

    //get p-1 and set his next to new_pos
    (p->get_prev())->set_next(new_pos);

    //get p and set his prev to new_pos
    p->set_prev(new_pos);

    //set p to point to the new cell
    p = new_pos;
    }

template <class T>
void List_pointer<T>::erase(position p){
    (p->get_next())->set_prev(p->get_prev());
    (p->get_prev())->set_next(p->get_next());
    delete p;
}

template <class T>
List_pointer<T>& List_pointer<T>::operator = (const List_pointer<T> &l){
    List_pointer<T>::position p1, p2;
	p1=l.begin();
	p2=this->begin();
	 while(!l.end(p1)){
		this->insert(l.read(p1), p2);
		p1=l.next(p1);
		p2=this->next(p2);
	}
	return *this;
}

template <class T>
bool List_pointer<T>::operator == (const List_pointer<T> &l) const{
    List_pointer<T>::position p1, p2;
    p1 = l.begin();
    p2 = this->begin();
    while(!this->end(p2)){
        if((this->read(p2) != (l.read(p1))))
            return false;
        p1 = l.next(p1);
        p2 = this->next(p2);
    }
    if (!l.end(p1))
        return false;
    return true;
    }

#endif // LIST_POINTER_H_INCLUDED
