#include <iostream>
#include <string>
#include <sstream>
#include "hash_trabocco.h"

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main()
{

    Hash_trabocco<string,string> ht(12);

    mypair<string,string> PR;
    for (int i = 0; i < 13; i++){
        PR.first = patch::to_string(i);
        PR.second = "VAL" + patch::to_string(i);
        //ss << i;
        //PR.first = ss.str();
        //PR.second = "VAL" + ss.str();
        ht.inserisci(PR);
    }
    PR.first = "2";
    PR.second = "EX";
    ht.inserisci(PR);
    PR.second = "EX2";
    ht.inserisci(PR);

    ht.stampaDizionario();

    string key;
    for (int i = 0; i<15;i++){
        //ss << i;
        //key = ss.str();
        key = patch::to_string(i);
     cout << key << " present: " << ht.appartiene(key) << endl;
    }

    for (int i = 5; i<10;i++){
        //ss << i;
        //key = ss.str();
        key = patch::to_string(i);
        ht.cancella(key);
    }

    ht.stampaDizionario();

    for (int i = 0; i<15;i++){
        //ss << i;
        //key = ss.str();
        key = patch::to_string(i);
     cout << key << " present: " << ht.appartiene(key) << endl;
    }

    string val;
    for (int i = 0; i<15;i++){
        //ss << i;
        //key = ss.str();
        key = patch::to_string(i);
        val = ht.recupera(key);
     cout << "value of " << key << ": " << val << endl;
    }

    return 0;
}
