#include "game_patterns.h"
#include <raylib.h>

  int startX = GRID_WIDTH / 2;   // Center X
  int startY = GRID_HEIGHT / 2;  // Center Y

// NOTE 
// These patterns were generated with ChatGPT
// My main concren was the game rules and menus

// Still Lifes
// Block - BeeHive - Loaf - Boat - Tub

void BlockInit() {
    grid[startY][startX] = 1;
    grid[startY][startX + 1] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 1] = 1;
}

void BeehiveInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 3] = 1;
    grid[startY + 2][startX + 1] = 1;
    grid[startY + 2][startX + 2] = 1;
}

void LoafInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 3] = 1;
    grid[startY + 2][startX + 1] = 1;
    grid[startY + 2][startX + 3] = 1;
    grid[startY + 3][startX + 2] = 1;
}

void BoatInit() {
    grid[startY][startX] = 1;
    grid[startY][startX + 1] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 2] = 1;
    grid[startY + 2][startX + 1] = 1;
}

void TubInit() {
    grid[startY][startX + 1] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 2] = 1;
    grid[startY + 2][startX + 1] = 1;
}

// Oscillators
// Blinker (2) - Toad (2) - Beacon (2) - Pulsar (3) - PentaDecathion (15)

void BlinkerInit() {
    grid[startY][startX - 1] = 1;
    grid[startY][startX] = 1;
    grid[startY][startX + 1] = 1;
}

void ToadInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY][startX + 3] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 1] = 1;
    grid[startY + 1][startX + 2] = 1;
}


void BeaconInit() {
    grid[startY][startX] = 1;
    grid[startY][startX + 1] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 1] = 1;
    grid[startY + 2][startX + 2] = 1;
    grid[startY + 2][startX + 3] = 1;
    grid[startY + 3][startX + 2] = 1;
    grid[startY + 3][startX + 3] = 1;
}

void PulsarInit() {
    int startX = GRID_WIDTH / 2 - 6;
    int startY = GRID_HEIGHT / 2 - 6;

    int pulsarPattern[13][13] = {
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0}
    };

    for (int y = 0; y < 13; y++)
        for (int x = 0; x < 13; x++)
            grid[startY + y][startX + x] = pulsarPattern[y][x];
}


void PentaDecaInit() {

    for (int i = 0; i < 10; i++) {
        if (i == 0 || i == 4 || i == 5 || i == 9) {
            grid[startY + i][startX + 1] = 1;
            grid[startY + i][startX + 2] = 1;
        } else {
            grid[startY + i][startX] = 1;
            grid[startY + i][startX + 3] = 1;
        }
    }
}

// Spaceships
// Glider - LWSS - MWSS - HWSS

void GliderInit() {
    grid[startY][startX + 1] = 1;
    grid[startY + 1][startX + 2] = 1;
    grid[startY + 2][startX] = 1;
    grid[startY + 2][startX + 1] = 1;
    grid[startY + 2][startX + 2] = 1;
}


void LWSSInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY][startX + 3] = 1;
    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 4] = 1;
    grid[startY + 2][startX + 4] = 1;
    grid[startY + 3][startX] = 1;
    grid[startY + 3][startX + 3] = 1;
}

void MWSSInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY][startX + 3] = 1;
    grid[startY][startX + 4] = 1;

    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 5] = 1;

    grid[startY + 2][startX + 5] = 1;

    grid[startY + 3][startX] = 1;
    grid[startY + 3][startX + 4] = 1;
}

void HWSSInit() {
    grid[startY][startX + 1] = 1;
    grid[startY][startX + 2] = 1;
    grid[startY][startX + 3] = 1;
    grid[startY][startX + 4] = 1;
    grid[startY][startX + 5] = 1;

    grid[startY + 1][startX] = 1;
    grid[startY + 1][startX + 6] = 1;

    grid[startY + 2][startX + 6] = 1;

    grid[startY + 3][startX] = 1;
    grid[startY + 3][startX + 5] = 1;
}

// Something Else
void CrossInit() {    
    grid[startX][startY] = 1;       // Center cell
    grid[startX + 1][startY] = 1;   // Right
    grid[startX - 1][startY] = 1;   // Left
    grid[startX][startY + 1] = 1;   // Bottom
    grid[startX][startY - 1] = 1;   // Top
}


