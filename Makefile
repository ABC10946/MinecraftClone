CC = g++
CFLAGS = -Wall
LIBS = -lGLEW -lGL -lglfw
PROGRAM = MinecraftClone
SRC = main.cpp shader.cpp

all: $(PROGRAM)

$(PROGRAM): $(SRC)
	$(CC) $(SRC) $(LIBS) -o $(PROGRAM)
