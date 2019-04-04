#include <iostream>
#include "pointers.h"

using namespace std;

namespace pointerstest 
{   
    void doubleTheValue(int* intPtr) {
        //intPtr*  is the dereferenced value
        *intPtr *= 2;
    }

    int getUnderlyingValueOfPointer(int number) {
        int* ptrToInt;

        ptrToInt = &number;
        return *ptrToInt;

        // cout << ptrToInt << endl; // gets the hexa address
        // cout << *ptrToInt << endl; // gets the stored value / dereferencing pointer
    }

    int* getLargestIntPtr(int* firstIntPtr, int* secondIntPtr) {
        int firstValue = *firstIntPtr;
        int secondValue = *secondIntPtr;
        return firstValue > secondValue ? firstIntPtr : secondIntPtr;
    }
}