#include <iostream>
using namespace std;

// compile with ctrl alt N.
int main() 
{
    int myInt = 7;
    int* ptrToInt;

    ptrToInt = &myInt;

    cout << ptrToInt << endl; // gets the hexa address
    cout << *ptrToInt << endl; // gets the stored value / dereferencing pointer
}