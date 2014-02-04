#ifndef PHYSICS_H
#define PHYSICS_H

#include "math3.h"
#include "collidables.h"

void checkSphereCollision (Sphere& sph1, Sphere& sph2, float e);

void SphereCollisionResponse (Sphere& sph1, Sphere& sph2, float e);

void BallToWallCheck(Sphere& sph, float size);

void UpdateSpherePos(Sphere& sph, float dt);

void checkMolCollision(Molecule3& m1, Molecule3& m2, float e);

void MolCollisionResponse(Molecule3& m1, Molecule3& m2, float e);

void MolToWallCheck(Molecule3& m);

void UpdateMolPos(Molecule3& m, float dt);

#endif