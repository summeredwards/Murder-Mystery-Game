#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

using namespace std;

class Character{
private:
    int points;
    int power;
    bool innocence;
    vector<string> evidence;
    string name;
    string room;

public:
    Character();
    Character(string newName, int newPoints, bool newInnocence, vector<string> newEvidence, int newPower);

    int getPoints();
    void setPoints(int newPoints);
    void addPoints(int newPoints);

    bool getInnocence();
    void setInnocence(bool newInnocence);

    void getEvidence();
    int getEvidenceSize();
    string getEvidenceAt(int index);
    void setEvidence(vector<string> newEvidence);
    void setEvidenceElement(string newEvidence);
    void eraseEvidence(int index);

    string getName();
    void setName(string newName);

    string getRoom();
    void setRoom(string newRoom);

    int getPower();
    void setPower(int newPower);
};
#endif