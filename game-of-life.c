#include <raylib.h>
#include <stdbool.h>
#include "game_patterns.h"
#include "game_functions.h"
//#include <stdio.h>


// main definitions are in the game_patterns.h
bool grid[GRID_WIDTH][GRID_HEIGHT] = {0};
bool nextGrid[GRID_WIDTH][GRID_HEIGHT] = {0};

// Menu

// Menu Options
const char *menuItems[] = {
    "Block", "Beehive", "Loaf", "Boat", "Tub", 
    "Blinker", "Toad", "Beacon","Pulsar", "PentaDecathlon", 
    "Glider", "Small SpaceShip", "Med SpaceShip", "Big SpaceShip",
    "Cross"
};

int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
int selectedItem = 0;
bool menuVisible = false;

void ApplySelectedPattern() {
  CleanGameGrid();

  switch (selectedItem) {
    case 0: BlockInit(); break;
    case 1: BeehiveInit(); break;
    case 2: LoafInit(); break;
    case 3: BoatInit(); break;
    case 4: TubInit(); break;
    case 5: BlinkerInit(); break;
    case 6: ToadInit(); break;
    case 7: BeaconInit(); break;
    case 8: PulsarInit(); break;
    case 9: PentaDecaInit(); break;
    case 10: GliderInit(); break;
    case 11: LWSSInit(); break;
    case 12: MWSSInit(); break;
    case 13: HWSSInit(); break;
    case 14: CrossInit(); break;
    }
}

int main(void) {
  int gameFPS = 10;
  bool isGamePaused = 0;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of Life - By Morty");
  SetTargetFPS(gameFPS);

  CrossInit();

  while (!WindowShouldClose()){

    // Toggle Menu
    
    if (IsKeyPressed(KEY_TAB)) menuVisible = !menuVisible;
    // Menu Mavigation

    if (menuVisible){
      // Navigation

        if (IsKeyPressed(KEY_DOWN)) selectedItem = (selectedItem + 1) % menuSize;
      
        if (IsKeyPressed(KEY_UP)) selectedItem = (selectedItem - 1 + menuSize) % menuSize;

        if (IsKeyPressed(KEY_ENTER)) ApplySelectedPattern() ;

      // Check Mouse Click
      
        Vector2 mousePos = GetMousePosition();
      
        for (int i = 0; i < menuSize; i++) {
            Rectangle itemRect = {10, 20 + i * 40, 180, 30};
            if (CheckCollisionPointRec(mousePos, itemRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            selectedItem = i;
            ApplySelectedPattern();
                }
            }
    }

    if (IsKeyPressed(KEY_P)){
        isGamePaused = !isGamePaused;      
      } 
    if (!isGamePaused){
      if (IsKeyPressed(KEY_C)){
        CrossInit();
      }
      if (IsKeyPressed(KEY_G)){
        GliderInit();
      }
      if (IsKeyPressed(KEY_R)){
          RandomizeGameGrid();
      }
      if (IsKeyPressed(KEY_SPACE)){
        CleanGameGrid();
        DrawGameGrid();
      }   
      

    
    UpdateGameGrid();
    }
    BeginDrawing();
    ClearBackground(BLACK);
 

    // Draw Menu (only if menuVisible is true)
    if (menuVisible) {
      for (int i = 0; i < menuSize; i++) {
        Color textColor = (i == selectedItem) ? YELLOW : GRAY;
        DrawRectangle(10, 20 + i * 40, 180, 30, (i == selectedItem) ? DARKGRAY : LIGHTGRAY);
        DrawText(menuItems[i], 20, 25 + i * 40, 20, textColor);
      }
    }

    int offsetX = menuVisible ? 200 : 0; // Shift grid when menu is visible
    DrawGameGrid();
    DrawText("P pause", (10 + offsetX), 10, 20, GREEN);
    DrawText("Tab patterns menu", (10 + offsetX), 30, 20, GREEN);
    DrawText("R randomize", (10 + offsetX), 50, 20, GREEN);
    DrawText("Space to clear screen", (10 + offsetX), 70,20, GREEN);
    DrawText("FPS: ", (10 + offsetX), 90, 20, GREEN);
    DrawFPS((100 + offsetX), 90);
    DrawText(isGamePaused ? "Paused" : "Running", (10 + offsetX), 110, 20, GREEN);
    EndDrawing();
    
  }

  CloseWindow();
  return 0;
}
