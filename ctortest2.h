#include <string>

using namespace std;

namespace ctortest {
    class Base
    {
    public:
        Base();
    };

    class DerivedFromBase : public Base
    {
    };

    class Character
    {
    public:
        Character();
        ~Character();
        
        string* name;
        float* health;
        
        virtual void PrintHealth();
        void CharacterFn();
    };

    class Actor : public Character
    {
    public:
        virtual void PrintHealth() override;
        void ActorFn();
    };
    
    class Pawn: public Actor
    {
    public:
        virtual void PrintHealth() override;
        void PawnFn();
    };

}