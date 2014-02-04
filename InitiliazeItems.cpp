#include <vector>
#include <time.h>

#include "InitializeItems.h"
#include "math3.h"
#include "irrlicht.h"
#include "collidables.h"



#define SQRT2 1.4142135;
#define DIVSQRT2 0.70710678118;



std::vector<Sphere> InitializeAtoms(int N, float R)
{
	
	std::vector<Sphere> spheres;
	spheres.reserve(N);
	srand(time(NULL));
	Sphere sph;
	for (int i=0;i<N;i++){

		sph.cm=Point(rand()%2*N*R,rand()%2*N*R,rand()%2*N*R);
		sph.R=R;
		sph.speed=irr::core::vector3df(rand()%10,rand()%10,rand()%10);
		spheres.push_back(sph);

	}
	return spheres;
}	
std::vector<Molecule3> InitializeMol (int N, float R){
	
	std::vector<Molecule3> mols;
	mols.reserve(N);
	srand(time(NULL));
	Molecule3 m;
	for (int i=0;i<N;i++){

		m.cm=Point(rand()%2*N*R,rand()%2*N*R,rand()%2*N*R);
		m.R=R;
		m.sph1=m.sph2=m.sph3=(m.cm-Point(0,0,0));
		m.orientation=irr::core::quaternion(rand(),rand(),rand(),rand());
		m.orientation.normalize();
		m.w=AxisAngle(irr::core::vector3df(rand(),rand(),rand()),rand()%360);
		m.w.v.normalize();
		irr::core::vector3df temp1,temp2,temp3;
		temp1=irr::core::vector3df(-R,-R,0);
		temp2=irr::core::vector3df(R,-R,0);
		temp3=irr::core::vector3df(0,R,0);
		temp1=fromRotation(m.orientation,temp1);
		temp2=fromRotation(m.orientation,temp2);
		temp3=fromRotation(m.orientation,temp3);
		m.sph1+=temp1;
		m.sph2+=temp2;
		m.sph3+=temp3;
		mols.push_back(m);

	}	
	return mols;
}