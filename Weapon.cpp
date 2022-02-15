#include "Weapon.h"
#include <string>
#include <vector>

using namespace std;

// define constructor
Weapon::Weapon(){
    name = "";
    innocence = false;
}

// define parameterized constructor
Weapon::Weapon(string newName, bool newInnocence){
    name = newName;
    innocence = newInnocence;
}

string Weapon::getName(){
    // returns the name of the weapon
    return name;
}

void Weapon::setName(string newName){
    // sets the name of the weapon to the input name 
    name = newName;
}

bool Weapon::getInnocence(){
    // returns the room's innocence
    return innocence;
}

void Weapon::setInnocence(bool newInnocence){
    // sets the room's innocence to the input innocence 
    innocence = newInnocence;
}


