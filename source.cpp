#include <iostream>
#include <string>
#include "pointers.h"
#include "ctortest.h"
#include "ctortest2.h"
#include "vectortest.h"

using namespace ctortest;
using namespace std;

// g++ -o /tmp/output.sh *.cpp -std=c++14

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
	Chihuahua doggo("rex");
	cout << doggo.Age << endl;

	// 5 dynamic cast in c++
   	Character* charPtr = new Character;
	charPtr->PrintHealth();
    Actor* actorPtr = new Actor;
	Pawn* pawnPtr = new Pawn;

	Character* charArr[] = { charPtr, actorPtr, pawnPtr };
	for(int i = 0; i< 3; i++)
	{
		Character* cPtr = charArr[i];
		cPtr->CharacterFn(); // works because this fn is inherited by all types. 

		Actor* aPtr = dynamic_cast<Actor*>(cPtr); // will either succeed or fail depending on type
		if(aPtr != nullptr) 
			aPtr->ActorFn();

		Pawn* pPtr = dynamic_cast<Pawn*>(cPtr);
		if(pPtr) // same as comparing with nullptr 
			pPtr->PawnFn(); 
	}
	
	// releasing all resources
    delete charPtr; // deleting the pointer
    charPtr = nullptr; // set to nullptr

    delete actorPtr;
    actorPtr = nullptr;

    delete pawnPtr;
    pawnPtr = nullptr;



    // 6 
	// practicing memory allocatins /deallocations
    int* p = new int(5);
    cout << &p << endl; // address
    cout << *p << endl; // getting the value by dereferencing the pointer

    delete p; //free up the memory address that p was pointing to, so that the address can further be used
    p = nullptr; // this avoids a "dangling" pointer, which is a pointer that points to nothing


	// 7 pointers practice 
	int tt = {100};
	int* ttptr =  {&tt};
	cout << "test " << *ttptr << endl;

	int first = {300};
	int* firstPtr = &first;
	int second = {100};
	int* secondPtr = &second; 

	int* largest = pointerstest::getLargestIntPtr(&first, &second);
	cout << "largest pointer pointed to: " << *largest << endl;

	double highTemp = {100.7};
	double lowTemp = {33.1};
	double* tempPtr = {&highTemp};
	cout << "tempPtr points to: " << *tempPtr << endl;
	tempPtr  = &lowTemp;
	cout << "tempPtr points to: " << *tempPtr << endl;

	string name = "Name1" ;
	string* namePtr = &name;
	cout << "namePtr points to:" << *namePtr << endl;
	name = "Name2";
	cout << "namePtr points to:" << *namePtr << endl;

	// 8 dynamic memory allocation
	int* intPtr = nullptr;
	intPtr = new int; // allocate an int on the heap
	*intPtr = 100;
	cout << *intPtr << endl;		
	delete intPtr; // release / deallocate storage

	int* arrayPtr { nullptr };
	int size {4};
	arrayPtr = new int[size];
	delete arrayPtr;


	// 9 vector tests
	std::vector<int> {0,1};	

	int test {5};
	int* testPtr = &test;
	cout << "reasignation of underlying pointed value" << endl;
	cout << *testPtr << endl;
	pointerstest::doubleTheValue(testPtr);
	cout << *testPtr << endl;

	// 10 
	system("pause");
}