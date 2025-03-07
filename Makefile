# Compiler
CC = gcc

# Common Compilation Flags
CFLAGS = -Wall -Wextra -g

# Detect OS
OS := $(shell uname)

# OS-Specific Libraries
ifeq ($(OS), Linux)
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else ifeq ($(OS), Darwin)  # macOS
    LDFLAGS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else  # Assume Windows (MinGW)
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
endif

# Files
SRC = game-of-life.c game_patterns.c game_functions.c
OBJ = $(SRC:.c=.o)
TARGET = game

# Default Build
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(OBJ) $(TARGET)
