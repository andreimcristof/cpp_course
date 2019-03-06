#include <iostream>
#include <string>
#include "ctortest2.h"

using namespace std;

namespace ctortest {
    Character::Character()
    {
        this->name = new string("Default Name");
        this->health = new float(100.f);
        
        cout << "the character " << *this->name << " was created!" << endl;
    }

    Character::~Character()
    {
        cout << "the character " << *this->name << " was destroyed!" << endl;

        // we must specifically release also the memory addresses for the properties of the class.
        delete this->health;
        delete this->name;
    }

    void Character::PrintHealth()
    {
        cout << "Character health: " << this->health << endl;
    }

    void Actor::PrintHealth()
    {
        cout << "_Actor health: " << this->health << endl;
    }

    void Pawn::PrintHealth()
    {
        cout << "Pawn health: " << this->health << endl;
    }
}