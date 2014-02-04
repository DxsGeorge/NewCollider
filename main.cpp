#include <stdio.h>     // - Just for some ASCII messages

#include <time.h>
#include <vector>
#include "gl/glut.h" 
#include "irrlicht.h"
#include "visuals.h"
#include "InitializeItems.h" 

////////////////// State Variables ////////////////////////

std::vector<Sphere> spheres;
std::vector<Molecule3> mols;

/////////////// Main Program ///////////////////////////
int main(int argc, char* argv[])
{ 
	int N,choice;
	float R;
	printf("Molecules/Balls? (1 for balls)");
	scanf_s("%d",&choice);
	printf("How many? \n");
	scanf_s("%d",&N);
	printf("radius? \n");
	scanf_s("%f",&R);
	if (choice==1) 
		spheres=InitializeAtoms(N,R);
	else 
		mols=InitializeMol(N,R);

	int mainwin;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(960,480);
	glutInitWindowPosition(50,50);
	mainwin=glutCreateWindow("Acton!");
	Setup();
	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Idle);
	glutMainLoop();
	return 0;


}  

