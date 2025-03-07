
# Game of Life (Raylib)

A simple implementation of Conway's Game of Life using **Raylib**.
Patterns were generated using ChatGPT.
I was mainly concerned with the game logic and menus.
## Features
- Toggleable side menu (**TAB**) to select different starting patterns.
- Various predefined patterns (Still Lifes, Oscillators, Spaceships).
- Keyboard & Mouse controls for easy interaction.

## Controls
- **TAB** - Toggle menu visibility
- **Arrow Keys (Up/Down)** - Navigate menu
- **Enter** - Apply selected pattern
- **Mouse Click** - Select pattern from the menu

## Installation & Compilation
Make sure you have **Raylib** installed before compiling.

### Linux & Mac
```sh
gcc game-of-life.c game_patterns.c game_functions.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./game
```

### Windows (MinGW)
```sh
gcc game-of-life.c game_patterns.c game_functions.c -o game.exe -lraylib -lopengl32 -lgdi32 -lwinmm
./game.exe
```

## Notes
- This project is just for fun and learning.
- Feel free to modify or expand it as needed.

## Credits
- Built with **Raylib**
- Inspired by Conway's **Game of Life**

