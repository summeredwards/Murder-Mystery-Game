#include "Character.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// define constructor
Character::Character(){
    name = "";
    power = 0;
    points = 0;
    innocence = false;
    room = "The Hallway";
}
// define parameterized constructor 
Character::Character(string newName, int newPoints, bool newInnocence, vector<string> newEvidence, int newPower){
    name = newName;
    points = newPoints;
    innocence = newInnocence;
    power = newPower;

    // sets evidence in input vector to the evidence vector 
    for (int i=0; i<newEvidence.size(); i++){
        evidence.push_back(newEvidence[i]);
    }
}

int Character::getPoints(){
    // returns the character's points 
    return points;
}

void Character::setPoints(int newPoints){
    // sets points to input number 
    points = newPoints;
}

void Character::addPoints(int newPoints){
    // adds input number to the character's points
    points = points + newPoints;
}

bool Character::getInnocence(){
    // returns the character's innocence 
    return innocence;
}

void Character::setInnocence(bool newInnocence){
    // sets the character's innocene to the input innocence 
    innocence = newInnocence;
}

void Character::getEvidence(){
    // goes through evidence vector and prints the evidence
    for (int i=0; i < evidence.size(); i++){
        cout << evidence[i] << " | ";
    }
    cout << endl;
}

string Character::getEvidenceAt(int index){
    string theEvidence = "";

    // gets the evidence from the evidence vector at the input index
    theEvidence = evidence[index];

    // returns that piece of evidence 
    return theEvidence;
}

int Character::getEvidenceSize(){
    int size = 0;

    // returns the size of the character's evidence vector 
    size = evidence.size();

    return size;
}

void Character::setEvidence(vector<string> newEvidence){
    // goes through the input evidence vector
    for (int i=0; i < newEvidence.size(); i++){
        // sets elemts form input vector to the evidence vector 
        evidence.push_back(newEvidence[i]);
    }
}

void Character::setEvidenceElement(string newEvidence){
    // places the input evidence into the evidence vector 
    evidence.push_back(newEvidence);
}

void Character::eraseEvidence(int index){
    // erases evidence at the input index 
    evidence.erase(evidence.begin()+index);
}

string Character::getName(){
    // returns the character name 
    return name;
}

void Character::setName(string newName){
    // sets the character name to the input name
    name = newName;
}

string Character::getRoom(){
    // returns the room the character is currently in
    return room;
}

void Character::setRoom(string newRoom){
    // sets the room the character is in to the input room
    room = newRoom;
}

int Character::getPower(){
    // returns the character's power
    return power;
}

void Character::setPower(int newPower){
    // adds input number to the character's power
    power = power + newPower;
}