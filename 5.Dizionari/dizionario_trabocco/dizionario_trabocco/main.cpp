#include <iostream>
#include <string>
#include "hash_trabocco.h"


#include "list_pointer.h"
using namespace std;

int main()
{

    /*List_pointer<int> zeta;
    auto p = zeta.begin();

    cout << zeta << endl;
    zeta.insert_ordered(5);
    cout << zeta << endl;
    zeta.insert_ordered(1);
    cout << zeta << endl;
    zeta.insert_ordered(3);
    cout << zeta << endl;
    zeta.insert_ordered(2);
    cout << zeta << endl;
    zeta.insert_ordered(0);
    cout << zeta << endl;
    zeta.insert_ordered(5);
    cout << zeta << endl;
    zeta.insert_ordered(8);
    cout << zeta << endl;
    auto b = zeta.linear_ord_search(2);
    zeta.erase(b);
    cout << zeta << endl;*/

    Hash_trabocco<string,string> ht(12);

    mypair<string,string> PR;
    for (int i = 0; i < 14; i++){
        PR.first = to_string(i);
        PR.second = "VAL" + to_string(i);
        ht.inserisci(PR);
    }

    ht.stampaDizionario();

    //cout << endl << "SIZE : " << ht.size() << endl;

    string key;
    for (int i = 0; i<15;i++){
        key = to_string(i);
     cout << key << " present: " << ht.appartiene(key) << endl;
    }
    /*for (int i = 3; i<6;i++)
        ht.cancella(PR[i].first);*/


    for (int i = 2; i<14;i++){
        key = to_string(i);
        ht.cancella(key);
    }

    ht.stampaDizionario();

    for (int i = 0; i<15;i++){
        key = to_string(i);
     cout << key << " present: " << ht.appartiene(key) << endl;
    }

    /*//cout << endl << "SIZE : " << ht.size() << endl;

    for (int i = 0; i<11;i++)
        cout << PR[i].first << " present: " << ht.appartiene(PR[i].first) << endl;

    //for (int i = 0; i<11;i++)
        //cout << "Recovering: " << PR[i].first << " value: " << ht.recupera(PR[i].first) << endl;
   // string st1 = "KEYDIECI", st2 = "MODIFIED VALUE";
    string st3 = "KEYELEVEN", st4 = "VALUE NOT PRESENT";

    ////PR[2].first = "KEYTRE"; PR[2].second = "VALUE ILLEGAL MOD";
    //ht.modifica(st1,st2);
    //ht.modifica(st3,st4);
    //ht.cancella(st1);
    //PR[12].first = st1;
    //PR[12].second = st2;
   // ht.inserisci(PR[12]);
    //ht.stampaDizionario();*/
    return 0;
}
