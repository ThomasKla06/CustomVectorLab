#pragma once
#include <iostream>
using namespace std;

//Thomas Klaesges

template<typename T>
class customVector {

//FIELDS
private:
	int length;     //Number of items in vector
	int capacity;  //The number of spaces in data
	T* data;      //This array will need to be manually allocated

public:
	//CONSTRUCTORS
	customVector() {
		//This should be an "empty" vector
		length = 0;
		capacity = 16;
		//Manually allocate an array of 16 Ts
		data = new T[capacity];
	}

	//COPY CONSTRUCTOR - for things like customVector vec{v1};
	customVector(const customVector<T>& other) {
		//We need to copy other fields into our fields
		length = other.length;
		capacity = other.capacity;
		data = new T[capacity];
		//Copy all items from other data
		for (int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}
	}

	//DESTRUCTOR
	~customVector() {
		delete[] data;
	}

	//COPY ASSIGNMENT OPERATOR OVERLOAD
	customVector<T>& operator=(const customVector<T> other) {
		//Step 1 delete
		delete[] data;

		//Step 2 copy over new values
		capacity = other.capacity;
		data = new T[capacity];
		length = other.length;

		for (int i = 0; i < length; i++)
			this->data[i] = other.data[i];

		return *this;
	}

	//METHODS
	//simple adding method
	void append(T item) {
		if (length >= capacity) {
			T* tmp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				tmp[i] = data[i];
			}
			delete[] data;
			data = tmp; //repoints data pointer to the thing tmp points to 
			capacity *= 2;
		}
		//Put the item at the first empty index
		data[length] = item;

		//Increase length stoopood
		length++;
	}
		
	//simple getter
	T get(int i) const {
		return data[i];
	}

	//sets item at index to the new item
	void set(int i, T item) {
		data[i] = item;
	}

	//Inserts an item at the specified index and adjusts the rest of the list to fit 
	void insert(int i, T item) {
		if (length + 1 > capacity) {
			capacity *= 2;
		}
		for (int j = length; j > i; j--) {
			data[j] = data[j - 1];
		}
		length++;
		data[i] = item;
	}

	//Removes item at specified index and returns the item removed
	T remove(int index) {
		T type = data[index];
		for (int j = index; j < length; j++) {
			data[j] = data[j + 1];
		}
		length--;
		return type;
	}

	//Returns size of vector
	int size() {
		return length;
	}

	//Reverses the elements in the vector
	void reverse() {
		T* tmp = new T[capacity];
		for (int i = 0; i < length; i++) {
			tmp[i] = data[length - 1 - i];
		}
		delete[] data;
		data = tmp;
	}

	//Finds and returns index of the first occurence of a specified item. If not found, returns -1
	T find(T item) {
		bool isFound{ false };
		int indic;
		for (int i = 0; i < length; i++) {
			if (data[i] == item) {
				isFound = true;
				indic = i;
			}
		}
		if (isFound) {
			return indic;
		}
		else {
			return -1;
		}
	}
	//Not Working yet gotta ask
	customVector<T> operator+(const customVector<T>& other) {
		int newLength = this->length + other.length;
		customVector<T> newVector;
		for (int i = 0; i < newLength; i++) {
			if (i < this->length) {
				newVector.append((data[i]));
			}
			else{
				newVector.append(other.data[i - length]);
			}
		}
		return newVector;
	}
	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const customVector<T>& vector);
	//Could potentially overload [] operator
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const customVector<T>& vector) {
	for (int i = 0; i < vector.length; i++) {
		out << vector.get(i) << " ";
	}
	return out;
}