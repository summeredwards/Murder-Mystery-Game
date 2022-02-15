#include "Weapon.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    Weapon room("Room", false);

    cout << room.getName() << endl;
    return 0;
}