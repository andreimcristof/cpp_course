#include <iostream>
#include <string>
#include "pointers.h"

using namespace std;

struct Container
{
	string Name;

	int X;
	int Y;
	int Z;
};

int main()
{
	// 1
	cout << pointerstest::getUnderlyingValueOfPointer(7) << endl;


	// 2
	int numbers[] = { 0,1,2,3,4,5 };

	int* NumPtr = numbers;
	cout << *NumPtr << endl;
	NumPtr++; // since pointers to arrays point to the first element of the array, incrementing the pointer can access subsequent array elements
	cout << *NumPtr << endl;
	NumPtr += 3;
	cout << *NumPtr << endl;

	// 3
	Container container = { "Sam", 1, 2, 3 };
	Container* PtrToContainer = &container; // specify pointer type, so that you can point to the address of that type

	cout << (*PtrToContainer).Name << endl; // pointers to any type can be dereferenced, to get the underlying value

	system("pause");
}