#include <iostream>
#include <string>
#include "pointers.h"
#include "ctortest.h"

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
	NumPtr++; // since pointers to arrays point to the first element of the array, iaaaancrementing the pointer can access subsequent array elements
	cout << *NumPtr << endl;
	NumPtr += 3;
	cout << *NumPtr << endl;

	// 3
	Container container = { "Sam", 1, 2, 3 };
	Container* PtrToContainer = &container; // specify pointer type, so that you can point to the address of that type

	cout << (*PtrToContainer).Name << endl; // pointers to any type can be dereferenced, to get the underlying value
	cout << (*PtrToContainer).X << endl; // paren ensures that the pointer is first dereferenced, then the operand dot can be used to get the prop. Its about the order of operations necessary for the <<
	cout << PtrToContainer->Name << endl; // this also dereferences the pointer. its syntactic sugar, better readability. 

	// 4
	ctortest::Chihuahua doggo("rex");
	cout << doggo.Age << endl;

	system("pause");
}