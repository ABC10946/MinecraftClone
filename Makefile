CC = gcc
CFLAGS = -Wall
LIBS = -lGLEW -lGL -lglfw
PROGRAM = MinecraftClone
SRC = main.cpp

all: $(PROGRAM)

$(PROGRAM): $(SRC)
	$(CC) $(SRC) $(LIBS) -o $(PROGRAM)
