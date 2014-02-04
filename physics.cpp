#include "physics.h"
#include "math3.h"
#include "collidables.h"
#include "irrlicht.h"

void SphereCollisionResponse (Sphere& sph1, Sphere& sph2, float e){
	irr::core::vector3df normal=sph2.cm-sph1.cm;
	float dist=sph1.cm.distance(sph2.cm);
	float penetration=sph1.R+sph2.R-dist;
	normal.normalize();
	float distcenter1 = sph1.cm.distance(Point(0,0,0));
	float distcenter2 = sph2.cm.distance(Point(0,0,0));
	if (distcenter2>distcenter1) sph1.cm=sph1.cm+penetration*normal;
	else sph2.cm=sph2.cm+penetration*normal;
	irr::core::vector3df relative=sph1.speed-sph2.speed;
	float vdotn = normal.dotProduct(relative);
	float j=-((1+e)*vdotn)/2;
	sph1.speed+=j*normal;
	sph2.speed-=j*normal;
}

void checkSphereCollision (Sphere& sph1, Sphere& sph2, float e){
	if (sph1.cm.distance(sph2.cm)<=sph1.R+sph2.R) SphereCollisionResponse(sph1,sph2,e);
}

void BallToWallCheck(Sphere& sph,float size){
	if (sph.cm.x+sph.R>size) sph.speed.X*=-1;
	if (sph.cm.y+sph.R>size) sph.speed.Y*=-1;
	if (sph.cm.z+sph.R>size) sph.speed.Z*=-1;
}

void UpdateSpherePos(Sphere& sph, float dt){
	sph.cm=sph.cm+sph.speed*dt;
}

void checkMolCollision(Molecule3& m1, Molecule3& m2, float e){
	if (m1.cm.distance(m2.cm)<m1.R+m2.R){
	}
}
