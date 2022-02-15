#include "Room.h"
#include <string>
#include <vector>

using namespace std;

// define constructor 
Room::Room(){
    name = "";
    innocence = false;
}

// define parameterized constructor 
Room::Room(string newName, bool newInnocence){
    name = newName;
    innocence = newInnocence;
}

string Room::getName(){
    // returns the room name 
    return name;
}

void Room::setName(string newName){
    // sets the room name to the input name 
    name = newName;
}

bool Room::getInnocence(){
    // returns the room's innocence 
    return innocence;
}

void Room::setInnocence(bool newInnocence){
    // sets the room's innocence to the input innocence 
    innocence = newInnocence;
}