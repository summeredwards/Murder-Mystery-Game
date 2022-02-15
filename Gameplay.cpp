#include "Character.h"
#include "Weapon.h"
#include "Room.h"
#include "Gameplay.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

// define constructor
Gameplay::Gameplay(){
    // set elements in the file to empty strings 
    murderer = "";
    theWeapon = "";
    theRoom = "";
}

// define parameterized constructor
Gameplay::Gameplay(Character newCharacters[], Weapon newWeapons[], Room newRooms[], string newMurderer, string newTheWeapon, string newTheRoom){
    // set character object array to characters array
    for (int i=0; i < 4; i++){
        characters[i] = newCharacters[i];
    }
    // set weapon object array to weapons array
    for (int j=0; j < 8; j++){
        weapons[j] = newWeapons[j];
    }
    // set room object array to rooms array
    for (int k=0; k < 7; k++){
        rooms[k] = newRooms[k];
    }
    // set murderer
    murderer = newMurderer;
    // set theWeapon
    theWeapon = newTheWeapon;
    // set theRoom
    theRoom = newTheRoom;
}

string Gameplay::getCharacterAt(int index){
    string characterName;

    // get the character name at the input index value 
    characterName = characters[index].getName();

    // return the name 
    return characterName;
}

void Gameplay::setCharacterAt(string newCharacter, int index){
    // set input character name at the given index 
    characters[index].setName(newCharacter);
}

string Gameplay::getWeaponAt(int index){
    string weaponName;

    // get the weapon name at the input index value 
    weaponName = weapons[index].getName();

    // return the name 
    return weaponName;
}

void Gameplay::setWeaponAt(string newWeapon, int index){
    // set input weapon name at the given index
    weapons[index].setName(newWeapon);
}

string Gameplay::getRoomAt(int index){
    string roomName;

    // get the room name at the input index value 
    roomName = rooms[index].getName();

    // return the name 
    return roomName;
}

void Gameplay::setRoomAt(string newRoom, int index){
    // set input room name at the given index 
    rooms[index].setName(newRoom);
}

int Gameplay::getIndex(){
    // return the user's character index from the character object array 
    return idx;
}

void Gameplay::setIndex(int index){
    // set the user's character index in the character object array 
    idx = index;
}

int Gameplay::getMurdererIndex(){
    // return the murderer's index in the character object array
    return murdererIdx;
}

string Gameplay::getMurderer(){
    // return the murderer
    return murderer;
}

void Gameplay::setMurderer(string newMurderer){
    // set the murderer as the input string 
    murderer = newMurderer;
}

int Gameplay::getTheWeaponIndex(){
    // return theWeapon's index in the weapon object array 
    return theWeaponIdx;
}

string Gameplay::getTheWeapon(){
    // return the weapon used
    return theWeapon;
}

void Gameplay::setTheWeapon(string newTheWeapon){
    // set the weapon used as the input string 
    theWeapon = newTheWeapon;
}

int Gameplay::getTheRoomIndex(){
    // return theRoom's index in the room object array 
    return theRoomIdx;
}

string Gameplay::getTheRoom(){
    // return the room it took place
    return theRoom;
}

string Gameplay::getCurrentRoom(){
    string theCurrentRoom = "";

    // gets the room the user is currently in 
    theCurrentRoom = characters[idx].getRoom();

    // return the room name 
    return theCurrentRoom;
}

void Gameplay::setTheRoom(string newTheRoom){
    // set the room it took place to the input string 
    theRoom = newTheRoom;
}

void Gameplay::addThePoints(int newPoints){
    // add the input points to the user's points 
    characters[idx].addPoints(newPoints);
}
//
// This function prints the stats of the desired character 
// Parameters: theCharacter - the character you want to check 
// Return: N/A 
//
void Gameplay::getCharacterStats(string theCharacter){
    // for the length of amount of characters
    for (int i=0; i < 4; i++){
        // if the character's name matches the input character name 
        if (characters[i].getName() == theCharacter){
            cout << " " << endl << "======= CHARACTER STATS =======" << endl;
            // print their name
            cout << "Name: " << characters[i].getName() << endl;
            // print their points
            cout << "Points: " << characters[i].getPoints() << endl;

            // check if their innocent or guilty
            bool innocent = characters[i].getInnocence();
            // if guilty
            if (innocent == false){
                cout << "Innocence: guilty" << endl;
            }
            // if innocent
            else{
                cout << "Innocence: innocent" << endl;
            }
            cout << "===============================" << endl;
        }          
    }
}

//
// This function prints the user's notes/checklist
// Parameters: N/A
// Return: N/A 
//
void Gameplay::PrintChecklist(){
    int k = 1, choice = 0, selected = 0, option = 0;
    string characterInnocence, weaponInnocence, roomInnocence;

    cout << "======= YOUR NOTES =======" << endl;
    // print innocence of each character
    for (int i=0; i < 4; i++){
        // if guilty
        if (characters[i].getInnocence() == 0){
            characterInnocence = "guilty";
        }
        // if innocent
        else{
            characterInnocence = "innocent";
        }
        cout << k << ". " << characters[i].getName() << ": " << characterInnocence << endl;
        k++;
    }
    cout << endl;
    // print innocence of each weapon 
    for (int j=0; j < 8; j++){
        // if guilty
        if (weapons[j].getInnocence() == 0){
            weaponInnocence = "guilty";
        }
        // if innocent
        else{
            weaponInnocence = "innocent";
        }
        cout << k << ". " << weapons[j].getName() << ": " << weaponInnocence << endl;
        k++;
    }
    cout << endl;
    // print innocence of each room
    for (int z=0; z < 7; z++){
        // if guilty
        if (rooms[z].getInnocence() == 0){
            roomInnocence = "guilty";
        }
        // if innocent 
        else{
            roomInnocence = "innocent";
        }
        cout << k << ". " << rooms[z].getName() << ": " << roomInnocence << endl;
        k++;
    }
    cout << "===========================" << endl;

    // GET if user wants to update notes
    cout << endl;
    cout << "Would you like to update your notes?" << endl << "1. Yes" << endl << "2. No" << endl;
    cout << "Select a numerical option" << endl;
    cin >> choice;

    // if yes 
    if (choice == 1){
        // GET element they want to edit 
        cout << "What would you like to edit? Select a numerical option." << endl;
        cin >> selected;

        // if selected is between 1 & 4
        if (selected >= 1 && selected <= 4){
            // get correct index of element 
            selected--;

            // GET innocence
            cout << "Is this option... " << endl << "1. Innocent" << endl << "2. Guilty" << endl;
            cout << "Select a numerical option." << endl; 
            cin >> option;

            // if innocent
            if (option == 1){
                // set innocence to innocent
                characters[selected].setInnocence(true);
            }
            // if guilty
            else if (option == 2){
                // set innocence to guilty
                characters[selected].setInnocence(false);
            }
        }
        // if selected if between 5 & 12
        else if (selected >= 5 && selected <= 12){
            // get correct index of element
            selected = selected - 5;

            // GET innocence 
            cout << "Is this option... " << endl << "1. Innocent" << endl << "2. Guilty" << endl;
            cout << "Select a numerical option." << endl; 
            cin >> option;

            // if innocent 
            if (option == 1){
                // set innocence to innocent 
                weapons[selected].setInnocence(true);
            }
            // if guilty
            else if (option == 2){
                // set innocence to guilty
                weapons[selected].setInnocence(false);
            }
        }
        // if selected is between 13 & 19 
        else if (selected >= 13 && selected <= 19){
            // get correct index of that element 
            selected = selected - 13;

            // GET innocence 
            cout << "Is this option... " << endl << "1. Innocent" << endl << "2. Guilty" << endl;
            cout << "Select a numerical option." << endl; 
            cin >> option;

            // if innocent 
            if (option == 1){
                // set innocence to innocent 
                rooms[selected].setInnocence(true);
            }
            // if guilty
            else if (option == 2){
                // set innocence to guilty
                rooms[selected].setInnocence(false);
            }
        }
        //otherwise
        else{
            cout << "Invalid input." << endl;
        }

        k = 1;

        // after user updates their notes print out the updated version
        cout << "======= YOUR NOTES =======" << endl;
        // prints characters' innocence 
        for (int g=0; g < 4; g++){
            // if guilty
            if (characters[g].getInnocence() == 0){
                characterInnocence = "guilty";
            }
            // if innocent 
            else{
                characterInnocence = "innocent";
            }
            cout << k << ". " << characters[g].getName() << ": " << characterInnocence << endl;
            k++;
        }
        cout << endl;
        // prints weapons' innocence 
        for (int h=0; h < 8; h++){
            // if guilty 
            if (weapons[h].getInnocence() == 0){
                weaponInnocence = "guilty";
            }
            // if innocent 
            else{
                weaponInnocence = "innocent";
            }
            cout << k << ". " << weapons[h].getName() << ": " << weaponInnocence << endl;
            k++;
        }
        cout << endl;
        k = 13;
        // prints rooms' innocence 
        for (int b=0; b < 7; b++){
            // if guilty
            if (rooms[b].getInnocence() == 0){
                roomInnocence = "guilty";
            }
            // if innocent 
            else{
                roomInnocence = "innocent";
            }
            cout << k << ". " << rooms[b].getName() << ": " << roomInnocence << endl;
            k++;
        }
        cout << "===========================" << endl;
    }
}

//
// This function prints the user's stats 
// Parameters: N/A
// Return: N/A 
//
void Gameplay::printUserStats(){
    // print the user's stats at each turn 
    cout << " " << endl << "======= YOUR STATS =======" << endl;
    // print name 
    cout << "Name: " << characters[idx].getName() << endl;
    // print points 
    cout << "Points: " << characters[idx].getPoints() << endl;

    // print user's innocence 
    bool innocent = characters[idx].getInnocence();
    // if guilty
    if (innocent == false){
        cout << "Innocence: guilty" << endl;
    }
    // if innocent
    else{
        cout << "Innocence: innocent" << endl;
    }
    // print location
    cout << "Location: " << characters[idx].getRoom() << endl;
    // print evidence 
    cout << "Evidence: ";
    characters[idx].getEvidence();
    cout << "===========================" << endl;
}

void Gameplay::selectFile(){
    int murdererIndex = 0, weaponIndex = 0, roomIndex = 0;

    // set the rand seed
    srand(time(NULL));

    // randomly select character index for murderer
    murdererIndex = rand()%4;
    // randomly select weapon index for theWeapon
    weaponIndex = rand()%8;
    // randomly select room index for theRoom
    roomIndex = rand()%7;

    // set the indeces
    murdererIdx = murdererIndex;
    theWeaponIdx = weaponIndex;
    theRoomIdx = roomIndex;

    // get the character's name and set it to the murderer
    murderer = characters[murdererIndex].getName();
    // get the weapon's name and set it to theWeapon
    theWeapon = weapons[weaponIndex].getName();
    // get the room's name and set it to theRoom
    theRoom = rooms[roomIndex].getName();
}

//
// This function filters through each character, each weapon, each 
// room that are NOT in the "File" and places them into each 
// character's evidence vector 
// Parameters: N/A
// Return: N/A 
//
void Gameplay::selectEvidence(){
    string selected = "";
    int k = 0;

    // goes through characters that are NOT the murderer, sets then to each character
    for (int i=0; i < 4; i++){
        // if index if not murderer index 
        if (i != murdererIdx){
            selected = characters[i].getName();
            characters[k].setEvidenceElement(selected);
            k++;
        }
    }
    // goes through weapons that are NOT theWeapon, sets then to each character
    for (int j=0; j < 8; j++){
        // if index if not theWeapon index
        if (j!= theWeaponIdx){
            selected = weapons[j].getName();
            characters[k].setEvidenceElement(selected);
            k++;
            if (k == 4){
                k = 0;
            }
        }
    }
    // goes through rooms that are NOT theRoom, sets then to each character
    for (int m=0; m < 7; m++){
        // if index if not theRoom index
        if (m !=theRoomIdx){
            selected = rooms[m].getName();
            characters[k].setEvidenceElement(selected);
            k++;
            if (k == 4){
                k = 0;
            }
        }
    }
    // test if it worked 
    // for (int b=0; b < 4; b++){
    //     cout << " " << endl << characters[b].getName() << " has this evidence: " << endl;
    //     characters[b].getEvidence();
    // }

}

//
// This function randomly selects 3 rooms and randomly selects a number from 1-3 for each room.
// The user can then select the desired room and the appropriate points will be added to the user's
// score, and their location will be updated
// Parameters: N/A
// Return: N/A 
//
void Gameplay::roomSelect(){
    int selected = 0, points = 0, choice = 0; 
    vector<int> thePoints;
    string theSelectedRooms[3];

    // set rand seed 
    srand(time(NULL));

    // randomly selects 3 rooms and points between 1-3 for each room 
    for (int i=0; i < 3; i++){
        selected = rand()%7;
        points = (rand()%3) + 1;
        // put selected rooms in an array 
        theSelectedRooms[i] = rooms[selected].getName();
        // put points in a vector 
        thePoints.push_back(points);
    }

    int k = 1;

    // GET the room
    cout << " " << endl << "Which room would you like?" << endl << "Select a numerical option." << endl;
    // prints each room with points
    for (int j=0; j < 3; j++){
        cout << k << ". " << theSelectedRooms[j] << " for " << thePoints[j] << " points " << endl;
        k++;
    }
    cin >> choice;

    // if choice is 1
    if (choice == 1){
        // add the points to the user's score 
        characters[idx].addPoints(thePoints[0]);
        // set the room to the user's location
        characters[idx].setRoom(theSelectedRooms[0]);

        cout << "You are now in " << theSelectedRooms[0] << ". Make a hypothesis or conclusion: " << endl;
    }
    // if choice is 2
    if (choice == 2){
        // add the points to the user's score 
        characters[idx].addPoints(thePoints[1]);
        // set the room to the user's location
        characters[idx].setRoom(theSelectedRooms[1]);
        
        cout << "You are now in " << theSelectedRooms[1] << ". Make a hypothesis or conclusion: " << endl;
    }
    // if choice is 3
    if (choice == 3){
        // add the points to the user's score 
        characters[idx].addPoints(thePoints[2]);
        // set the room to the user's location
        characters[idx].setRoom(theSelectedRooms[2]);
        
        cout << "You are now in " << theSelectedRooms[2] << ". Make a hypothesis or conclusion: " << endl;
    }
}

//
// This function takes the input room and updates the user's location to that room. The function then 
// adds 5 points to the user's score 
// Parameters: newRoom - the room the user wants to go 
// Return: N/A 
//
void Gameplay::pickRoom(string newRoom){
    // set input room to the user's location 
    characters[idx].setRoom(newRoom);
    // add 5 points to user's score 
    characters[idx].addPoints(5);

    cout << "You are now in " << newRoom << ". Make a hypothesis or conclusion: " << endl;
}

//
// This function checks if the user's conclusion is correct.
// Parameters: theMurderer - the guessed murderer, theGuessedWeapon - the weapon the user thinks was
// used. theGuessedRoom - the room the user thinks it took place 
// Return: correct - so the code knows if they guess wrong or right 
//
int Gameplay::checkConclusion(string theMurderer, string theGuessedWeapon, string theGuessedRoom){
    bool match = false;
    int correct = 0;

    // if the guess is right, match is true
    if (theMurderer == murderer && theGuessedWeapon == theWeapon && theGuessedRoom == theRoom){
        match = true;
    }

    // if guess is not right 
    if (match == false){
        cout << "You are not correct." << endl;
        // add one to user's power
        characters[idx].setPower(1);
        // if user guesses wrong twice
        if (characters[idx].getPower() == 2){
            // correct equals -1
            correct = -1;
        }
        // if user guesses wrong once
        else{
            // add 15 points to user's score
            characters[idx].addPoints(15);
        }
    }
    // if guess is right 
    else{
        cout << "You are correct! Congratulations, you win!" << endl;
            correct = -1;
    }

    return correct;
}

//
// This function goes through the chosen character's evidence vector and checks if any of their evidence matches
// to user's hypothesis. If there is a match, the function returns the evidence and deletes that piece of evidence
// from the character's evidence vector 
// Parameters: theCharacter - the character whose evidence we are checking, theMurderer - the guessed murderer, 
// theGuessedWeapon - the weapon the user thinks was used, theGuessedRoom - the room the user thinks it took place
// Return: match - the evidence that matches the description
//
string Gameplay::checkEvidence(string theCharacter, string theMurderer, string theGuessedWeapon, string theGuessedRoom){
    string match = "", theAskedCharacter = "";
    int characterIndex = 0, evidenceIndex = 0;
    bool found = false;

    // for the length of number of characters
    for (int i=0; i < 4; i++){
        // if the input character matches one of the characters in the characters array
        if (theCharacter == characters[i].getName()){
            // go through their evidence 
            for (int j=0; j < characters[i].getEvidenceSize(); j++){
                // check if any of their evidence matches the description
                if (theMurderer == characters[i].getEvidenceAt(j) || theGuessedWeapon == characters[i].getEvidenceAt(j) || theGuessedRoom == characters[i].getEvidenceAt(j)){
                    // if matches, set that evidence to match variable 
                    match = characters[i].getEvidenceAt(j);
                    // save the character index
                    characterIndex = i;
                    // save the evidence index
                    evidenceIndex = j;
                    found = true;
                    break;
                }
            }
        }
    }
    // if found a match 
    if (found == true){
        // erase that evidence from the vector 
        characters[characterIndex].eraseEvidence(evidenceIndex);
    }

    // return that matched evidence 
    return match;
}

//
// This function runs when it is another character's turn (not the user's). It will add the appropriate points 
// to that character's score. The function will randomly select a number between 1-4 (bc there are 4 characters).
// If the number is 1, then that means the character is asking the user for evidence. The function then goes through the 
// user's evidence to see if theres a match. 
// Parameters: index - the index of the character when it's their turn
// Return: N/A 
//
void Gameplay::characterTurn(int index){
    int points = 0, ask = 0, characterIndex = 0, weaponIndex = 0, roomIndex = 0, choice = 0, theChoice = 0, k = 1, count = 0;
    string theCharacter = "", theEvidence = "", evidences[3];

    // set rand seed
    srand(time(NULL));

    // print the character
    cout << "It is " << characters[index].getName() << "'s turn." << endl;

    // add points to that character 
    characters[index].addPoints(1);

    // randomly select # of points to represent moving rooms 
    points = rand()%6;
    if (points == 4){
        points = 2;
    }
    // add those points to that character 
    characters[index].addPoints(points);

    // randomly pick a character to "ask for evidence "
    ask = (rand()%4) + 1;
    // if selected character 1 (aka the user)
    if (ask == 1){
        // randomly select a character
        characterIndex = rand()%4;
        // randomly select a weapon
        weaponIndex = rand()%8;
        // randomly select a room
        roomIndex = rand()%7;

        // print the character's guess to the user, tell user to show evidence 
        cout << characters[index].getName() << " thinks " << characters[characterIndex].getName() << " did it with (a) ";
        cout << weapons[weaponIndex].getName() << " in (the) " << rooms[roomIndex].getName() << endl;
        cout << "If applicable, show your evidence." << endl;

        // print menu, GET choice
        cout << endl;
        cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
        cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
        cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl;
        cout << "===========================" << endl;
        cout << "Select a numerical value." << endl;
        cin >> choice;

        // while choice is not 4
        while (choice != 4){
            switch(choice){
                // if choice is 1
                case 1:
                    cout << "It is not your turn to move." << endl;
                    
                    break;
                // if choice is 2
                case 2:
                    // GET character to check 
                    cout << "Choose the character you want to check:" << endl;
                    // prints characters
                    for (int g=0; g < 4; g++){
                        cout << k << ". " << characters[g].getName() << endl;
                        k++;
                    }
                    // GET character 
                    cout << endl;
                    cout << "Select a numerical option." << endl;
                    cin >> theChoice;
                    
                    // selects chosen character 
                    if (theChoice == 1){
                        theCharacter = characters[0].getName();
                    }
                    else if (theChoice == 2){
                        theCharacter = characters[1].getName();
                    }
                    else if (theChoice == 3){
                        theCharacter = characters[2].getName();
                    }
                    else if (theChoice == 4){
                        theCharacter = characters[3].getName();
                    }

                    cout << endl;
                    // run getCharacterStats() with the chosen character 
                    Gameplay::getCharacterStats(theCharacter);

                    break;
                // if choice is 3
                case 3:
                    cout << "It is not your turn to guess." << endl;

                    break;
                // if choice is 5
                case 5:
                    // run PrintChecklist()
                    Gameplay::PrintChecklist();

                    break;
                // otherwise
                default:
                    cout << "Invalid input." << endl;
            }
             // print menu, GET choice
            cout << endl;
            cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
            cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
            cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl;
            cout << "===========================" << endl;
            cout << "Select a numerical value." << endl;
            cin >> choice;
        }

        k = 0;

        // go through user's evidence 
        for (int x=0; x < 4; x++){
            theEvidence = characters[idx].getEvidenceAt(x);
            // check if any of user's evidence matches character's description
            if (theEvidence == characters[characterIndex].getName() || theEvidence == weapons[weaponIndex].getName() || theEvidence == rooms[roomIndex].getName()){
                // add to evidences array 
                evidences[k] = theEvidence;
                k++;
                // keep track of # of evidences that match
                count++;
            }
        }

        k = 1;

        // if theres evidence that matches 
        if (count > 0){
            // print the evidence that matches 
            cout << "You have " << count << " piece(s) of evidence that match " << characters[index].getName() << "'s description. Choose one to share: " << endl;
            for (int y=0; y < count; y++){
                cout << k << ". " << evidences[y] << endl;
                k++;
            }
            // GET the evidence the user wants to share 
            cout << "Select a numerical option." << endl;
            cin >> choice;

            // get correct index of evidence in evidence array 
            choice = choice - 1;

            // print the evidence they want to share 
            cout << characters[idx].getName() << " has the evidence: " << evidences[choice] << endl;

            // add one to the character's power 
            characters[index].setPower(1);
        }
        // if theres no evidence that matches 
        else{
            cout << "You have no evidence that matches " << characters[index].getName() << "'s description." << endl;
        } 
    }
}

//
// This function checks if the character's power is 3+ and if the character's points are less than the users. If both of these 
// are true, then the user has a 40% chance of losing this round.
// Parameters: N/A
// Return: lose - a boolean value on whether the user lost or not 
//
bool Gameplay::checkCharacterWin(){
    bool lose = false;
    int chance = 0;

    // set rand seed
    srand(time(NULL));

    // go through each character
    for (int i=0; i < 4; i++){
        // if character's power is greater than or equal to 3 and the character's points are less than the user's
        if (characters[i].getPower() >= 3 && characters[idx].getPoints() > characters[i].getPoints()){
            // randomly select number between 1 and 10 
            chance = (rand()%10) + 1;
            // 40% chance of losing (if chance equals 1-4)
            if (chance >= 1 && chance <= 4){
                // print the character that solved the case 
                cout << "Uh oh! " << characters[i].getName() << " solved the case. You lose!" << endl;
                // print correct answer
                cout << "The correct answer was: " << murderer << " did it with (a) " << theWeapon << " in (the) " << theRoom << "." << endl;
                lose = true;
                break;
            }
        }
    }
    return lose;
}
