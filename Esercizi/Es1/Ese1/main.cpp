#include <iostream>
#include "list_pointer.h"
#include "insiemi_lista.h"
#include "recommender.h"


using namespace std;
template<class T>
using List = List_pointer<T>;

int freq(List<int> &L, int k){
    List_pointer<int>::position p = L.begin();
    int mFound = 0;
    while(!L.end(p)){
        if(L.read(p) % k == 0)
            mFound++;
        p = L.next(p);
    }
    return mFound;
}

void hist(List_pointer<int> &L){
    List_pointer<int>::position p = L.begin();
    Insiemi_lista<int> ins;

    while(!L.end(p)){
        int k = L.read(p);
        if( !ins.appartiene(k)){
            ins.inserisci(k);
            int freq = 0;
            auto p2 = p;
            while(!L.end(p2)){
                if(k == L.read(p2))
                    freq++;
                p2 = L.next(p2);
            }
            cout << "element " << k << " freq " << freq << endl;
        }
        p = L.next(p);
    }
}

void remp(List_pointer<int> &L){
    List_pointer<int>::position p = L.begin();

    while(!L.end(L.next(p))){
        if(L.read(L.next(p)) % 2 != 0)
            L.erase(p);
        p = L.next(p);
    }
}

int main()
{
    List_pointer<int> int_list;
    List_pointer<int>::position p = int_list.begin();

    for (int i = 1; i < 10; i++)
        int_list.insert(i, p);
    int_list.insert(2, p);int_list.insert(2, p);int_list.insert(3, p);int_list.insert(5, p);


    cout << int_list;
    int m = 4;
    int x = freq(int_list, m);
    cout << "multiples of "<< m << ": " << x<<endl;
    hist(int_list);
    remp(int_list);
    cout << int_list;

    /***** recommender *****/
    recommender r;

    r.insert("u1","p1",1);
    r.insert("u1","p3",3);
    r.insert("u1","p5",4);
    r.insert("u2","p1",2);
    r.insert("u2","p2",3);
    r.insert("u2","p3",3);
    r.insert("u3","p1",1);
    r.insert("u3","p2",1);
    r.insert("u3","p3",1);
    r.insert("u3","p5",5);
    r.insert("u4","p3",2);
    r.insert("u4","p4",4);
    r.insert("u5","p2",3);
    r.insert("u5","p3",2);
    r.insert("u6","p4",2);

    string u = "u1";
    cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;
    u = "u2"; cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;
    u = "u3"; cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;
    u = "u4"; cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;
    u = "u5"; cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;
    u = "u6"; cout << "mean for "<< u<<" is " << r.meanUser(u)<<endl;

    u = "p1"; cout << "mean for "<< u<<" is " << r.meanItem(u)<<endl;
    u = "p2"; cout << "mean for "<< u<<" is " << r.meanItem(u)<<endl;
    u = "p3"; cout << "mean for "<< u<<" is " << r.meanItem(u)<<endl;
    u = "p4"; cout << "mean for "<< u<<" is " << r.meanItem(u)<<endl;
    u = "p5"; cout << "mean for "<< u<<" is " << r.meanItem(u)<<endl;

    List<string> rated = r.rated("u1");
    cout << "rated products of u1 "<< rated<<endl;
    List<string> rated2 = r.rated("u2");
    cout << "rated products of u2 "<< rated2<<endl;
    List<string> comms = r.common("u1","u2");
    cout << "common rated products for u1 and u2" <<endl<< comms<<endl;
    int y = r.commonEqual("u1","u2");
    cout << "common rated equals for u1 and u2: " << y << endl;
    return 0;
}
