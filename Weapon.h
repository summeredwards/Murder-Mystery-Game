#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <vector>

using namespace std;

class Weapon{
private:
    string name;
    bool innocence;

public:
    Weapon();
    Weapon(string newName, bool newInnoncence);

    string getName();
    void setName(string newName);

    bool getInnocence();
    void setInnocence(bool newInnocence);
};
#endif