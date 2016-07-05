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
    //friend ostream& operator << <T,P>(ostream&, const Linear_list<T,P>&);
    virtual int size() const;  // returns the size of the list
    virtual void push_front(const value_type &); // insert a new element at the beginning
    virtual void push_back(const value_type &); // insert a new element at the end
    virtual void pop_front(); // removes the first element
    virtual void pop_back(); // removes the last element
    virtual void clear(); // erases all the elements

    virtual void invert();
    virtual bool is_palindrome();
    virtual void insert_ordered(const value_type &);
    virtual position linear_ord_search (const value_type &);
    virtual void merge_ord(const Linear_list &, const Linear_list &); //merges the two lists inside the obj list
    static void merge_ord_2(Linear_list &, const Linear_list &); //static, merges the second list in the first one
    //TODO bool is_present( value_type) //returns if an element is present in the list.
    //MORE TO DO
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
bool Linear_list<T,P>::is_palindrome(){
        //int length = size();
        bool exit = false;
        Linear_list<T,P>::position p1,p2;
        Linear_list<T,P>::value_type temp;
        p1 = begin();
        p2 = begin();
        while(!end(next(p2)))
            p2 = next(p2);

        while ((p1 != p2) && (next(p1) != p2) && (exit == false)){
            if (read(p1) == read(p2)){
                p1 = next(p1);
                p2 = previous(p2);
            }
            else
                exit = true;

        }
        return !exit;
}

template <class T, class P>
void Linear_list<T,P>::insert_ordered(const value_type &val){
    Linear_list<T,P>::position pos = begin();
    bool inserted = false;

    while(!end(pos) && inserted == false){
        if (val > read(pos)){
            //cout << val << " major " << read(pos) <<", skipping" << endl;
            pos = next(pos);
            }
        else{
            //cout << val << " mineq " << read(pos) <<", inserting" << endl;
            insert(val, pos);
            inserted = true;
        }

    }
    if (end(pos) && inserted == false)
        insert(val,pos);
}

template <class T, class P>
typename Linear_list<T,P>::position Linear_list<T,P>::linear_ord_search (const value_type &val){
    Linear_list<T,P>::position pos = begin();
    bool found = false;
    bool not_here = false;

    while(!end(pos) && found == false && not_here == false){
        //cout << "reading " << read(pos);
        if (val == read(pos)){
            //cout << " ...found!" << endl;
            found = true;
        }
        else if (val < read(pos)){
            //cout <<  val << " is minor than " << read(pos) <<", stopping." << endl;
            not_here = true;
            }
            else
                pos = next(pos);
    }

    if (found == false || not_here == true)
        return NULL;
    else if (found == true)
        return pos;

}

template <class T, class P>
void Linear_list<T,P>::merge_ord(const Linear_list &l1, const Linear_list &l2){
    this->clear();
    Linear_list<T,P>::position  p0 = this->begin(),
                                p1 = l1.begin(),
                                p2 = l2.begin();

    while(!l1.end(p1) && !l2.end(p2)){
        p0 = this->next(p0);
        if (l1.read(p1) <= l2.read(p2)){
            this->insert(l1.read(p1), p0);
            p1 = l1.next(p1);
        }
        else{
            this->insert(l2.read(p2), p0);
            p2 = l2.next(p2);
        }
    }
    if (!l1.end(p1)){
        while(!l1.end(p1)){
            p0 = this->next(p0);
            this->insert(l1.read(p1), p0);
            p1 = l1.next(p1);
        }
    }
    else{
        while(!l2.end(p2)){
            p0 = this->next(p0);
            this->insert(l2.read(p2), p0);
            p2 = l2.next(p2);
        }
    }
}

template <class T, class P>
void Linear_list<T,P>::merge_ord_2(Linear_list &l1, const Linear_list &l2){
    Linear_list<T,P>::position  p1 = l1.begin(),
                                p2 = l2.begin();

    while(!l2.end(p2)){
        if (l1.read(p1) <= l2.read(p2)){
            p1 = l1.next(p1);
        }
        else{
            l1.insert(l2.read(p2), p1);
            p2 = l2.next(p2);
        }
    }
}






#endif // LINEARLIST_H_INCLUDED
