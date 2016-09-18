#include <iostream>

#include "list_pointer.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    List_pointer<int> list1, list2, list4, list5, list6, list7,list10,list11;
    List_pointer<int>::position iter1, iter2, iter4, iter5, iter6, iter10,iter11;
    int x;
    iter1 = list1.begin();
    iter2 = list2.begin();
    iter4 = list4.begin();
    iter5 = list5.begin();
    iter6 = list6.begin();

    iter10 = list10.begin();
    iter11 = list11.begin();
	/*inserting three elements into the list list1 */
	x = 1;
  list1.insert(x, iter1);
  list1.insert(x, iter10);
  list1.insert(x, iter11);
	x = 2;
  list1.insert(x, iter1);
    list1.insert(x, iter10);
  list1.insert(x, iter11);
	x = 3;
  list1.insert(x, iter1);
    list1.insert(x, iter10);
  list1.insert(x, iter11);
	x = 4;
  list1.insert(x, iter1);
    list1.insert(x, iter10);
  list1.insert(x, iter11);
  cout << list1;

  	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */
	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

    /* get size of list1 and list2 */
    cout << "size of list1 = " << list1.size() << endl;
    cout << "size of list2 = " << list2.size() << endl;

    /* pushing elements in front and back of list1 */
    cout << "pushing 8 in front and 9 in back of list1..." <<endl;
    list1.push_front(8); list1.push_back(9);
    cout << list1 << endl;

    /* popping elements in front and back of list1 */
    cout << "popping front and back of list1..." <<endl;
    list1.pop_front(); list1.pop_back();
    cout << list1 << endl;

    /*trying copy constructor*/
    cout << "Trying copy constructor..."<< endl;
    List_pointer<int> list3(list1);
    cout << "list1 = " << list1 << "list3 = " << list3 << endl;

    /* clearing list1*/
    cout << "clearing list1..." << endl;
    list1.clear();
    cout << "list1 is empty and list3 still copied." << endl;
    cout << "list1 = " << list1 << "list1 is empty = " << list1.empty() << endl;
    cout << "list3 = " << list3 << "list3 is empty = " << list3.empty() << endl;

    /*inverting list3*/
    cout << "inverting list3" <<endl;
    list3.invert();
    cout << "list3 = " << list3 << endl;

    /*testing palindrome*/
    cout << "list3 is palindrome = " << list3.is_palindrome() << endl;

    x = 1;
    list4.insert(x, iter4);
	x = 2;
    list4.insert(x, iter4);
	x = 2;
    list4.insert(x, iter4);
	x = 1;
    list4.insert(x, iter4);

    cout << "list4 is palindrome = " << list4.is_palindrome() << endl;

    cout << endl << "merging list5 with list6 inside list7 ..." <<endl;
    list5.insert(11,iter5);
    list5.insert(9, iter5);
    list5.insert(5, iter5);
    list5.insert(3, iter5);
    list5.insert(1, iter5);
    list6.insert(6, iter6);
    list6.insert(4, iter6);
    list6.insert(2, iter6);
    cout << "list5 = " << list5;
    cout << "list6 = " << list6;
    list7.merge_ord(list5, list6);
    cout << "list7 = " << list7;

    cout << endl << "merging list6 inside list5 (using a static function) ..." <<endl;
    List_pointer<int>::merge_ord_2(list5, list6);
    cout << "list5 = " << list5 << endl;


    cout << "list10 = " << list10;
    cout << "list11 = " << list11 <<endl;

    bool status = false;
    if ( list10 == list11)
        status = true;
    else
        status = false;
    cout << "list10 is equal list11? " << status << endl;

    list11.erase(list11.begin());
    iter11 = list11.begin();
    list11.insert(15,iter11);
    cout << "list11 = " << list11;
    if ( list10 == list11)
        status = true;
    else
        status = false;
    cout << "list10 is equal list11? " << status << endl;

    return 0;
}
