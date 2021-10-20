#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdio.h>

using namespace std;


void MyWallet(int betAmount, int winningNumber, int walletAmount) {
        if(betAmount == winningNumber) {
            cout << "\n " << "   You WOON!!!\n\n ";
        } else {
            cout << "\n " << "   Try again ...\n\n ";
        }
    }

int main()
{
    int wallet = 10;
    int buttons;
    int colour;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// used for colour

    cout << " Hi! Wellcome to the ";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "GAME\n ";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Your currency amount is: " << wallet << (char)36 << (char)36<< "\n ";
    cout << "Please, select the number of buttons:\n ";
    cin >> buttons;
    cout << "\n\n";

    srand(time (NULL)); //generate random number from 1 to player choice

    for(int numberOfButtons = 0; numberOfButtons < buttons; ++numberOfButtons) { //display buttons
        colour = rand() % 13 + 1; // set colour for buttons
        SetConsoleTextAttribute(hConsole, colour);
        cout << "    "  << (char)3;
    }

    int luckyNumber; // set the winner button
    //luckyNumber = rand() % buttons + 1;

    SetConsoleTextAttribute(hConsole, 15);
    int playerChoice;
    while (wallet > 0) {
        cout << "\n\n Wich one is the winner?\n Insert a number from 1 to " << buttons << ", 1 being first from left:\n ";
        cin >> playerChoice;
        //set choice only between 1 and button
        if(playerChoice > buttons || playerChoice == 0) {
            cout << " Select a number from 1 to " << buttons << ": \n ";
            cin >> playerChoice;
            while(playerChoice > buttons || playerChoice == 0) {
                cout << " You're being stubborn\n ";
                cin >> playerChoice;
            }
        }
        luckyNumber = rand() % buttons + 1;
        MyWallet(playerChoice, luckyNumber, wallet);
        if(luckyNumber == playerChoice){
            wallet += playerChoice;
        } else {
            wallet -= playerChoice;
        }
        cout << "Your currency amount is: " << wallet << (char)36 << (char)36<< "\n ";
        if(wallet == 0) {
            cout << "\n   ..No more many baby ..";
            SetConsoleTextAttribute(hConsole, 12);
            cout << " GAME OVER";
            SetConsoleTextAttribute(hConsole, 15);
            cout << " .. \n\n ";
        } else {
            cout << "Would you like to withdraw the money?" << "(" << "Yes = 1,No = 0" << ")\n ";
            cin >>playerChoice;
            if(playerChoice == 1) {
                cout << " Your prize is:" << wallet << (char)36 << (char)36<< "\n ";
                wallet = 0;
            }
        }
    }
    return 0;
}
