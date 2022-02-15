#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <string>
#include <vector>
#include "Character.h"
#include "Weapon.h"
#include "Room.h"

using namespace std;

class Gameplay{
private:
    Character characters[4];
    Weapon weapons[8];
    Room rooms[7];
    string murderer;
    string theWeapon;
    string theRoom;
    int idx;
    int murdererIdx;
    int theWeaponIdx;
    int theRoomIdx;

public:
    Gameplay();
    Gameplay(Character newCharacters[], Weapon newWeapons[], Room newRooms[], string newMurderer, string newTheWeapon, string newTheRoom);

    string getCharacterAt(int index);
    void setCharacterAt(string newCharacter, int index);

    string getWeaponAt(int index);
    void setWeaponAt(string newWeapon, int index);

    string getRoomAt(int index);
    void setRoomAt(string newRoom, int index);

    int getMurdererIndex();
    string getMurderer();
    void setMurderer(string newMurderer);

    int getTheWeaponIndex();
    string getTheWeapon();
    void setTheWeapon(string newTheWeapon);

    int getTheRoomIndex();
    string getTheRoom();
    void setTheRoom(string newTheRoom);

    int getIndex();
    void setIndex(int index);

    void addThePoints(int newPoints);

    string getCurrentRoom();

    void getCharacterStats(string theCharacter);

    void printUserStats();

    void PrintChecklist();

    void selectFile();

    void selectEvidence();

    void roomSelect();
    void pickRoom(string newRoom);

    int checkConclusion(string theMurderer, string theGuessedWeapon, string theGuessedRoom);

    string checkEvidence(string theCharacter, string theMurderer, string theGuessedWeapon, string theGuessedRoom);

    void characterTurn(int index);

    bool checkCharacterWin();
};
#endif