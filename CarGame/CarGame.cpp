#include <iostream>
#include <conio.h>    
#include <windows.h>  
#include <ctime>     

using namespace std;

// Game Settings
const int roadWidth = 15;  // Width of the road
const int roadHeight = 20; // Height of the road
int carPosition = roadWidth / 2;
int score = 0;
bool gameOver = false;

// Draw the game state
void draw(char road[roadHeight][roadWidth]) {
    system("cls");
    for (int i = 0; i < roadHeight; i++) {
        for (int j = 0; j < roadWidth; j++) {
            cout << road[i][j];
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

// Update the car's position based on user input
void updateCarPosition(char road[roadHeight][roadWidth]) {
    if (_kbhit()) {
        char key = _getch();
        // Erase previous car position
        road[roadHeight - 2][carPosition] = ' ';
        road[roadHeight - 2][carPosition + 1] = ' ';

        // Move car based on key input
        if (key == 'a' && carPosition > 1) {
            carPosition -= 1;
        }
        else if (key == 'd' && carPosition < roadWidth - 3) {
            carPosition += 1;
        }

        // Draw new car position
        road[roadHeight - 2][carPosition] = 'O';
        road[roadHeight - 2][carPosition + 1] = 'O';
    }
}

// Generate obstacles randomly at the top row
void generateObstacle(char road[roadHeight][roadWidth]) {
    int obstaclePosition = rand() % (roadWidth - 3) + 1;
    road[0][obstaclePosition] = '#';
    road[0][obstaclePosition + 1] = '#';
}

// Move obstacles down the road
void moveObstacles(char road[roadHeight][roadWidth]) {
    for (int i = roadHeight - 2; i >= 0; i--) {
        for (int j = 0; j < roadWidth; j++) {
            if (road[i][j] == '#') {
                if (i == roadHeight - 2 && (j == carPosition || j == carPosition + 1)) {
                    gameOver = true;
                    return;
                }
                road[i][j] = ' ';
                if (i + 1 < roadHeight - 1) {
                    road[i + 1][j] = '#';
                }
            }
        }
    }
}

// Initialize the game
void initializeRoad(char road[roadHeight][roadWidth]) {
    for (int i = 0; i < roadHeight; i++) {
        for (int j = 0; j < roadWidth; j++) {
            road[i][j] = (j == 0 || j == roadWidth - 1) ? '|' : ' ';
        }
    }
    road[roadHeight - 2][carPosition] = 'O';
    road[roadHeight - 2][carPosition + 1] = 'O';
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    char road[roadHeight][roadWidth];
    initializeRoad(road);

    while (!gameOver) {
        draw(road);
        updateCarPosition(road);

        // Generate a new obstacle every few frames
        if (rand() % 5 == 0) {
            generateObstacle(road);
        }

        moveObstacles(road);

        score++;
        Sleep(100);  // Control game speed
    }

    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}
