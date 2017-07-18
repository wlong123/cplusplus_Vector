#include <iostream>
#include <string>


using namespace std;


/*
	Header for for the Vector. Constructors are implemented and the methods and variables
	are declared
*/
template <class T>
struct Vector {
	//fields
	int capacity;
	int size;
	T *array;
	
	//default constructor. sets capacity to 10
	Vector () {
		array = new T[10];
		capacity = 10;
		size = 0;
	}
	
	//constructor with an inputted capacity
	Vector (int initCapacity) {
		if(initCapacity <= 0)
			throw invalid_argument("Initial capacity cannot be less than or equal to zero");
		array = new T[initCapacity];
		capacity = initCapacity;
		size = 0;
	}
	
	//copy constructor
	Vector (Vector<T>* other) {
		if(!other)
			throw invalid_argument("cannot copy an empty vector");
		array = new T[other->size];
		for(int i = 0; i < other->size; i++)
		{
			array[i] = other->get(i);
		}
		size = other->size;
		capacity = other->capacity;
	}
	
	//methods
	void add(T toAdd);
	void add(int index, T toAdd);
	void print();
	void increaseCapacity();
	T get(int index);
	T remove(int index);
	bool removeObj(T obj);
	T set(int index, T obj);
	void clear();
	bool isEmpty();
	bool contains(T obj);
	int indexOf(T obj);
	
	
};

