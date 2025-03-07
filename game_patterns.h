#ifndef GAME_PATTERNS_H
#define GAME_PATTERNS_H

#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define CELL_SIZE 10
#define GRID_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)

extern bool grid[GRID_WIDTH][GRID_HEIGHT];
extern bool nextGrid[GRID_WIDTH][GRID_HEIGHT];

// Other Patterns

void CrossInit();

// Still Lifes
// Block - BeeHive - Loaf - Boat - Tub

void BlockInit();
void BeehiveInit();
void LoafInit();
void BoatInit();
void TubInit();

// Oscillators
// Blinker (2) - Toad (2) - Beacon (2) - Pulsar (3) - PentaDecathion (15)

void BlinkerInit();
void ToadInit();
void BeaconInit();
void PulsarInit();
void PentaDecaInit();

// Spaceships
// Glider - LWSS - MWSS - HWSS

void GliderInit();
void LWSSInit();
void MWSSInit();
void HWSSInit();

#endif
