#include <stdio.h>     // - Just for some ASCII messages
#include <time.h>
#include <vector>
#include <math.h>
#include "gl/glut.h"   // - An interface and windows 
//   management library
#include "math3.h"
#include "visuals.h"   
#include "physics.h"
#include "collidables.h"




float t=0;
static float rotx = 0.0;
static float roty = 0.0;
static float rotz = 0.0;
static float tranx = 0.0;
static float trany = 0.0;
static float tranz = 0.0;

void axes()
{
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0, 0, -1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,100.0);
	glEnd();
	glPopMatrix(); 
}

void Box(int N, float R){
	glColor4f(1,1,1,0.2);
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glEnd();
	/*glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glEnd();*/
	/*glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glEnd();*/
	glColor4f(0,0,1,1);
	glBegin(GL_LINES);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glEnd();
}


void Render()
{    
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0,0,-8*N*R);
	//glRotatef(45,0,1,0);
	glTranslatef(tranx,trany,tranz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);
	//Box(N,R);
	glColor4f(1,0,0,1.0);
	if (spheres.size()>0){
		for (int i=0;i<int(spheres.size());i++){
			glPushMatrix();
			glTranslatef(spheres.at(i).cm.x,spheres.at(i).cm.y,spheres.at(i).cm.z);
			glutSolidSphere(spheres.at(i).R,30,30);
			glPopMatrix();
		}
	}
	else {
		for (int i=0;i<int(mols.size());i++){
			glPushMatrix();
			glTranslatef(mols.at(i).cm.x,mols.at(i).cm.y,mols.at(i).cm.z);
			glPushMatrix();
			glTranslatef(mols.at(i).sph1.X,mols.at(i).sph1.Y,mols.at(i).sph1.Z);
			glutSolidSphere(mols.at(i).R,20,20);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(mols.at(i).sph2.X,mols.at(i).sph2.Y,mols.at(i).sph2.Z);
			glutSolidSphere(mols.at(i).R,20,20);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(mols.at(i).sph3.X,mols.at(i).sph3.Y,mols.at(i).sph3.Z);
			glutSolidSphere(mols.at(i).R,20,20);
			glPopMatrix();
			glPopMatrix();
		}
	}


	glutSwapBuffers();
}

//-----------------------------------------------------------


void Idle()
{
	t+=0.01;
	float e=1.0;
	float dt=0.01;
	if (spheres.size()>0){
		for (int i=0;i<int(spheres.size());i++){
			for (int j=i+1;j<int(spheres.size());j++){
				checkSphereCollision (spheres.at(i), spheres.at(j),e);
				}
			BallToWallCheck(spheres.at(i),spheres.size()*spheres.at(i).R);
			UpdateSpherePos(spheres.at(i),dt);
		}
	}
	else {
		for (int i=0;i<int(mols.size());i++){
			for (int j=i+1;j<int(mols.size());j++){
				checkMolCollision(mols.at(i),mols.at(j),e);
			}
			MolToWallCheck(mols.at(i));
			UpdateMolPos(mols.at(i),dt);
		}	
	}
	glutPostRedisplay(); 
}


//-----------------------------------------------------------

void Resize(int w, int h)
{ 
	// define the visible area of the window ( in pixels )
	if (h==0) h=1;
	glViewport(0,0,w,h); 

	// Setup viewing volume

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	//glOrtho(-4*N*R,4*N*R,-4*N*R,4*N*R,4*N*R,-4*N*R);


	float aspect = (float)w/(float)h;             /// aspect ratio
	if (spheres.size()>0) gluPerspective(60.0, aspect, 1.0, 500.0+spheres.size()*spheres.at(0).R);
	else gluPerspective(60.0, aspect, 1.0, 500.0+mols.size()*mols.at(0).R);
}


//-----------------------------------------------------------

void Setup()  
{ 

	//glEnable( GL_CULL_FACE );
	glEnable( GL_BLEND );
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);
	glDepthFunc( GL_LEQUAL );      
	glClearDepth(1.0); 		      


	//Set up light source
	GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat lightPos[] = { -20.0, 20.0, 150.0, 1.0 };

	glLightfv( GL_LIGHT0, GL_AMBIENT, ambientLight );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight );
	glLightfv( GL_LIGHT0, GL_POSITION,lightPos );


	// polygon rendering mode and material properties
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0);



	// Black background
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void Keyboard(unsigned char key,int x,int y)
{

	switch(key)
	{
	case 'o' : rotx-=2.0f;
		break;
	case 'p' : rotx+=2.0f;
		break;
	case 'k' : roty-=2.0f;
		break;
	case 'l' : roty+=2.0f;
		break;
	case 'n' : rotz-=2.0f;
		break;
	case 'm' : rotz+=2.0f;
		break;
	case 'q' : tranx-=2.0f;
		break;
	case 'w' : tranx+=2.0f;
		break;
	case 'a' : trany-=2.0f;
		break;
	case 's' : trany+=2.0f;
		break;
	case 'z' : tranz-=2.0f;
		break;
	case 'x' : tranz+=2.0f;
		break;
	default : 
		break;

	}

	glutPostRedisplay();
	//
}



