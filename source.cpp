#include <iostream>
#include <string>
#include "pointers.h"
#include "ctortest.h"
#include "ctortest2.h"

using namespace ctortest;
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

	system("pause");
}