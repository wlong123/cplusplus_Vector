#include <iostream>
#include <string>
#include "Vector.cpp"

using namespace std;

int main() {
	try{
		Vector<int>* a = new Vector<int>(0);
	}
	catch (invalid_argument e)
	{
		cout << "caught invalid argument error 1" << endl;
	}
	Vector<int>* arr = new Vector<int>(5);
	cout << arr->capacity << endl;
	arr->increaseCapacity();
	cout << arr->capacity << endl;
	arr->add(3);
	try{
		arr->get(5);
	}
	catch(out_of_range e) {
		cout << "caught out of bounds error 1" << endl;
	}
	cout << arr->get(0) << endl;
	cout << arr->size << endl;
	try{
		arr->add(25, 10);
	}
	catch (out_of_range e) {
		cout << "caught out of bounds error 2" << endl;
	}
	arr->add(0,2);
	arr->add(4);
	arr->add(5);
	arr->add(0,1);
	cout << arr->get(0) << endl;
	cout << arr->get(1) << endl;
	arr->print();
	try{
		arr->remove(-1);
	}
	catch(out_of_range e) {
		cout << "caught out of bounds error 3" << endl;
	}
	cout << arr->remove(0) << endl;
	arr->print();
	cout << arr->remove(3) << endl;
	arr->print();
	arr->add(21);
	arr->print();
	cout << "TESTING REMOVEOBJ" << endl;
	cout << arr->removeObj(21) << endl;
	cout << arr->removeObj(12) << endl;
	arr->print();
	cout << arr->get(2) << endl;
	cout << arr->indexOf(2) << endl;
	cout << arr->indexOf(3) << endl;
	cout << arr->indexOf(4) << endl;
	cout << arr->indexOf(10) << endl;
	cout << arr->indexOf(NULL) << endl;
	cout << "TESTING Contains" << endl;
	cout << arr->contains(10) << endl;
	cout << arr->contains(3) << endl;
	cout << "TESTING ISEMPTY" << endl;
	cout << arr->isEmpty() << endl;
	Vector<int>* emptyarr = new Vector<int>();
	cout << emptyarr->isEmpty() << endl;
	//emptyarr->print();
	emptyarr->add(11);
	cout << "TESTING CLEAR" << endl;
	emptyarr->print();
	emptyarr->clear();
	emptyarr->print();
	try{
		arr->set(-1,3);
	}
	catch (out_of_range e) {
		cout << "caught out of bounds error 4" << endl;
	}
	try{
		arr->set(10,3);
	}
	catch (out_of_range e) {
		cout << "caught out of bounds error 5" << endl;
	}
	cout << arr->set(1,10) << endl;
	arr->print();
	cout << "TESTING COPY CONSTRUCTOR" << endl;
	Vector<int>* copy = new Vector<int>(arr);
	copy->print();
	try{
		Vector<int>* a;
		Vector<int>* b = new Vector<int>(a);
	}
	catch (invalid_argument e)
	{
		cout << "caught invalid argument error 2" << endl;
	}
	
	return 0;
}