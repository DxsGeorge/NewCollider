#ifndef MATH_H
#define MATH_H

#include "irrlicht.h"

class Point{
public:
	float x;
	float y;
	float z;
	Point (float _x, float _y, float _z){
		x=_x;
		y=_y;
		z=_z;
	}
	Point(){
		x=0;
		y=0;
		z=0;
	}
	irr::core::vector3df operator-(Point p){
		return irr::core::vector3df(this->x-p.x,this->y-p.y,this->z-p.z);
	}
	float distance(Point p){
		return sqrt((this->x-p.x)*(this->x-p.x)+(this->y-p.y)*(this->y-p.y)+(this->z-p.z)*(this->z-p.z));
	}
	Point operator+(irr::core::vector3df v){
		return Point(this->x+v.X,this->y+v.Y,this->z+v.Z);
	}
};

class Vector3 {
	
public:
	float x;
	float y;
	float z;
	Vector3 (float _x,float _y,float _z){
		x=_x;
		y=_y;
		z=_z;
	}
	Vector3 (){
		x=0;
		y=0;
		z=0;
	}
	float magnitude(){
		float magn=sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
		return magn;
	}
	void normalize(){
		float magn=this->magnitude();
		this->x=this->x/magn;
		this->y=this->y/magn;
		this->z=this->z/magn;
	}
	Vector3 operator+(Vector3 v){
		return Vector3(v.x+x,v.y+y,v.z+z);
	}
	float operator*(Vector3 v){
		return (v.x*x+v.y*y+v.z*z);
	}
	Vector3 operator*(float f){
		return Vector3(f*x,y*f,z*f);
	}
	Vector3 operator/(float f){
		return Vector3 (x/f,y/f,z/f);
	}
	Vector3 operator=(Vector3 v){
		return Vector3 (x=v.x,y=v.y,z=v.z);
	}
	Vector3 operator-(Vector3 v) {
		return Vector3(x-v.x,y-v.y,z+v.z);
	}
	Vector3 cross(Vector3 v) {
		return Vector3(x*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
	}
};

class Matrix33{
public:
	irr::core::vector3df v1; //row1
	irr::core::vector3df v2; //row2
	irr::core::vector3df v3; //row3
	Matrix33 (irr::core::vector3df _v1, irr::core::vector3df _v2, irr::core::vector3df _v3){
		v1=_v1;
		v2=_v2;
		v3=_v3;
	}
	Matrix33 (){
		irr::core::vector3df v1,v2,v3;
	}
	float Det(){
		return v1.Z*v2.X*v3.Y+v1.X*v2.Y*v3.Z+v1.Y*v2.Z*v3.X-v1.X*v2.X*v3.Z-v1.Z*v2.Y*v3.X-v1.X*v2.Z*v3.Y;
	}
	Matrix33 Inverse(){
		float det=this->Det();
		irr::core::vector3df row1 ((v2.Y*v3.Z-v2.Z*v3.Y)/det,(v1.Z*v3.Y-v1.Y*v3.Z)/det,(v1.Y*v2.Z-v1.Z*v2.Y)/det);
		irr::core::vector3df row2 ((v2.Z*v3.X-v2.X*v3.Z)/det,(v1.X*v3.Z-v1.Z*v3.X)/det,(v1.Z*v2.X-v1.X*v2.Z)/det);
		irr::core::vector3df row3 ((v2.X*v3.Y-v2.Y*v3.X)/det,(v1.Y*v3.X-v1.X*v3.Y)/det,(v1.X*v2.Y-v1.Y*v2.X)/det);
		return Matrix33 (row1,row2,row3);
	}
	Matrix33 fromAXisAngle(irr::core::vector3df v, float angle){
		angle*=3.14/180;
		irr::core::vector3df row1 (cos(angle)+v.X*v.X*(1-cos(angle)), 
			          v.X*v.Y*(1-cos(angle))-v.Z*sin(angle),
					  v.X*v.Z*(1-cos(angle))+v.Y*sin(angle));
		irr::core::vector3df row2 (v.Y*v.X*(1-cos(angle))+v.Z*sin(angle),
					  cos(angle)+v.Z*v.Z*(1-cos(angle)),
					  v.Y*v.Z*(1-cos(angle))-v.X*sin(angle));
		irr::core::vector3df row3 (v.Z*v.X*(1-cos(angle))-v.Y*sin(angle),
					  v.Z*v.Y*(1-cos(angle))+v.X*sin(angle),
					  cos(angle)+v.Z*v.Z*(1-cos(angle)));
		return Matrix33 (row1,row2, row3);
	}
	Vector3 operator*(irr::core::vector3df v){
		float a=v1.X*v.X+v1.Y*v.Y+v1.Z*v.Z;
		float b=v2.X*v.X+v2.Y*v.Y+v2.Z*v.Z;
		float c=v3.X*v.X+v3.Y*v.Y+v3.Z*v.Z;
		return Vector3 (a,b,c);
	}
};

class AxisAngle{
public:
	irr::core::vector3df v;
	float angle;
	AxisAngle(irr::core::vector3df _v, float _angle){
		v=_v;
		angle=_angle;
	}
	AxisAngle(){
		v=irr::core::vector3df(0,0,0);
		angle=0;
	}
};
using namespace irr::core;
quaternion fromVector (vector3df v){
	quaternion q;
	q.X=v.X;
	q.Y=v.Y;
	q.Z=v.Z;
	q.W=0;
	return q;
}

vector3df purequatToVector(quaternion q) {
	return vector3df(q.X,q.Y,q.Z);
}

vector3df fromRotation(quaternion q,vector3df v){
	quaternion q1;
	q1=fromVector(v);
	q1=q*q1*q.makeInverse();
	return v=purequatToVector(q1);

}

#endif