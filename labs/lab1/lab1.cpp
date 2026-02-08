/*****************************************
** File:    lab1.cpp
** Project: CMSC 202 Lab 1, Spring 2026
** Author:  Elliot Hurchalla
** Date:    02/07/26
** Section: 
** E-mail:  ehurcha1@umbc.edu
**
** This program simulates the beginning of a Pokemon game.
** It asks the user for their name and age. Then, it presents
** them with the decision of picking a first Pokemon.
*****************************************/


#include <iostream>
using namespace std;

int main() {
    string name;
    int age=0;
    int teamSelect=0;
    int teamNum=3;

    cout << "What is your name?" << endl;
    getline(cin, name);
    
    cout << "What is your age?" << endl;
    cin >> age;

    if (age >= 10 && age <= 122){
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
        return 0;
    }
    bool team1=true;
    bool team2=true;
    bool team3=true;
    
    while (teamNum != 0){
        if (teamSelect == 1 && team1 == true){
            team1 = false;
            teamNum -= 1;
            cout << "It carries a seed on its back right from birth. By" << endl
                << "soaking up the sun's rays, the seed grows" << endl
                << "progressively larger. It is filled with nutrients." << endl
                << "Able to go for days without eating a single morsel, it" << endl
                << "uses this to grow while it is young.\n" << endl;
        }else if (teamSelect == 2 && team2 == true){
            team2 = false;
            teamNum -= 1;
            cout << "Its shell is soft immediately after it is born. In no" << endl
                << "time at all, the shell becomes so resilient that a" << endl
                << "prodding finger will bounce right off it. It hides in" << endl
                << "its shell to protect itself, then strikes back with" << endl
                << "spouts of water at every opportunity.\n" << endl;
        }else if (teamSelect == 3 && team3 == true){
            team3 = false;
            teamNum -= 1;
            cout << "From the time it is born, a flame burns at the tip of" << endl
                << "its tail. It shows the strength of its life-force. If" << endl
                << "Charmander is weak, the flame also burns weakly. If" << endl
                << "Charmander is healthy, the flame will burn vigorously" << endl
                << "and won't go out even if it gets a bit wet.\n" << endl;
        }
        if (teamNum >= 1){
            cout << "What would you like to do?" << endl
                << "1. Learn about Bulbasaur" << endl
                << "2. Learn about Squirtle" << endl
                << "3. Learn about Charmander" << endl;
            cin >> teamSelect;
        }
        if (teamNum == 0){
            cout << "Oh no! It seems that Professor Oak has run out of" << endl
                << "starter Pokemon. Better luck next time!" << endl;
        }
    }

    return 0;
}