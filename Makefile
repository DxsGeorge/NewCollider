SOURCES = InitiliazeItems.cpp  main.cpp   physics.cpp  visuals.cpp # math.cpp
LIBS = -lGL -lglut -lGLU
FLAGS = -I./irr -I/usr/include/GL/
EXEC = coll

all:
	g++ $(SOURCES) $(LIBS) $(FLAGS) -o $(EXEC)
