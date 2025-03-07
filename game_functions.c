#include "game_functions.h"
#include "game_patterns.h"
#include <raylib.h>

void RandomizeGameGrid() {
  for (int x = 0; x < GRID_WIDTH; x++){
    for (int y = 0; y < GRID_HEIGHT; y++){
      grid[x][y] = GetRandomValue(0,1);
    }
  }
}

void CleanGameGrid() {
  for (int x =0; x < GRID_WIDTH; x++){
    for(int y = 0; y < GRID_HEIGHT; y++){
      grid[x][y] = 0;
    }
  }
}

int CountNeighbors(int x, int y){
  int count = 0;
  for(int dx = -1; dx <= 1; dx++){
    for (int dy = -1; dy <= 1; dy++){
      if (dx == 0 && dy == 0) continue; // to skip the cell itself, we need the neighors not it 
      int nx = x + dx;
      int ny = y + dy;

      // check that neighbor is not out of grid bounds

      if (nx >= 0 && nx < GRID_WIDTH && ny < GRID_HEIGHT){
        count += grid[nx][ny];
      }
    }
  }
    return count;
}

// main game of life rules

void UpdateGameGrid() {
  for (int x = 0; x < GRID_WIDTH; x++){
      for (int y = 0; y < GRID_HEIGHT; y++){
        int neighbors = CountNeighbors(x, y);
        if (grid[x][y]) {
            nextGrid[x][y] = (neighbors == 2 || neighbors == 3);
        } else {
            nextGrid[x][y] = (neighbors == 3);
        }
    }
  }
   for (int x = 0; x < GRID_WIDTH; x++){
      for (int y = 0; y < GRID_HEIGHT; y++){
          grid[x][y] = nextGrid[x][y];
      }
    }

  }

void DrawGameGrid() {
for (int x = 0; x < GRID_WIDTH; x++){
    for (int y = 0; y < GRID_HEIGHT; y++){
      if (grid[x][y]){
          DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
      }
    }
  }
}

