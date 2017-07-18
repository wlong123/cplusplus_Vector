#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

/**
	Vector Class where all of the methods are implemented. Template <class T> allows
	you to use generics.
*/


/*
	Add method that takes in an object that is added to the end of the vector
*/
template <class T>
void Vector<T>::add(T toAdd) {
	if(size >= capacity) 
		increaseCapacity();
	array[size] = toAdd;
	size++;	
}

/*
	add method that adds an object to a specified spot in the vector
*/
template <class T>
void Vector<T>::add(int index, T toAdd) {
	if(size >= capacity) 
		increaseCapacity();
	if((index > size) || (index < 0)) {
		throw out_of_range("tried to add a value to a spot that is not in the array");
	}
	size++;
	for(int i = index; i < size; i++)
	{
		T temp = get(i);
		array[i] = toAdd;
		toAdd = temp;
	}
}

/*
	print method for the vector
*/
template <class T>
void Vector<T>::print() {
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		if(i == size - 1)
			cout << array[i];
		else{
			cout << array[i] << ", ";
		}
	}
	cout << "]";
	cout << endl;
}

/*
	doubles the capacity of the vector
*/
template <class T>
void Vector<T>::increaseCapacity() {
	T *temp = array;
	array = new T[capacity * 2];
	for(int i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	capacity = capacity * 2;
}

/*
	gets the object at a specified index in the vector
*/
template <class T>
T Vector<T>::get(int index) {
	if((index >= size) || (index < 0))
		throw out_of_range("tried to get the value of a spot that is not in the array");
	return array[index];
}

/*
	removes the object at a specified index in the vector
*/
template <class T>
T Vector<T>::remove(int index) {
	if((index >= size) || (index < 0))
		throw out_of_range("tried to remove a value at a spot that is not in the array");
	T output = array[index];
	for(int i = index; i < size - 1; i++)
	{
			array[i] = array[i + 1];
	}
	size--;
	return output;
}

/*
	removes an inputted object from the vector. Returns whether or not the remove was 
	successful. ! for true and 0 for false
*/
template <class T>
bool Vector<T>::removeObj(T obj) {
	if(contains(obj) == false)
		return false;
	int i = indexOf(obj);
	remove(i);
	return true;
}

/*
	sets an inputted object at an inputted index. The object that was previously at
	that spot in the vector is returned	
*/
template <class T>
T Vector<T>::set(int index, T obj) {
	if((index >= size) || (index < 0))
		throw out_of_range("tried to set a value at a spot that is not in the array");
	T output = array[index];
	array[index] = obj;
	return output;
}

/*
	clears all of the objects in the vector
*/
template <class T>
void Vector<T>::clear() {
	array = new T[capacity];
	size = 0;
}

/*
	returns whether the vector contains an inputted object. 1 for true and 0 for false
*/
template <class T>
bool Vector<T>::contains(T obj) {
	if(indexOf(obj) >= 0)
		return true;
	return false;
}

/*
	returns whether the vector is empty or not. 1 for true and 0 for false
*/
template <class T>
bool Vector<T>::isEmpty() {
	if(size == 0)
		return true;
	return false;
}

/*
	returns the index of an inputted object. returns -1 if the object is not in the vector
*/
template <class T>
int Vector<T>::indexOf(T obj) {
	if(!obj)
	{
		for(int i = 0; i < size; i++)
		{
			if(!array[i])
				return i;
		}
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			if(obj == array[i])
				return i;
		}
	}
	return -1;
}


