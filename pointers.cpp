#include <iostream>
#include "pointers.h"

// to compile all in vs code: g++ -o output.sh *.cpp

using namespace std;

namespace pointerstest 
{   
    int getUnderlyingValueOfPointer(int number)
    {
        int* ptrToInt;

        ptrToInt = &number;
        return *ptrToInt;

        // cout << ptrToInt << endl; // gets the hexa address
        // cout << *ptrToInt << endl; // gets the stored value / dereferencing pointer
    }
}