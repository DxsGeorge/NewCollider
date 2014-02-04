#ifndef INITIALIZEITEMS_H
#define INITIALIZEITEMS_H

#include <vector>
#include "collidables.h"


std::vector<Sphere> InitializeAtoms(int N, float R);
std::vector<Molecule3> InitializeMol(int N, float R);

#endif