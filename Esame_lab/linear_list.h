#ifndef LINEARLIST_H_INCLUDED
#define LINEARLIST_H_INCLUDED

#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

/*****************************
CLASSE ASTRATTA LISTA LINEARE
*****************************/

template <class T, class P>
class Linear_list{

public:
    typedef T value_type;   //The type of obj stored in the list
    typedef P position;

    //*****operators*****
    virtual void create() = 0;
    virtual bool empty() const = 0;
    virtual value_type read(position) const = 0;
    virtual void write(const value_type &, position) = 0;
    virtual position begin() const = 0;
    virtual bool end(position) const = 0;
    virtual position next(position) const = 0;
    virtual position previous(position) const = 0;
    virtual void insert(const value_type &, position &) = 0;
    virtual void erase(position) = 0;

    //*****service functions******
    virtual int size() const;  // returns the size of the list
    virtual void push_front(const value_type &); // insert a new element at the beginning
    virtual void push_back(const value_type &); // insert a new element at the end
    virtual void pop_front(); // removes the first element
    virtual void pop_back(); // removes the last element
    virtual void clear(); // erases all the elements

    virtual void invert();

    virtual position linear_search(const value_type &) const;

};

//*****Implementations*****
/* sovraccarica <<. Se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	typename Linear_list<T,P>::position p;
	p = l.begin();
	os << "[";
	while (!l.end(p)){
		if (p != l.begin()){
			os << ", ";
			os << l.read(p);
		}
		else
			os << l.read(p);
		p = l.next(p);
	}
	os << "]" << endl;
	return os;
}

template <class T, class P>
int Linear_list<T,P>::size() const{
    int length = 0;
    if (!empty()){      //if list not empty then scan the list and calculate length.
        Linear_list<T,P>::position p = begin();
        while(!end(p)){
                length++;
                p = next(p);
        }
    }
    return length;
}

template <class T, class P>
void Linear_list<T,P>::push_front(const value_type &value){
    Linear_list<T,P>::position p = begin();
    insert(value, p);
}

template <class T, class P>
void Linear_list<T,P>::push_back(const value_type &value){
    Linear_list<T,P>::position p = begin();
    while(!end(p))
        p = next(p);
    insert(value, p);
}

template <class T, class P>
void Linear_list<T,P>::pop_front(){
    erase(begin());
}

template <class T, class P>
void Linear_list<T,P>::pop_back(){
    Linear_list<T,P>::position p = begin();
    while(!end(next(p)))
        p = next(p);
    erase(p);
}

template <class T, class P>
void Linear_list<T,P>::clear(){
    Linear_list<T,P>::position p;
    while (!empty())
        erase(p = begin());
}

template <class T, class P>
void Linear_list<T,P>::invert(){
    int length = size();
    if(length > 1){
        Linear_list<T,P>::position p1,p2;
        Linear_list<T,P>::value_type temp;
        p1 = begin();
        p2 = begin();
        while(!end(next(p2)))
            p2 = next(p2);

        for (int k = 1; k <= length / 2; ++k){
            temp = read(p1);
            write(read(p2), p1);
            write(temp, p2);
            p1 = next(p1);
            p2 = previous(p2);
        }
    }
}


template <class T, class P>
typename Linear_list<T,P>::position Linear_list<T,P>::linear_search(const value_type &x) const{
    Linear_list<T,P>::position p = this->begin();
    bool trovato = false;
    while (!this->end(p) && trovato == false){
        if (x == this->read(p))
            trovato = true;
        else
            p = this->next(p);
    }
    if (trovato == false)
        p = NULL;
    return p;
}


#endif // LINEARLIST_H_INCLUDED
