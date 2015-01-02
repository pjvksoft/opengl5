#include <iostream>
#include <cstdlib>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <GL/glut.h>
#include "RgbImage.h"

#define PI 3.141592653 //.....
//map

float map[100][100];
float x,y,z;
float rx,ry,rz;
float spinx=0.0;
float spinz=0.0;
float hoekbeen=0.0;
float hoekarm1=0.0;
float hoekarm2=0.0;

float hoogte;
int r;
int geld;
//textures
#define FILEAANTAL 1
char* filenameh[FILEAANTAL]={"gras.bmp"};
GLuint*  textures;
char str[100];
float relief[100][100];


//*********************************************************
//*  world gelinkte matrix
//*********************************************************

void glutPrint(float xxx, float yyy, char* text, float rr, float gg, float bb, float aa)
{
    if(!text || !strlen(text)) return;
    bool blending = false;
    if(glIsEnabled(GL_BLEND)) blending = true;
    //glEnable(GL_BLEND);
    glColor4f(rr,gg,bb,aa);
    glRasterPos3f(xxx,yyy,0.0);
	glDisable(GL_TEXTURE_2D);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *text);
        text++;
    }
    if(!blending) glDisable(GL_BLEND);
} 


void loadTexture(int res,GLint param)
{    
	int i;

	//textures= (GLuint*)malloc(sizeof(GLuint)*2);

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	
	textures=(GLuint*) calloc(FILEAANTAL,sizeof(GLuint));
	glGenTextures(FILEAANTAL,textures);

	RgbImage theTexMap;
	
	for(i=0;i<FILEAANTAL;i++){
		glBindTexture(GL_TEXTURE_2D,textures[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		theTexMap.LoadBmpFile(filenameh[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3,theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
	}
}



void drawScene(void)
{
   int i,j,k,l,m,n,o,p;
   
   GLfloat light_pos1[] = { 20,0,0.0,1 };					//licht
      glEnable(GL_LIGHTING);
   //glLightfv(GL_LIGHT0,GL_POSITION, light_pos1);
	  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	  GLfloat light_position[] = { 1.0, 1.0, 1.0, 10.0 };
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


	  glEnable(GL_LIGHT0);
	  glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
	   glEnable ( GL_COLOR_MATERIAL ) ;
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
   	
    gluLookAt(x, y, z, x+cos(spinz/180.*PI)*cos(spinx/180.*PI), y+sin(spinz/180*PI)*cos(spinx/180.*PI), z-sin(spinx/180.*PI), 0, 0,1);

	//teken ondergrond
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[0] );
	glBegin(GL_QUADS);
	//glNormal3f(0.0,0.0,1.0);
	
	for(i=0;i<99;i++){
	for(j=0;j<99;j++){
	glTexCoord2f(0.0, 0.0);glVertex3f(10*i, 10*j, relief[i][j]);
	glTexCoord2f(0.0, 1.0);glVertex3f(10*i, 10*j+10, relief[i][j+1]);
	glTexCoord2f(1.0, 1.0);glVertex3f(10*i+10, 10*j+10, relief[i+1][j+1]);
	glTexCoord2f(1.0, 0.0);glVertex3f(10*i+10,10*j, relief[i+1][j]);
	}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glLoadIdentity();
    glTranslated(0,0,-1);
	sprintf(str,"(x=%f,y=%f,z=%f,spinx=%f,spinz=%f)",x,y,z,spinx,spinz);
	glutPrint(-1.0, 0.5, str, 1, 1, 1, 0);
   glutSwapBuffers();
}




void motion(int xm, int ym)
{
	float rx,ry,rz,f;
	spinz = -xm; 

	spinx = (ym-(768./2))/10.;
	printf("\n ym=%d,spinx=%f",ym,spinx);

	if(spinx>30.)
		spinx=30.;
	if(spinx<-30.)
		spinx=-30.;
    glutPostRedisplay();
}



void resizeWindow(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/h, 1, 1200); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0, 1, 0, 0, 0, 0,1);
	glClearColor(0, 1, 1, 1);


	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE, light_pos);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_NORMALIZE);
	//glEnable(GL_QUADRATIC_ATTENUATION);
	 //glShadeModel(GL_SMOOTH);
}


void keyboard(unsigned char key, int xx, int yy)
{
    char message[100];
	long answer;
	static int toggle = 0;
	int i,j,k,ij;
	printf("keyboard %c, x=%f y=%f sinz=%f",key,x,y,spinz);
    switch (key) {
    case 27:
		   exit(0);
    case ' ':

        break;
	case 'z':
		x=x+cos(spinz/180.*PI);
		y=y+sin(spinz/180.*PI);
        break;
	case 's':
		x=x-cos(spinz/180.*PI);
		y=y-sin(spinz/180.*PI);
        break;
	case 'd':
		x=x+sin(spinz/180.*PI);
		y=y-cos(spinz/180.*PI);
		r=3;
        break;
	case 'q':
		x=x-sin(spinz/180.*PI);
		y=y+cos(spinz/180.*PI);
		r=1;
        break;
	case 'c':
		printf("vrije knop c\n");
		
		
        break;
	case 'v':
		printf("vrije knop v\n");
		
        break;		
	case 'e':
		break;
	case 'r':
		spinx+=5.0;
        break;
    case 't':
		spinz+=5.0;
        break;
	case 'h':
		z++;
		break;
	case 'l':
		z--;
		break;
	}
    glutPostRedisplay();
}


void makerelief(){
int i,j,k;
for(i=0;i<100;i++){
	for(j=0;j<100;j++){
		relief[i][j]=(float) (rand()%100);
		if(i==0||j==0||i==99||j==99)
			relief[i][j]=100.;
	}
}
for(k=0;k<10;k++){
for(i=1;i<99;i++){
	for(j=1;j<99;j++){
		relief[i][j]=(4*relief[i][j]+relief[i+1][j]+relief[i-1][j]+relief[i][j+1]+relief[i][j-1])/8;
	}
}
}




}


void idle(void){
    glutPostRedisplay();
}



int main(int argc, char** argv){
	makerelief();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	loadTexture(0,0);
	x=0;y=0;z=100;
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
    //glutMouseFunc(mouse);
	//glutPassiveMotionFunc(motionpassief);
	//glutIdleFunc(idle);
	glutMainLoop();

	system("PAUSE");
}







