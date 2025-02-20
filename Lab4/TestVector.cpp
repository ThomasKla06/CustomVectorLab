#include "customVector.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	customVector<int> vec;
	vec.append(1);
	vec.append(2);
	vec.append(3);
	vec.append(4);
	vec.append(5);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	vec.set(2, 8);
	cout << "Testing set:\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	vec.remove(2);
	cout << "Test remove:\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	vec.insert(2, 3);
	cout << endl;
	cout << "Test insert:\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	cout << "Test reverse:\n";
	vec.reverse();
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	vec.reverse();
	cout << "Reverse back:\n";

	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	customVector<int> vec2;
	vec2.append(6);
	vec2.append(7);
	vec2.append(8);
	vec2.append(9);
	vec2.append(10);
	customVector<int> vec3;
	cout << "Testing Addition: \n";
	vec3 = vec + vec2;
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3.get(i) << " ";
	}
	cout << "\nTesting find:\n";
	cout << "Looking for 3 in vec:\n";
	cout << "3 is at index " << vec.find(3) << endl;
	cout << "Looking for 8:\n";
	if (vec.find(8) == -1) {
		cout << "8 not found\n";
	}
	else {
		cout << "Something wrong with .find\n";
	}
	cout << "Testing direct printing:\n";
	cout << vec;
}