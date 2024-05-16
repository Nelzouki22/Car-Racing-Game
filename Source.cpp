#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // for _kbhit() function
#include <windows.h> // for Sleep() function

using namespace std;

const int trackLength = 40;
int playerPosition = trackLength / 2;
int opponentPosition = trackLength / 2;

void drawTrack() {
    cout << "|";
    for (int i = 0; i < trackLength; ++i) {
        cout << "-";
    }
    cout << "|" << endl;
}

void drawCars() {
    for (int i = 0; i < trackLength; ++i) {
        if (i == playerPosition) {
            cout << "X";
        }
        else if (i == opponentPosition) {
            cout << "O";
        }
        else {
            cout << " ";
        }
    }
    cout << endl;
}

void moveOpponent() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    int move = rand() % 3 - 1; // Random move: -1, 0, or 1
    opponentPosition += move;

    if (opponentPosition < 0) {
        opponentPosition = 0;
    }
    else if (opponentPosition >= trackLength) {
        opponentPosition = trackLength - 1;
    }
}

int main() {
    cout << "Welcome to the Car Racing Game!" << endl;

    while (true) {
        system("cls"); // Clear the console
        drawTrack();
        drawCars();
        moveOpponent();

        // Check for collision
        if (playerPosition == opponentPosition) {
            cout << "Game Over! You crashed into the opponent's car." << endl;
            break;
        }

        // Check for player input
        if (_kbhit()) { // Check if a key is pressed
            char key = _getch(); // Get the pressed key
            if (key == 'a') {
                playerPosition--;
                if (playerPosition < 0) {
                    playerPosition = 0;
                }
            }
            else if (key == 'd') {
                playerPosition++;
                if (playerPosition >= trackLength) {
                    playerPosition = trackLength - 1;
                }
            }
        }

        // Pause for a moment
        Sleep(100);
    }

    return 0;
}
