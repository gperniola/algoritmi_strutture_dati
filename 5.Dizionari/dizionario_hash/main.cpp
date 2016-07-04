#include <iostream>
#include "hash_table.h"

using namespace std;

int main()
{
    hash_table<string, string> dict(1000);
    mypair<string,string> the_pair;

    the_pair.first = "FIRSTKEY";
    the_pair.second = "first value";
    dict.insert(the_pair);

    the_pair.first = "SECONDKEY";
    the_pair.second = "second value";
    dict.insert(the_pair);

    the_pair.first = "THIRDKEY";
    the_pair.second = "third value";
    dict.insert(the_pair);

    the_pair.first = "FOURTHKEY";
    the_pair.second = "fourth value";
    dict.insert(the_pair);

    the_pair.first = "FIFTHKEY";
    the_pair.second = "fifth value";
    dict.insert(the_pair);

    string str1 = "FIFTHKEY";
    string str2 = "modded";
    dict.modify(str1, str2);

    cout << dict.size() << endl;

    return 0;
}
