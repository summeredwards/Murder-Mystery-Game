#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>

using namespace std;

class Room{
private:
    string name;
    bool innocence;

public:
    Room();
    Room(string newName, bool newInnocence);

    string getName();
    void setName(string newName);

    bool getInnocence();
    void setInnocence(bool newInnocence);
};
#endif