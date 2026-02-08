/*****************************************
** File:    lab1.cpp
** Project: CMSC 202 Lab 1, Spring 2026
** Author:  Elliot Hurchalla
** Date:    02/07/26
** Section: 14
** E-mail:  ehurcha1@umbc.edu
**
** This program simulates the beginning of a Pokemon game.
** It asks the user for their name and age. Then, it presents
** them with the decision of picking a first Pokemon.
*****************************************/


#include <iostream>
using namespace std;

int main() {
    string name; // User's name
    int age=0; // User's age
    int teamSelect=0; // Signifies the Pokemon the user picks
    int teamNum=3; // How many Pokemon are left to choose from
    bool team1=true; // Whether or not Bulbasaur is still available
    bool team2=true; // Whether or not Squirtle is still available
    bool team3=true; // Whether or not Charmander is still available

    cout << "What is your name?" << endl;
    getline(cin, name);
    
    cout << "What is your age?" << endl;
    cin >> age;

    if (age >= 10 && age <= 122){ // Makes sure the age is valid
        cout << "Welcome, Pokemon trainer " << name << "!" << endl;
        cout << "To start your adventure, you must choose the first" << endl
                << "member of your team. Take a minute to review your" << endl
                << "options!" << endl;
        cout << "What would you like to do?" << endl 
            << "1. Learn about Bulbasaur" << endl
            << "2. Learn about Squirtle" << endl
            << "3. Learn about Charmander" << endl;
        cin >> teamSelect; 
    }else{
        return 0; // The program ends immediately if the age is invalid
    }
    
    while (teamNum != 0){ // Loops until the user has picked all the Pokemon
        if (teamSelect == 1 && team1 == true){
            team1 = false; // Bulbasaur is no longer available
            teamNum -= 1; // Decreases the number of Pokemon left to choose from
            cout << "It carries a seed on its back right from birth. By" << endl
                << "soaking up the sun's rays, the seed grows" << endl
                << "progressively larger. It is filled with nutrients." << endl
                << "Able to go for days without eating a single morsel, it" << endl
                << "uses this to grow while it is young.\n" << endl;
        }else if (teamSelect == 2 && team2 == true){
            team2 = false; // Squirtle is no longer available
            teamNum -= 1; // Decreases the number of Pokemon left to choose from
            cout << "Its shell is soft immediately after it is born. In no" << endl
                << "time at all, the shell becomes so resilient that a" << endl
                << "prodding finger will bounce right off it. It hides in" << endl
                << "its shell to protect itself, then strikes back with" << endl
                << "spouts of water at every opportunity.\n" << endl;
        }else if (teamSelect == 3 && team3 == true){
            team3 = false; // Charmander is no longer available
            teamNum -= 1; // Decreases the number of Pokemon left to choose from
            cout << "From the time it is born, a flame burns at the tip of" << endl
                << "its tail. It shows the strength of its life-force. If" << endl
                << "Charmander is weak, the flame also burns weakly. If" << endl
                << "Charmander is healthy, the flame will burn vigorously" << endl
                << "and won't go out even if it gets a bit wet.\n" << endl;
        }
        if (teamNum >= 1){ // If there are still Pokemon left to choose from, the user is prompted to pick again
            cout << "What would you like to do?" << endl
                << "1. Learn about Bulbasaur" << endl
                << "2. Learn about Squirtle" << endl
                << "3. Learn about Charmander" << endl;
            cin >> teamSelect;
        }
        if (teamNum == 0){ // If there are no Pokemon left to choose from, the user is informed
            /* This if statement isn't the cleanest but I was getting infinite loops when I had it as 
            an else statement to the previous if statement. */
            cout << "Oh no! It seems that Professor Oak has run out of" << endl
                << "starter Pokemon. Better luck next time!" << endl;
        }
    }

    return 0;
}