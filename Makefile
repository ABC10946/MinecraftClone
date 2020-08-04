CC = g++
CFLAGS = -Wall
LIBS = -lglut -lGLU -lGL -lm
PROGRAM = MinecraftClone
SRC = main.cpp 

all: $(PROGRAM)

$(PROGRAM): $(SRC)
	$(CC) $(SRC) $(LIBS) -o $(PROGRAM)
