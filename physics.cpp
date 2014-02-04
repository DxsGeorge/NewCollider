#include "physics.h"
#include "math3.h"
#include "collidables.h"
#include "irrlicht.h"
#define DIVSQRT2 0.70710678118

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
	if (fabs(sph.cm.x+sph.R)>size) {
		if (sph.cm.x<0) sph.cm.x+=fabs(sph.cm.x-sph.R-size);
		else sph.cm.x-=fabs(sph.cm.x+sph.R-size);
		sph.speed.X*=-1;
	}
	if (fabs(sph.cm.y+sph.R)>size) {
		if (sph.cm.y<0) sph.cm.y+=fabs(sph.cm.y-sph.R-size);
		else sph.cm.y-=fabs(sph.cm.y+sph.R-size);
		sph.speed.Y*=-1;
	}
	if (fabs(sph.cm.z+sph.R)>size) {
		if (sph.cm.z<0) sph.cm.z+=fabs(sph.cm.z-sph.R-size);
		else sph.cm.z-=fabs(sph.cm.z+sph.R-size);
		sph.speed.Z*=-1;
	}
}

void UpdateSpherePos(Sphere& sph, float dt){
	sph.cm=sph.cm+sph.speed*dt;
}

void checkMolCollision(Molecule3& m1, Molecule3& m2, float e){
	if (m1.cm.distance(m2.cm)<m1.R+m2.R){
	}
}

void MolCollisionResponse(Molecule3& m1, Molecule3& m2, float e){
};

void MolToWallCheck(Molecule3& m,float size){
};

void UpdateMolPos(Molecule3& m, float dt){
	irr::core::vector3df temp1;
	irr::core::quaternion tempw(m.w.v.X*sin((m.w.angle*3.14/180)/2),m.w.v.Y*sin((m.w.angle*3.14/180)/2),m.w.v.Z*sin((m.w.angle*3.14/180)/2),cos((m.w.angle*3.14/180)/2));
	//temp1 = irr::core::vector3df(m.cm.x,m.cm.y,m.cm.z);
	m.orientation=m.orientation+tempw*dt*0.5;
#if 1
	m.sph1-=temp1;
	m.sph2-=temp1;
	m.sph3-=temp1;
#endif
	m.sph1=fromRotation(m.orientation,m.sph1);
	m.sph2=fromRotation(m.orientation,m.sph2);
	m.sph3=fromRotation(m.orientation,m.sph3);
#if 1
	m.sph1+=temp1;
	m.sph2+=temp1;
	m.sph3+=temp1;
#endif 
	//m.cm=m.cm+m.centersp*dt;
};
