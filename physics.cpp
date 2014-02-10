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
	if (float dif=fabs(sph.cm.x)+sph.R-size>0) {
		if (sph.cm.x<0) sph.cm.x+=(dif+0.5);
		else sph.cm.x-=(dif+0.5);
		sph.speed.X*=-1;
	}
	if (float dif=fabs(sph.cm.y)+sph.R-size>0) {
		if (sph.cm.y<0) sph.cm.y+=dif+0.5;
		else sph.cm.y-=(dif+0.5);
		sph.speed.Y*=-1;
	}
	if (float dif=fabs(sph.cm.z)+sph.R-size>0) {
		if (sph.cm.z<0) sph.cm.z+=(dif+0.5);
		else sph.cm.z-=(dif+0.5);
		sph.speed.Z*=-1;
	}
}

void UpdateSpherePos(Sphere& sph, float dt){
	sph.cm=sph.cm+sph.speed*dt;
}

void checkMolCollision(Molecule3& m1, Molecule3& m2, float e){
}

void MolCollisionResponse(Molecule3& m1, Molecule3& m2, float e){
};

void MolToWallCheck(Molecule3& m,float size){
	if (float dif=fabs(m.cm.X)+m.R-size>0) {
		if (m.cm.X<0) m.cm.X+=(dif+0.5);
		else m.cm.X-=(dif+0.5);
		m.centersp.X*=-1;
	}
	if (float dif=fabs(m.cm.Y)+m.R-size>0) {
		if (m.cm.Y<0) m.cm.Y+=dif+0.5;
		else m.cm.Y-=(dif+0.5);
		m.centersp.Y*=-1;
	}
	if (float dif=fabs(m.cm.Z)+m.R-size>0) {
		if (m.cm.Z<0) m.cm.Z+=(dif+0.5);
		else m.cm.Z-=(dif+0.5);
		m.centersp.Z*=-1;
	}
};

void UpdateMolPos(Molecule3& m, float dt){
	//m.cm+=m.centersp*dt;
	m.orax.angle+=m.w.angle*dt;
	if (m.orax.angle>6.28) m.orax.angle-=6.28;
	m.mat.setRotationAxisRadians(m.orax.angle,m.orax.v);
	//m.mat[15]=1;
	m.sph1-=m.cm;
	m.sph2-=m.cm;
	m.sph3-=m.cm;
	m.mat.rotateVect(m.sph1);
	m.mat.rotateVect(m.sph2);
	m.mat.rotateVect(m.sph3);
	m.sph1+=m.cm;
	m.sph2+=m.cm;
	m.sph3+=m.cm;
	
};
