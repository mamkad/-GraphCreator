CC = g++
OUT_PATH = ./Bin/
PROJECT_NAME = GraphCreator

INCLUDE_PATH = -I./SFML/include -MMD -MP -DSFML_STATIC

LIB_PATH = -L./SFML/lib
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32


all: compile

compile:
	$(CC) -c main.cpp $(INCLUDE_PATH)

	$(CC) -c Node.cpp              $(INCLUDE_PATH)
	$(CC) -c GraphicObjectBase.cpp $(INCLUDE_PATH)
	$(CC) -c GraphObjectBase.cpp   $(INCLUDE_PATH)

	$(CC) -mwindows GraphObjectBase.o GraphicObjectBase.o Node.o main.o -o $(OUT_PATH)$(PROJECT_NAME) $(LIB_PATH) $(LIBS)
