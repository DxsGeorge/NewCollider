#ifndef VISUALS_H
#define VISUALS_H
#include "math3.h"
#include "collidables.h"
#include <vector>

extern std::vector<Sphere> spheres;
extern std::vector<Molecule3> mols;


//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 
void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void Keyboard(unsigned char key,int x,int y);


#endif