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

int main(){
    Character characters[4];
    Weapon weapons[8];
    Room rooms[7];

    Gameplay game(characters, weapons, rooms, "Summer", "dagger", "room");

    return 0;
}