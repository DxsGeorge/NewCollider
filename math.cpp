#include "math3.h"
#include "quaternion.h"
#include "vector3d.h"


float Dot3(Vector3 v1, Vector3 v2){
	float res=v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
	return res;
}

Vector3 Cross3(Vector3 v1, Vector3 v2){
	Vector3 res;
	res.x=v1.x*v2.z-v1.z*v2.y;
	res.y=v1.z*v2.x-v1.x*v2.z;
	res.z=v1.x*v2.y-v1.y*v2.x;
	return res;
}

float magn3(Vector3 v1){
	float magn=sqrt(v1.x*v1.x+v1.y*v1.y+v1.z*v1.z);
	return magn;
}

Vector3 Normalize3(Vector3 v){
	float magn=magn3(v);
	Vector3 v1;
	v1.x=v.x/magn;
	v1.y=v.y/magn;
	v1.z=v.z/magn;
	return v1;
}
namespace irr{
namespace core{
vector3df rotatevector(quaternion q,vector3df v){
	quaternion q1;
	q.normalize();
	q1.X=v.X;
	q1.Y=v.Y;
	q1.Z=v.Z;
	q1.W=0;
	q1=q*q1*q.makeInverse();
	v.X=q1.X;
	v.Y=q1.Y;
	v.Z=q1.Z;
	return v;
}
vector3df rotatevector2(quaternion q,vector3df v){
	vector3df q1;
	q1.X=q.X;
	q1.Y=q.Y;
	q1.Z=q.Z;
	vector3df t= (v.crossProduct(q1))*2;
	v=v+t*(q.W)+q1.crossProduct(t);
	return v;
}
}
}