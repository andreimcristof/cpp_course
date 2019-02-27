#include <iostream>
#include <string>
#include "ctortest.h"

using namespace std;

namespace ctortest
{
    Dog::Dog()
    {
        Name = "Default dog";
        
        Age = 1;
        Health = 100.f;

        Dog::Bark();
    }

    Dog::Dog(string name)    
       :Name(name)
    {
        Age = 1;
        Health = 100.f;

        Dog::Bark();
    }

    void Dog::Bark()
    {
        cout << "woof " + Name + ", " + to_string(Health) << endl;
    };

    Chihuahua::Chihuahua(string name)
    : Dog::Dog(name)
    {

    }
};
