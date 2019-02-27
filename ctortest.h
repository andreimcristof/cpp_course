#include <string>

using namespace std;

namespace ctortest
{
    class Dog 
    {

    public:
        Dog();
        Dog(string Name);

        string Name;
        int Age;
        float Health;

        void Bark();
    };

    class Chihuahua: public Dog
    {
    public:
        Chihuahua(string Name);
    };
};