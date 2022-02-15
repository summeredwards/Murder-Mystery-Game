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
    int choice = 0, option = 0, k = 0, index = 0, playerTurn = 1, chosen = 0, characterIndex = 0, Choice = 0;
    bool lose = false;
    ifstream charactersTxt, weaponsTxt, roomsTxt, createdCharacters;
    ofstream createCharacter;
    string line, theCreatedCharacter, theChosenCharacter;

    // create Gameplay object
    Gameplay MurderMystery;

    //print intro
    cout << " " << endl << "================== MURDER MYSTERY ==================" << endl << " " << endl;
    cout << "It is a gloomy night in the height of the roaring 20's. The Greenwald Estate sits unusually quiet this night." << endl;
    cout << "This mulitmillion dollar mansion belongs to the infamous business man, Walter Greenwald, who has accumulated" << endl;
    cout << "more than his fair share of wealth. He has cheated, stolen, lied, and blackmailed; which created quite a list" << endl;
    cout << "of enemies. A couple hours ago, Mr. Greenwald was found dead in the back lawn. Someone had clearly killed and disposed" << endl;
    cout << "his body outside. However, there were only 4 other people at the Greenwald Estate this night. Now, they" << endl;
    cout << "are all trying to solve the murder. They need to figure out who committed the crime, where they did it, and" << endl;
    cout << "what they did it with. You will play a role of one of these characters, and try to solve the mystery before" << endl;
    cout << "anyone else." << endl << " " << endl << "Each character is introduced below. Please read their descriptions and choose" << endl;
    cout << "who you would like to be. If you wish, you can also create your own character." << endl << " " << endl;
    cout << "==== DAISY BAKER ====" << endl;
    cout << "Daisy Baker is one of the maids that lives at the Greenwald Estate. She spent most of her time cooking and" << endl;
    cout << "cleaning. Mr. Greenwald was known for his drunkenness, and was quite aggressive under the influence." << endl;
    cout << "He has yelled at and beaten Daisy on multiple occasions. His tantrums would leave the mansion a disaster, all for" << endl;
    cout << "Daisy to clean up. Whenever Daisy tried to quit her job, Mr. Greenwald would threaten to blacklist her." << endl << " " << endl;
    cout << "==== Nicolas White ====" << endl;
    cout << "Nicolas White is Mr. Greenwald's nefew who is visiting from out of town. He is a kind and wealthy man, but his" << endl; 
    cout << "his relationship with his uncle has always been rocky. Nick has loaned Mr. Greenwald substantial amounts of money. However," << endl;
    cout << "Mr. Greenwald refused to pay him back because Nick was wealthier than him. No matter how hard Nick tried, he could" << endl;
    cout << "not get his uncle to budge." << endl << " " << endl;
    cout << "==== Tom Porter ====" << endl;
    cout << "Tom Porter is one of Mr. Greenwald's colleagues. He came over to drop off a coat Mr. Greenwald had left at work. While Mr. Greenwald" << endl;
    cout << "considers Tom a friend, he has cheated his out of many business deals, leaving Tom in the dust. Mr. Greenwald's actions have" << endl;
    cout << "greatly affected Tom financially." << endl << " " << endl;
    cout << "==== Scarlet Jones ====" << endl;
    cout << "Scarlet Jones is Mr. Greenwald's fiancée. While she is very beautiful, Scarlet was only in it for the money. After she" << endl;
    cout << "realized how vial Mr. Greenwald was, she tried to leave him. However, Mr. Greenwald had lots of dirt on Scarlet," << endl;
    cout << "and blackmailed her to stay in the relationship." << endl << " " << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////// CHOOSING CHARACTERS
    // GET choose character
    cout << "Would you like to..." << endl;
    cout << "1. Pick a character" << endl;
    cout << "2. Create your own" << endl;
    cout << "Select a numerical option." << endl;
    cin >> choice;

    // if choice is 1
    if (choice == 1){
        // open character file
        charactersTxt.open("characters.txt");

        // if opening failed
        if (charactersTxt.fail()){
            cout << "Error opening file." << endl;
        }
        else{
            // read from file
            while (getline(charactersTxt, line)){
                // if line is not empty
                if (line != ""){
                    //cout << line << endl;
                    // add character to array of character obejcts 
                    MurderMystery.setCharacterAt(line, k);
                    k++;
                }
            }
            // close file
            charactersTxt.close();
        }
        k = 1;
        line = "";

        // GET character
        cout <<  " " << endl << "Below is the list of characters. Select a numerical option: " << endl;
        
        for (int i=0; i < 4; i++){
            cout << k << ". " << MurderMystery.getCharacterAt(i) << endl;
            k++;
        }
        cin >> index;

        // save index of character in character object array 
        index = index - 1;

        // save the index of character in the Gameplay class
        MurderMystery.setIndex(index);

        // print selected character 
        cout << " " << endl << "You have selected " << MurderMystery.getCharacterAt(index) << " as your character." << endl;
    }
    // if choice is 2
    else if (choice == 2){
        k = 0;

        // GET character name 
        cout << "Enter the first and last name of your character: " << endl;
        cin.ignore();

        getline(cin, theCreatedCharacter);
        //cout << theCreatedCharacter << endl;

        // open file for writing
        createCharacter.open("createCharacters.txt");

        // if opening failed
        if (createCharacter.fail()){
            cout << "Error opening file." << endl;
        }
        else{
            // write character names to file 
            createCharacter << "Daisy Baker" << endl;
            createCharacter << "Nicolas White" << endl;
            createCharacter << "Scarlet Jones" << endl;
            createCharacter << theCreatedCharacter << endl;
            createCharacter.close();
        }

        // open the file for reading 
        createdCharacters.open("createCharacters.txt");

        // if opening failed 
        if (createdCharacters.fail()){
            cout << "Error opening file." << endl;
        }
        else{
            // read lines from file 
            while (getline(createdCharacters, line)){
                // if line is not empty
                if (line != ""){
                    //cout << line << endl;
                    // add character to array of character objects 
                    MurderMystery.setCharacterAt(line, k);
                    k++;
                }
            }
            // close file 
            createdCharacters.close();
        }
        // save index of character in character object array 
        index = 3;

        // save index of character in Gameplay class 
        MurderMystery.setIndex(index);

        // print selected character 
        cout << " " << endl << "You have selected " << MurderMystery.getCharacterAt(index) << " as your character." << endl;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////// SETTING WEAPON AND ROOM ARRAYS

    line = "";
    k = 0;

    //open weapon file
    weaponsTxt.open("weapons.txt");

    // if opening failed
    if (weaponsTxt.fail()){
        cout << "Error opening file." << endl;
    }
    else{
        // read from file
        while (getline(weaponsTxt, line)){
            // if line is not empty 
            if (line != ""){
                // set weapon to weapon object array 
                MurderMystery.setWeaponAt(line, k);
                k++;
            }
        }
        // close file 
        weaponsTxt.close();
    }

    line = "";
    k = 0;

    // open room file
    roomsTxt.open("rooms.txt");

    // if opening failed 
    if (roomsTxt.fail()){
        cout << "Error opening file." << endl;
    }
    else{
        // read from file 
        while (getline(roomsTxt, line)){
            // if line is not empty 
            if (line != ""){
                // set room to room object array 
                MurderMystery.setRoomAt(line, k);
                k++;
            }
        }
        // close file 
        roomsTxt.close();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////// SELECTING THE FILE AND EVIDENCE 

    // randomly select who did it, with what, and where
    MurderMystery.selectFile();

    // set evidence vectors for each character
    MurderMystery.selectEvidence();

    ////////////////////////////////////////////////////////////////////////////////////////////// START GAME 

    // print rules 
    cout << endl <<  "=========== RULES ===========" << endl << "(1) POINTS" << endl << "The goal of this game is to earn the least amount of points possible." << endl;
    cout << "Every turn, a character will earn 1 point. When a character wants to move rooms," << endl;
    cout << "they have a choice between rolling the dice and picking their own room. When a character " << endl;
    cout << "decides to roll the dice, 3 rooms will be randomly selected, each with a random number" << endl;
    cout << "of points between 1-3. If a character wants to pick their own room, they can choose whichever" << endl;
    cout << "room they want, with the cost of 5 points. A character can also stay in the same room for" << endl;
    cout << "as many rounds as they want, however that will cost 3 points." << endl << "(2) MAKING A HYPOTHESIS" << endl;
    cout << "When a character is ready to make a hypothesis, they get to choose which other character they want to ask." << endl;
    cout << "If the character they asked has evidence that matches their description, they will be shown that piece of" << endl;
    cout << "evidence. This means that element is innocent." << endl << "(3) MAKING A CONCLUSION" << endl;
    cout << "When you are ready to give your final answer, select the 'Make a Conlusion' option and enter your guesses." << endl;
    cout << "You only get to make a conclusion twice. When you guess wrong the first time, 15 points will be added to your score." << endl;
    cout << "If you guess wrong again, you lose the game." << endl << "(4) BEAT THE COMPUTER" << endl;
    cout << "When another character has LESS points than you, then they have a greater chance of beating you." << endl;
    cout << "You can check another character's score by selecting 'Get Player Stats'. Good luck!" << endl;
    cout << "==============================" << endl;

    // print it is their turn
    cout << " " << endl << "It is your turn, please enter the numerical value: " << endl;
    cout << "1. Next" << endl;
    cin >> choice;

    // while choice is not quit
    while(choice != 6){
        // if it is the player's turn
        if (playerTurn == 1){
            // print the user's stats 
            MurderMystery.printUserStats();

            // print menu and GET choice 
            cout << endl;
            cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
            cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
            cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl;
            cout << "6. Quit" << endl << "===========================" << endl;
            cout << "Select a numerical value." << endl;
            cin >> choice;

            // while choice is not 6 and not 7
            while (choice != 6 && choice != 7){
                switch(choice){
                    // if choice is 1
                    case 1:
                        // GET option
                        cout << "Would you like to..." << endl << "1. Roll the Dice" << endl;
                        cout << "2. Pick Your Own Room" << endl << "Select a numerical option" << endl;
                        cin >> option;

                        // if option equals 1
                        if (option == 1){
                            k = 1;

                            // select 3 rooms at random 
                            MurderMystery.roomSelect();
                        }
                        // if option equals 2
                        else if (option == 2){
                            string theWantedRoom = "";
                            int theChoice = 0;

                            k = 1;

                            // GET room
                            cout << endl;
                            cout << "Where would you like to go?" << endl;
                            for (int g=0; g < 7; g++){
                                // prints each room
                                cout << k << ". " << MurderMystery.getRoomAt(g) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // if user chose room 1
                            if (theChoice == 1){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(0);
                            }
                            // if user chose room 2
                            else if (theChoice == 2){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(1);
                            }
                            // if user chose room 3
                            else if (theChoice == 3){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(2);
                            }
                            // if user chose room 4
                            else if (theChoice == 4){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(3);
                            }
                            // if user chose room 5
                            else if (theChoice == 5){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(4);
                            }
                            // if user chose room 6
                            else if (theChoice == 6){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(5);
                            }
                            // if user chose room 7
                            else if (theChoice == 7){
                                // select room
                                theWantedRoom = MurderMystery.getRoomAt(6);
                            }

                            // update user location
                            MurderMystery.pickRoom(theWantedRoom);  
                        }

                        // print menu, GET chosen
                        cout << endl;
                        cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
                        cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
                        cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl <<  "6. Quit" << endl;
                        cout << "===========================" << endl;
                        cout << "Select a numerical value." << endl;
                        cin >> chosen;

                        // while chosen is not 3 and not 6
                        while (chosen != 3 && chosen != 6){
                            // if chosen is 1
                            if (chosen == 1){
                                cout << "You have already moved to a room." << endl;
                            }
                            // if chosen is 2
                            else if (chosen == 2){
                                string theCharacter = "";
                                int theChoice = 0;

                                k = 1;

                                // GET character
                                cout << "Choose the character you want to check:" << endl;
                                for (int g=0; g < 4; g++){
                                    // prints each character
                                    cout << k << ". " << MurderMystery.getCharacterAt(g) << endl;
                                    k++;
                                }
                                cout << endl;
                                cout << "Select a numerical option." << endl;
                                cin >> theChoice;
                                
                                // if user chose character 1
                                if (theChoice == 1){
                                    // select character
                                    theCharacter = MurderMystery.getCharacterAt(0);
                                }
                                // if user chose character 2
                                else if (theChoice == 2){
                                    // select character
                                    theCharacter = MurderMystery.getCharacterAt(1);
                                }
                                // if user chose character 3
                                else if (theChoice == 3){
                                    // select character
                                    theCharacter = MurderMystery.getCharacterAt(2);
                                }
                                // if user chose character 4
                                else if (theChoice == 4){
                                    // select character
                                    theCharacter = MurderMystery.getCharacterAt(3);
                                }

                                // print selected character's stats
                                cout << endl;
                                MurderMystery.getCharacterStats(theCharacter);
                            }
                            // if chosen equals 4
                            else if (chosen == 4){
                                cout << "A character has not asked you for evidence." << endl;
                            }
                            // if chosen equals 5
                            else if (chosen == 5){
                                // print the user's notes 
                                MurderMystery.PrintChecklist();
                            }
                            // otherwise 
                            else{
                                cout << "Invalid input." << endl;
                            }
                            // print menu again and GET chosen
                            cout << endl;
                            cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
                            cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
                            cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl << "6. Quit" << endl;
                            cout << "===========================" << endl;
                            cout << "Select a numerical value." << endl;
                            cin >> chosen;
                        }

                        // if chosen is 6
                        if (chosen == 6){
                            // print correct answer
                            cout << "The correct answer was: " << MurderMystery.getMurderer() << " did it with (a) " << MurderMystery.getTheWeapon() << " in (the) " << MurderMystery.getTheRoom() << "." << endl;
                            cout << endl;
                            cout << "Goodbye!" << endl;
                            // end game
                            return 0;
                        }

                        // GET chosen 
                        cout << endl;
                        cout << "Would you like to..." << endl;
                        cout << "1. Make a Hypothesis" << endl << "2. Make a Conclusion" << endl;
                        cout << "Select a numerical option." << endl;
                        cin >> chosen;

                        k = 1;

                        // if chosen is 1 (Make a Hypothesis)
                        if (chosen == 1) {
                            string theCharacter = "", theGuessedMurderer = "", theGuessedWeapon = "", theGuessedRoom = "";
                            int theChoice = 0;

                            // GET character
                            cout << "Choose a character to ask:" << endl;
                            for (int g=0; g < 4; g++){
                                // prints each character
                                cout << k << ". " << MurderMystery.getCharacterAt(g) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;
                            
                            // if user selected character 1
                            if (theChoice == 1){
                                // select character
                                theCharacter = MurderMystery.getCharacterAt(0);
                            }
                            // if user selected character 2
                            else if (theChoice == 2){
                                // select character
                                theCharacter = MurderMystery.getCharacterAt(1);
                            }
                            // if user selected character 3
                            else if (theChoice == 3){
                                // select character
                                theCharacter = MurderMystery.getCharacterAt(2);
                            }
                            // if user selected character 4
                            else if (theChoice == 4){
                                // select character
                                theCharacter = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed murderer
                            cout << endl;
                            cout << "Who do you think commited the crime?" << endl;
                            for (int p=0; p < 4; p++){
                                // prints each character
                                cout << k << ". " << MurderMystery.getCharacterAt(p) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // if user selected character 1
                            if (theChoice == 1){
                                // select character
                                theGuessedMurderer = MurderMystery.getCharacterAt(0);
                            }
                             // if user selected character 2
                            else if (theChoice == 2){
                                 // select character
                                theGuessedMurderer = MurderMystery.getCharacterAt(1);
                            }
                             // if user selected character 3
                            else if (theChoice == 3){
                                 // select character
                                theGuessedMurderer = MurderMystery.getCharacterAt(2);
                            }
                             // if user selected character 4
                            else if (theChoice == 4){
                                 // select character
                                theGuessedMurderer = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed weapon
                            cout << endl;
                            cout << "Which weapon was used?" << endl;
                            for (int t=0; t < 8; t++){
                                // prints each weapon
                                cout << k << ". " << MurderMystery.getWeaponAt(t) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // if user selects weapon 1
                            if (theChoice == 1){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(0);
                            }
                            // if user selects weapon 2
                            else if (theChoice == 2){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(1);
                            }
                            // if user selects weapon 3
                            else if (theChoice == 3){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(2);
                            }
                            // if user selects weapon 4
                            else if (theChoice == 4){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(3);
                            }
                            // if user selects weapon 5
                            else if (theChoice == 5){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(4);
                            }
                            // if user selects weapon 6
                            else if (theChoice == 6){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(5);
                            }
                            // if user selects weapon 7
                            else if (theChoice == 7){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(6);
                            }
                            // if user selects weapon 8
                            else if (theChoice == 8){
                                // select weapon
                                theGuessedWeapon = MurderMystery.getWeaponAt(7);
                            }

                            // select room the character is in
                            theGuessedRoom = MurderMystery.getCurrentRoom();

                            // print guess
                            cout << endl;
                            cout << "I think " << theGuessedMurderer << " did it with a " << theGuessedWeapon << " in " << theGuessedRoom << endl;

                            string match = "";

                            // see if evidence matches
                            match = MurderMystery.checkEvidence(theCharacter, theGuessedMurderer, theGuessedWeapon, theGuessedRoom);

                            // if no match
                            if (match == ""){
                                cout << theCharacter << " has no evidence to prove these are innocent." << endl;
                            }
                            // otherwise
                            else{
                                cout << theCharacter << " has the following evidence: " << match << endl;
                            }
                        }
                        // if chosen is 2 (Make a Conclusion)
                        else if (chosen == 2){
                            string theGuessedMurderer = "", theGuessedWeapon = "", theGuessedRoom = "";
                            int theChoice = 0;

                            k = 1;

                            // GET guessed murderer
                            cout << endl;
                            cout << "Who do you think commited the crime?" << endl;
                            for (int p=0; p < 4; p++){
                                // prints characters
                                cout << k << ". " << MurderMystery.getCharacterAt(p) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen character
                            if (theChoice == 1){
                                theGuessedMurderer = MurderMystery.getCharacterAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedMurderer = MurderMystery.getCharacterAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedMurderer = MurderMystery.getCharacterAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedMurderer = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed weapon
                            cout << endl;
                            cout << "Which weapon was used?" << endl;
                            for (int t=0; t < 8; t++){
                                // prints weapons
                                cout << k << ". " << MurderMystery.getWeaponAt(t) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen weapon
                            if (theChoice == 1){
                                theGuessedWeapon = MurderMystery.getWeaponAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedWeapon = MurderMystery.getWeaponAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedWeapon = MurderMystery.getWeaponAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedWeapon = MurderMystery.getWeaponAt(3);
                            }
                            else if (theChoice == 5){
                                theGuessedWeapon = MurderMystery.getWeaponAt(4);
                            }
                            else if (theChoice == 6){
                                theGuessedWeapon = MurderMystery.getWeaponAt(5);
                            }
                            else if (theChoice == 7){
                                theGuessedWeapon = MurderMystery.getWeaponAt(6);
                            }
                            else if (theChoice == 8){
                                theGuessedWeapon = MurderMystery.getWeaponAt(7);
                            }

                            k = 1;

                            // GET guessed room
                            cout << endl;
                            cout << "Where did it take place?" << endl;
                            for (int g=0; g < 7; g++){
                                // prints rooms 
                                cout << k << ". " << MurderMystery.getRoomAt(g) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen room
                            if (theChoice == 1){
                                theGuessedRoom = MurderMystery.getRoomAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedRoom = MurderMystery.getRoomAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedRoom = MurderMystery.getRoomAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedRoom = MurderMystery.getRoomAt(3);
                            }
                            else if (theChoice == 5){
                                theGuessedRoom = MurderMystery.getRoomAt(4);
                            }
                            else if (theChoice == 6){
                                theGuessedRoom = MurderMystery.getRoomAt(5);
                            }
                            else if (theChoice == 7){
                                theGuessedRoom = MurderMystery.getRoomAt(6);
                            }

                            int correct = 0;

                            // checks if guess is correct
                            correct = MurderMystery.checkConclusion(theGuessedMurderer, theGuessedWeapon, theGuessedRoom);

                            // if return value is -1, end program 
                            if (correct == -1){
                                cout << "The correct answer was: " << MurderMystery.getMurderer() << " did it with (a) " << MurderMystery.getTheWeapon() << " in (the) " << MurderMystery.getTheRoom() << "." << endl;
                                return 0;
                            } 
                        }
                        // after you guess, your turn ends
                        choice = 7;

                        break; ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // if choice is 2
                    case 2:
                        k = 1;

                        // GET character
                        cout << "Choose the character you want to check: " << endl;

                        for (int g=0; g < 4; g++){
                            // prints characters
                            cout << k << ". " << MurderMystery.getCharacterAt(g) << endl;

                            k ++;
                        }
                        cout << endl;
                        cout << "Select a numerical option." << endl;
                        cin >> chosen;

                        // selects chosen character
                        if (chosen == 1){
                            theChosenCharacter = MurderMystery.getCharacterAt(0);
                        }
                        else if (chosen == 2){
                            theChosenCharacter = MurderMystery.getCharacterAt(1);
                        }
                        else if (chosen == 3){
                            theChosenCharacter = MurderMystery.getCharacterAt(2);
                        }
                        else if (chosen == 4){
                            theChosenCharacter = MurderMystery.getCharacterAt(3);
                        }

                        // prints that character's stats 
                        cout << endl;
                        MurderMystery.getCharacterStats(theChosenCharacter);

                        break;
                    // if choice is 3
                    case 3:
                        // print options
                        cout << endl;
                        cout << "Would you like to..." << endl;
                        cout << "1. Make a Hypothesis" << endl << "2. Make a Conclusion" << endl;
                        cout << "Select a numerical option." << endl;
                        cin >> chosen;

                        k = 1;

                        // if chosen is 1 (Make a Hypothesis)
                        if (chosen == 1) {
                            string theCharacter = "", theGuessedMurderer = "", theGuessedWeapon = "", theGuessedRoom = "";
                            int theChoice = 0;

                            // GET character to ask 
                            cout << "Choose a character to ask:" << endl;
                            for (int g=0; g < 4; g++){
                                // prints characters
                                cout << k << ". " << MurderMystery.getCharacterAt(g) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;
                            
                            // selects chosen character
                            if (theChoice == 1){
                                theCharacter = MurderMystery.getCharacterAt(0);
                            }
                            else if (theChoice == 2){
                                theCharacter = MurderMystery.getCharacterAt(1);
                            }
                            else if (theChoice == 3){
                                theCharacter = MurderMystery.getCharacterAt(2);
                            }
                            else if (theChoice == 4){
                                theCharacter = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed murderer
                            cout << endl;
                            cout << "Who do you think commited the crime?" << endl;
                            for (int p=0; p < 4; p++){
                                // prints characters
                                cout << k << ". " << MurderMystery.getCharacterAt(p) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen character 
                            if (theChoice == 1){
                                theGuessedMurderer = MurderMystery.getCharacterAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedMurderer = MurderMystery.getCharacterAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedMurderer = MurderMystery.getCharacterAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedMurderer = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed weapon
                            cout << endl;
                            cout << "Which weapon was used?" << endl;
                            for (int t=0; t < 8; t++){
                                // prints weapons 
                                cout << k << ". " << MurderMystery.getWeaponAt(t) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen weapon
                            if (theChoice == 1){
                                theGuessedWeapon = MurderMystery.getWeaponAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedWeapon = MurderMystery.getWeaponAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedWeapon = MurderMystery.getWeaponAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedWeapon = MurderMystery.getWeaponAt(3);
                            }
                            else if (theChoice == 5){
                                theGuessedWeapon = MurderMystery.getWeaponAt(4);
                            }
                            else if (theChoice == 6){
                                theGuessedWeapon = MurderMystery.getWeaponAt(5);
                            }
                            else if (theChoice == 7){
                                theGuessedWeapon = MurderMystery.getWeaponAt(6);
                            }
                            else if (theChoice == 8){
                                theGuessedWeapon = MurderMystery.getWeaponAt(7);
                            }

                            // selects room the user is in
                            theGuessedRoom = MurderMystery.getCurrentRoom();

                            // print guess
                            cout << endl;
                            cout << "I think " << theGuessedMurderer << " did it with (a) " << theGuessedWeapon << " in (the) " << theGuessedRoom << endl;

                            string match = "";

                            // check if there is a match
                            match = MurderMystery.checkEvidence(theCharacter, theGuessedMurderer, theGuessedWeapon, theGuessedRoom);

                            // if there's no match
                            if (match == ""){
                                cout << theCharacter << " has no evidence to prove these are innocent." << endl;
                            }
                            // otherwise
                            else{
                                cout << theCharacter << " has the following evidence: " << match << endl;
                            }
                            // add 3 points to user's points because they didn't move rooms
                            MurderMystery.addThePoints(3);
                        }
                        // if chosen is 2 (Make a Conclusion)
                        else if (chosen == 2){
                            string theGuessedMurderer = "", theGuessedWeapon = "", theGuessedRoom = "";
                            int theChoice = 0;

                            k = 1;

                            // GET guessed murderer
                            cout << endl;
                            cout << "Who do you think commited the crime?" << endl;
                            for (int p=0; p < 4; p++){
                                // prints characters
                                cout << k << ". " << MurderMystery.getCharacterAt(p) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen character
                            if (theChoice == 1){
                                theGuessedMurderer = MurderMystery.getCharacterAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedMurderer = MurderMystery.getCharacterAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedMurderer = MurderMystery.getCharacterAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedMurderer = MurderMystery.getCharacterAt(3);
                            }

                            k = 1;

                            // GET guessed weapon
                            cout << endl;
                            cout << "Which weapon was used?" << endl;
                            for (int t=0; t < 8; t++){
                                // prints weapons
                                cout << k << ". " << MurderMystery.getWeaponAt(t) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen weapon
                            if (theChoice == 1){
                                theGuessedWeapon = MurderMystery.getWeaponAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedWeapon = MurderMystery.getWeaponAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedWeapon = MurderMystery.getWeaponAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedWeapon = MurderMystery.getWeaponAt(3);
                            }
                            else if (theChoice == 5){
                                theGuessedWeapon = MurderMystery.getWeaponAt(4);
                            }
                            else if (theChoice == 6){
                                theGuessedWeapon = MurderMystery.getWeaponAt(5);
                            }
                            else if (theChoice == 7){
                                theGuessedWeapon = MurderMystery.getWeaponAt(6);
                            }
                            else if (theChoice == 8){
                                theGuessedWeapon = MurderMystery.getWeaponAt(7);
                            }

                            k = 1;

                            // GET guessed room
                            cout << endl;
                            cout << "Where did it take place?" << endl;
                            for (int g=0; g < 7; g++){
                                // prints room
                                cout << k << ". " << MurderMystery.getRoomAt(g) << endl;
                                k++;
                            }
                            cout << endl;
                            cout << "Select a numerical option." << endl;
                            cin >> theChoice;

                            // selects chosen room
                            if (theChoice == 1){
                                theGuessedRoom = MurderMystery.getRoomAt(0);
                            }
                            else if (theChoice == 2){
                                theGuessedRoom = MurderMystery.getRoomAt(1);
                            }
                            else if (theChoice == 3){
                                theGuessedRoom = MurderMystery.getRoomAt(2);
                            }
                            else if (theChoice == 4){
                                theGuessedRoom = MurderMystery.getRoomAt(3);
                            }
                            else if (theChoice == 5){
                                theGuessedRoom = MurderMystery.getRoomAt(4);
                            }
                            else if (theChoice == 6){
                                theGuessedRoom = MurderMystery.getRoomAt(5);
                            }
                            else if (theChoice == 7){
                                theGuessedRoom = MurderMystery.getRoomAt(6);
                            }

                            int correct = 0;

                            // check if the conclusion is correct 
                            correct = MurderMystery.checkConclusion(theGuessedMurderer, theGuessedWeapon, theGuessedRoom);

                            // if return value is -1, end program 
                            if (correct == -1){
                                cout << "The correct answer was: " << MurderMystery.getMurderer() << " did it with (a) " << MurderMystery.getTheWeapon() << " in (the) " << MurderMystery.getTheRoom() << "." << endl;
                                return 0;
                            } 
                        }

                        // your turn is over
                        choice = 7;
                        break;
                    // if choice is 4
                    case 4:
                        cout << "A character has not asked you for evidence." << endl;

                        break;
                    // if choice is 5
                    case 5:
                        // print user's notes
                        MurderMystery.PrintChecklist();

                        break;
                    // otherwise
                    default:
                        cout << "Invalid input." << endl;
                } // this bracket is for the switch statement

                // print menu and GET choice if choice is not 7 
                if (choice != 7){
                    cout << endl;
                    cout << "========== MENU ===========" << endl << "1. Move Rooms" << endl;
                    cout << "2. Get Player Stats" << endl << "3. Make a Guess" << endl;
                    cout << "4. Show Evidence" << endl << "5. Show Checklist" << endl;
                    cout << "6. Quit" << endl << "===========================" << endl;
                    cout << "Select a numerical value." << endl;
                    cin >> choice;
                }
                else{
                    choice = 7;
                }
            }
            // if choice equals 6
            if (choice == 6){
                // print correct answer
                cout << "The correct answer was: " << MurderMystery.getMurderer() << " did it with (a) " << MurderMystery.getTheWeapon() << " in (the) " << MurderMystery.getTheRoom() << "." << endl;
                cout << endl;
                cout << "Goodbye!" << endl;
                // end program
                return 0;
            }
            // add 1 point after every turn
            MurderMystery.addThePoints(1);

            // add one to playerTurn
            playerTurn++;
        } // this bracket is for the playerTurn variable, right now playerTurn == 1

        // if playerTurn equals 2
        else if (playerTurn == 2){
            // get the index of the next character
            characterIndex = MurderMystery.getIndex() + 1;
            if (characterIndex == 4){
                characterIndex = 0;
            }
            // run characterTurn() for the next character
            MurderMystery.characterTurn(characterIndex);

            // add one to playerTurn
            playerTurn++;
        }
        // if playerTurn equals 3
        else if (playerTurn == 3){
            // get the index of the next character
            characterIndex++;
            if (characterIndex == 4){
                characterIndex = 0;
            }
            // run characterTurn() for the next character
            MurderMystery.characterTurn(characterIndex);

            // add one to playerTurn
            playerTurn++;
        }
        // if playerTurn equals 4
        else if (playerTurn == 4){
            // get the index of the next character 
            characterIndex++;
            if (characterIndex == 4){
                characterIndex = 0;
            }
            // run characterTurn() for the next character 
            MurderMystery.characterTurn(characterIndex);

            // add one to playerTurn
            playerTurn++;
        }

        // check to see if user lost to the computer 
        lose = MurderMystery.checkCharacterWin();
        // if they lost 
        if (lose == true){
            // end program 
            return 0;
        }

        // if playerTurn equals 5, then it equals 1
        if (playerTurn == 5){
            playerTurn = 1;
        }

        // if it is not the user's turn 
        if (playerTurn != 1){
            cout << "It is not your turn, enter the numerical value: " << endl << "1. Next" << endl;
            cin >> choice;
        }
        // if it is the user's turn
        else{
            cout << "It is your turn, enter the numerical value: " << endl << "1. Next" << endl;
            cin >> choice;
        }

    } // while loop brakcet 

    // print correct answer and end program is choice equals 6
    cout << "The correct answer was: " << MurderMystery.getMurderer() << " did it with (a) " << MurderMystery.getTheWeapon() << " in (the) " << MurderMystery.getTheRoom() << "." << endl;
    cout << endl;
    cout << "Goodbye!" << endl;
                        
    return 0;
}