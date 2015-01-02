#include <iostream>
#include <cstdlib>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <GL/glut.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "glovar.h"
#include "RgbImage.h"
//#include "bst.h"	//vervangen door lijst.h
#include "lijst.h"
#include "objecten.h"

#define PI 3.141592653 //.....
#define FILEAANTAL 49
//map


float rx,ry,rz;
float spinx=0.0;
float spinz=0.0;
float spinz_beweeg=0.0;
float hoekbeen=0.0;
float hoekarm1=0.0;
float hoekarm2=0.0;
float hoogte;
int r;
int geld;
int toonzak=0;
world* aarde;
int toggel;
//textures
//#define FILEAANTAL 7
//char* filenameh[FILEAANTAL]={"gras.bmp","boom1.bmp","muur.bmp","goudh.bmp","ijzerh.bmp","platinh.bmp","koolh.bmp"};

FILE * pFile;


char str[100];




/***********************************************************/
/* functions
/***********************************************************/
#define FALSE 0
#define TRUE 1

typedef struct                                  // Create A Structure
{
    GLubyte *imageData;                         // Image Data (Up To 32 Bits)
    GLuint  bpp;                                // Image Color Depth In Bits Per Pixel.
    GLuint  width;                              // Image Width
    GLuint  height;                             // Image Height
    GLuint  texID;                              // Texture ID Used To Select A Texture
} TextureImage; 


void actierugzak(int i){
	if(i>=rugzak->zaklijst.size())return;	
	std::string naam;	
	naam=rugzak->zaklijst.at(i)->getnaam();
	if(naam.substr(0,4)=="fles"){//is fles
		fles* drank;
		drank=(fles*)rugzak->zaklijst.at(i);
		rugzak->gezondheid+=drank->level;
		if(rugzak->gezondheid>rugzak->maxgezondheid+rugzak->extramaxgezondheid())rugzak->gezondheid=rugzak->maxgezondheid+rugzak->extramaxgezondheid();
	}else{//geen fles drop op land;
		rugzak->zaklijst.at(i)->xobj=x;
		rugzak->zaklijst.at(i)->yobj=y;
		rugzak->zaklijst.at(i)->zobj=aarde->zfunction(x,y,z);
		aarde->insert(rugzak->zaklijst.at(i));
	}
		rugzak->zaklijst.erase(rugzak->zaklijst.begin()+i);
}


/*
int LoadTGA(char *filename, int tex){   
    GLubyte     TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};        // Uncompressed TGA Header default {0,0,2,0,0,0,0,0,0,0,0,0} maar gedecodeerd tga is 0 0 10 0 ...
    GLubyte     TGAcompare[12];                     // Used To Compare TGA Header
    GLubyte     header[6];                      // First 6 Useful Bytes From The Header
    GLuint      bytesPerPixel;                      // Holds Number Of Bytes Per Pixel Used In The TGA File
    GLuint      imageSize;                      // Used To Store The Image Size When Setting Aside Ram
    GLuint      temp;                           // Temporary Variable
    GLuint      type=GL_RGBA;                       // Set The Default GL Mode To RBGA (32 BPP)
	TextureImage temptexture;
	TextureImage *texture=&temptexture;
    FILE *file = fopen(filename, "rb");                 // Open The TGA File
 
    if( file==NULL ||                           // Does File Even Exist?
        fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) ||  // Are There 12 Bytes To Read?
        memcmp(TGAheader,TGAcompare,sizeof(TGAheader))!=0 ||        // Does The Header Match What We Want?
        fread(header,1,sizeof(header),file)!=sizeof(header))        // If So Read Next 6 Header Bytes
    {
        if (file == NULL)                       // Does The File Even Exist? *Added Jim Strong*
            return -1;                       // Return False
        else                                // Otherwise
        {
            fclose(file);                       // If Anything Failed, Close The File
            printf("\nheader %s\n",TGAcompare);
			return -2;                       // Return False
        }
    }
 
    texture->width  = header[1] * 256 + header[0];               // Determine The TGA Width  (highbyte*256+lowbyte)
    texture->height = header[3] * 256 + header[2];               // Determine The TGA Height (highbyte*256+lowbyte)
     
    if( texture->width   <=0 ||                       // Is The Width Less Than Or Equal To Zero
        texture->height  <=0 ||                       // Is The Height Less Than Or Equal To Zero
        (header[4]!=24 && header[4]!=32))               // Is The TGA 24 or 32 Bit?
    {
        fclose(file);                           // If Anything Failed, Close The File
        return -3;                           // Return False
    }
 
    texture->bpp = header[4];                        // Grab The TGA's Bits Per Pixel (24 or 32)
    bytesPerPixel   = texture->bpp/8;                    // Divide By 8 To Get The Bytes Per Pixel
    imageSize       = texture->width*texture->height*bytesPerPixel;   // Calculate The Memory Required For The TGA Data
 
    texture->imageData=(GLubyte *)malloc(imageSize);         // Reserve Memory To Hold The TGA Data
 
    if( texture->imageData==NULL ||                  // Does The Storage Memory Exist?
        fread(texture->imageData, 1, imageSize, file)!=imageSize)    // Does The Image Size Match The Memory Reserved?
    {
        if(texture->imageData!=NULL)                 // Was Image Data Loaded
            free(texture->imageData);                // If So, Release The Image Data
 
        fclose(file);                           // Close The File
        return -4;                           // Return False
    }
 
    for(GLuint i=0; i<int(imageSize); i+=bytesPerPixel)          // Loop Through The Image Data
    {                                   // Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
        temp=texture->imageData[i];                  // Temporarily Store The Value At Image Data 'i'
        texture->imageData[i] = texture->imageData[i + 2];        // Set The 1st Byte To The Value Of The 3rd Byte
        texture->imageData[i + 2] = temp;                // Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
    }
 
    fclose (file);                              // Close The File
 
    // Build A Texture From The Dat           
	glBindTexture(GL_TEXTURE_2D,textures[tex]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   // Linear Filtered
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   // Linear Filtered
     
    if (texture[0].bpp==24)                         // Was The TGA 24 Bits
    {
        type=GL_RGB;                            // If So Set The 'type' To GL_RGB
    }
 
    glTexImage2D(GL_TEXTURE_2D, 0, type, texture[0].width, texture[0].height, 0, type, GL_UNSIGNED_BYTE, texture[0].imageData);
 
    return 1;                                // Texture Building Went Ok, Return True
	
}
*/

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
		if(i==1){	//with alpha kanaal
			glBindTexture(GL_TEXTURE_2D,textures[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			theTexMap.LoadBmpFilealpha(filenameh[i]); 
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,GL_RGBA, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
		}else{
			glBindTexture(GL_TEXTURE_2D,textures[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			theTexMap.LoadBmpFile(filenameh[i]);
			glTexImage2D(GL_TEXTURE_2D, 0, 3,theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
		}
	}
	//printf("geslaagt TGA bestand %d",LoadTGA("joris.tga", 2));
}


time_t seconds;

void drawScene(void)
{
   int i,j,k,l,m,n,o,p,jj;
  
   	time_t ds;
	ds = time (NULL);
	ds=ds-seconds;
	seconds = time (NULL);

	x=x+xv*ds;
	y=y+yv*ds;

   GLfloat light_pos1[] = { 20,0,0.0,1 };					//licht
   //
   //glEnable(GL_LIGHTING);
   if(toggel)glEnable(GL_NORMALIZE);
   if(!toggel)glDisable(GL_NORMALIZE);
   //glLightfv(GL_LIGHT0,GL_POSITION, light_pos1);
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { -1.0, -1.0, -1.0, 10.0 };
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);		//heel de ruimte licht afhankelijk van kijkrichting
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHT0);
	
   
	glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
	glEnable ( GL_COLOR_MATERIAL ) ;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*

   
   glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	float ambientlight[]={1.0f,1.0f,1.0f,1.0f};

	float position[]={2.0f,3.0f,3.0f,1.0f};
	float direction[]={0.0f,0.0f,-1.0f};

	float matspecular[]={1.0f,1.0f,1.0f,1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambientlight);

	glLightfv(GL_LIGHT0, GL_POSITION, position);

	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 40.0f);
	//glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 30.0f);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);

	glEnable(GL_LIGHT0);
	
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, matspecular);
	glMaterialf(GL_FRONT, GL_SHININESS, 1.0f);
	*/
	//einde nieuw stuk test code lichting
	
	
	
	if(z>-5.0){
	glClearColor(0.8f,0.8f,0.8f,1.0f);
	GLfloat fogColor[4]= {0.8f, 0.8f, 0.8f, 1.0f}; 
	glFogi(GL_FOG_MODE, GL_EXP);        // Fog Mode:GL_EXP, GL_EXP2, GL_LINEAR
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.01f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, 100.0f);             // Fog Start Depth
	glFogf(GL_FOG_END, 200.0f);               // Fog End Depth
	//glEnable(GL_FOG);                   // Enables GL_FOG
	}else if(z>-100){//water
	glClearColor(0.1f,0.8f,0.8f,1.0f);
	GLfloat fogColor[4]= {0.1f, 0.8f, 0.8f, 1.0f}; 
	glFogi(GL_FOG_MODE, GL_EXP);        // Fog Mode:GL_EXP, GL_EXP2, GL_LINEAR
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.05f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, 100.0f);             // Fog Start Depth
	glFogf(GL_FOG_END, 200.0f);               // Fog End Depth
	glEnable(GL_FOG);                   // Enables GL_FOG
	}else{//ondergronds
	glClearColor(0.1f,0.1f,0.1f,1.0f);
	GLfloat fogColor[4]= {0.1f, 0.1f, 0.1f, 1.0f}; 
	glFogi(GL_FOG_MODE, GL_EXP);        // Fog Mode:GL_EXP, GL_EXP2, GL_LINEAR
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.04f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, 100.0f);             // Fog Start Depth
	glFogf(GL_FOG_END, 200.0f);               // Fog End Depth
	glEnable(GL_FOG);                   // Enables GL_FOG
	}

	
	glLoadIdentity();
   	float oogafstand=10.0;
    //gluLookAt(x, y, z, x+cos(spinz/180.*PI)*cos(spinx/180.*PI), y+sin(spinz/180*PI)*cos(spinx/180.*PI), z-sin(spinx/180.*PI), 0, 0,1);
	gluLookAt(x-oogafstand*cos(spinz/180.*PI)*cos(spinx/180.*PI), y-oogafstand*sin(spinz/180*PI)*cos(spinx/180.*PI), z+oogafstand*sin(spinx/180.*PI)+5.0,x, y, z+5.0, 0, 0,1);
	

	//teken ondergrond
	glEnable(GL_DEPTH_TEST);
	
	if(rugzak->gezondheid<=0){
		glColor4f(0,0,0,0);
	}



	/*
	object* obj = new rots(48.0,205.0,4);
	obj->draw();
	obj =new muurblok(200.0,200.0);
	obj->draw();
	*/

	//muurblok kas=muurblok(200.0,200.0);
	//kas.draw();
	//meteor met=meteor(500.0,500.0);
	//met.draw();
	//rots goldmijn=rots(50.0,200.0,3);
	//goldmijn.draw();
	//goldmijn=rots(48.0,205.0,4);
	//goldmijn.draw();

	

	aarde->drawgrond(x,y);
	aarde->drawobjecten(x,y);
	/*
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
	*/
	/*************************************man tekenen**************************/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[5] );
	//glEnable( GL_BLEND );
	//glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_SRC_COLOR);
	//glLoadIdentity();
	//glTranslated(x,y,z);
#define MAG 5.0	
	//glTranslated(x+MAG/2,y+MAG/2,z-5.0);
	glTranslated(x,y,z);
glRotatef(spinz+180, 0, 0, 1);
	hoekbeen=hoekbeen+0.1;
	hoekarm1=0.5*sin(hoekbeen);
	hoekarm2=-0.2*sin(hoekbeen);
	glBindTexture(GL_TEXTURE_2D,textures[12] );
	//been1

	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4+MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025-MAG*0.025*cos(hoekbeen));
		 //been2
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.5-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-MAG*0.2*sin(hoekbeen)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.025+MAG*0.025*cos(hoekbeen));

	glEnd();

	//buik
	glBindTexture(GL_TEXTURE_2D,textures[11] );		//waldo truitje
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.3);
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.3);

		 //armen boven ook trui textures
		  glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);

		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);

	glEnd();

	//arm rechts
	glBindTexture(GL_TEXTURE_2D,textures[18] );		
	glBegin(GL_QUADS);
		

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm2)-0.5*MAG, MAG*0.3-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm2));

	glEnd();

	//arm links
	glBindTexture(GL_TEXTURE_2D,textures[18] );		
	glBegin(GL_QUADS);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.7-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.55+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.55-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.45-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.45+MAG*0.3*sin(hoekarm1)-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.6-MAG*0.3*cos(hoekarm1));

	glEnd();

	//hoofd
	glBindTexture(GL_TEXTURE_2D,textures[17] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[13] );
	glBegin(GL_QUADS);
		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[15] );
	glBegin(GL_QUADS);
		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[16] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[14] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.4-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.6);

	glEnd();
	//auto
	//$$$$$$$$$$$$$$$$$$$ speciaal voor toon
	jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		if(rugzak->zaklijst.at(i)->getnaam()=="Bugatti Veyron") jj=1;
	}
	if(jj){
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(+10, +5, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(+10, +5, +2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(-10, +5, +2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(-10, +5, 0);

		glTexCoord2f(0.0, 0.0);glVertex3f(+10, -5, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(+10, -5, +2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(-10, -5, +2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(-10, -5, 0);

		glTexCoord2f(0.0, 0.0);glVertex3f(+10, +5, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(+10, +5, +2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(+10, -5, +2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(+10, -5, 0);

		glTexCoord2f(0.0, 0.0);glVertex3f(-10, -5, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(-10, -5, +2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(-10, +5, +2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(-10, +5, 0);

		glTexCoord2f(0.0, 0.0);glVertex3f(-10, -5, +2.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(-10, +5, +2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(+10, +5, +2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(+10, -5, +2.5);

	glEnd();
	}
	//$$$$$$$$$$$$$$
	//zwaard
	jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string str1 = rugzak->zaklijst.at(i)->getnaam();
		if(str1.compare("zwaard")==0) jj=1;
	}
	if(jj){
	glBindTexture(GL_TEXTURE_2D,textures[19]);
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.17*cos(hoekarm1)+MAG*0.3*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, MAG*0.17*sin(hoekarm1)-MAG*0.3*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.17*cos(hoekarm1)+MAG*0.25*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, MAG*0.17*sin(hoekarm1)-MAG*0.25*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.25*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.25*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.3*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.3*cos(hoekarm1)+MAG*0.6);
	glEnd();
	}
	//houweel
	jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string str1 = rugzak->zaklijst.at(i)->getnaam();
		if(str1.compare("houweel")==0) jj=1;
	}
	if(jj){
	glBindTexture(GL_TEXTURE_2D,textures[21]);
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.17*cos(hoekarm1)+MAG*0.3*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, MAG*0.17*sin(hoekarm1)-MAG*0.3*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.17*cos(hoekarm1)+MAG*0.25*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, MAG*0.17*sin(hoekarm1)-MAG*0.25*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.25*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.25*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.3*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.3*cos(hoekarm1)+MAG*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[29]);
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.5*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.5*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(-MAG*0.35*cos(hoekarm1)+MAG*0.1*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.35*sin(hoekarm1)-MAG*0.1*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(-MAG*0.40*cos(hoekarm1)+MAG*0.1*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.40*sin(hoekarm1)-MAG*0.1*cos(hoekarm1)+MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(-MAG*0.40*cos(hoekarm1)+MAG*0.5*sin(hoekarm1)+MAG*0.45-0.5*MAG, MAG*0.75-0.5*MAG, -MAG*0.40*sin(hoekarm1)-MAG*0.5*cos(hoekarm1)+MAG*0.6);
	glEnd();

	}

	//mantel
	jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string naam;
		naam=rugzak->zaklijst.at(i)->getnaam();
		if(naam.substr(0,6)=="mantel"){ 
			mantel* cape;
			cape=(mantel*)rugzak->zaklijst.at(i);
			jj=1;
			i=cape->tex;
			break;
		}
	}
	if(jj){
	glBindTexture(GL_TEXTURE_2D,textures[i] );
	glBegin(GL_QUADS);
		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(MAG*0.7-0.5*MAG, MAG*0.2-0.5*MAG, MAG*0.1);
		 glTexCoord2f(0.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.4-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(MAG*0.6-0.5*MAG, MAG*0.6-0.5*MAG, MAG*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(MAG*0.7-0.5*MAG, MAG*0.8-0.5*MAG, MAG*0.1);
	glEnd();
	}

	glDisable(GL_TEXTURE_2D);

	//**********************************print text**************/
	glLoadIdentity();
    glTranslated(0,0,-1);
	sprintf(str,"gezondheid %d/%d",rugzak->gezondheid,rugzak->maxgezondheid);
	glutPrint(-1.0, 0.4, str, (1-((float)rugzak->gezondheid/rugzak->maxgezondheid)),  ((float)rugzak->gezondheid/rugzak->maxgezondheid), 0, 0);
	sprintf(str,"(x=%f,y=%f,z=%f,spinx=%f,spinz=%f,landpointer=%p)",x,y,z,spinx,spinz,aarde->temp);
	glutPrint(-1.0, 0.5, str, 1, 1, 1, 0);
	//**********************************menu rugzak*****************/
	glLoadIdentity();
    glTranslated(0,0,-1);
	

	if(toonzak==1){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[26] );
	glBegin(GL_QUADS);
		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(-1.0,-1.0,-1.0);
		 glTexCoord2f(0.0, 1.0);glVertex3f(-1.0,1.0,-1.0);
		 glTexCoord2f(1.0, 1.0);glVertex3f(1.0,1.0,-1.0);
		 glTexCoord2f(1.0, 0.0);glVertex3f(1.0,-1.0,-1.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	sprintf(str,"rugzak       geld=%d  gezondheid=%d/%d+%d",rugzak->geld,rugzak->gezondheid,rugzak->maxgezondheid,rugzak->extramaxgezondheid());
	glutPrint(-0.45, 0.45, str, 1, 1, 1, 0);
	sprintf(str,"power=%d     vechtxp=%d   aanval=%d+%d",rugzak->power,rugzak->vechtxp,rugzak->vechtlevel(),rugzak->extravechtlevel());
	glutPrint(-0.45, 0.40, str, 1, 1, 1, 0);
	sprintf(str,"gerbuiken of laten vallen toets het nummer 1,2,..");
	glutPrint(-0.45, 0.35, str, 1, 1, 1, 0);
	for(i=0;i<rugzak->zaklijst.size();i++){
		//sprintf(str,"%p",rugzak->zaklijst.at(i));
		sprintf(str,"%d) %s",i,rugzak->zaklijst.at(i)->getnaam());
		glutPrint(-0.40, 0.30-i*0.05, str, 1, 1, 1, 0);
	}
	}//end toon zak

   glutSwapBuffers();
}




void motion(int xm, int ym)
{
	//float rx,ry,rz,f;
	spinz = -xm; 

	spinx = (ym-(768./2))/10.;
	//printf("\n ym=%d,spinx=%f",ym,spinx);
	printf("\n%d,%d",xm,ym);
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
	 glShadeModel(GL_SMOOTH);
}


void keyboard(unsigned char key, int xx, int yy)
{
    char message[100];
	long answer;
	static int toggle = 0;
	int i,j,k,ij,jj;
	float xnieuw,ynieuw,znieuw;
	xnieuw=x;
	ynieuw=y;
	znieuw=z;
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$auto besturing
	jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		if(rugzak->zaklijst.at(i)->getnaam()=="Bugatti Veyron") jj=1;
	}
	if(jj){
	switch (key) {
	case 'z':
		xv+=cos(spinz/180.*PI);
		yv+=sin(spinz/180.*PI);
        break;
	case 's':
		xv+=cos(spinz/180.*PI);
		yv+=sin(spinz/180.*PI);
        break;
	case 'd':
		xv+=sin(spinz/180.*PI);
		yv+=cos(spinz/180.*PI);
        break;
	case 'q':
		xv+=sin(spinz/180.*PI);
		yv+=cos(spinz/180.*PI);
        break;
	case ' ':
		xv=xv/2.0;
		yv=yv/2.0;
        break;
	}
	return;
	}
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$auto besturing end
	//printf("keyboard %c, x=%f y=%f sinz=%f",key,x,y,spinz);
    switch (key) {
    case 27:
		   exit(0);
    case ' ':
		printf("\n actie knop");
		aarde->actie(x,y,0);
        break;
	case 'w':
		xnieuw=xnieuw+cos(spinz/180.*PI);
		ynieuw=ynieuw+sin(spinz/180.*PI);
		spinz_beweeg=spinz;
        break;
	case 's':
		xnieuw=xnieuw-cos(spinz/180.*PI);
		ynieuw=ynieuw-sin(spinz/180.*PI);
		spinz_beweeg=spinz;
        break;
	case 'd':
		xnieuw=xnieuw+sin(spinz/180.*PI);
		ynieuw=ynieuw-cos(spinz/180.*PI);
		spinz_beweeg=spinz;
		r=3;
        break;
	case 'a':
		xnieuw=xnieuw-sin(spinz/180.*PI);
		ynieuw=ynieuw+cos(spinz/180.*PI);
		spinz_beweeg=spinz;
		r=1;
        break;
	case 'c':
		printf("vrije knop c toggel=%d\n",toggel);
		toggel=1-toggel;
        break;
	case 'v':
		printf("vrije knop v\n");
		printf("coordinaten=%f;%f;z=%f;zfunction=%f\n",x,y,z,aarde->zfunction(x,y,z));
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
	case 'i':
		printf("\n toon inventorie");
		toonzak=1-toonzak;
		break;
	case 'o':
		printf("\n opslaan");
		pFile = fopen ("save.txt","w");

		    fprintf(pFile,"%f\n",x);
		    fprintf(pFile,"%f\n",y);
		    fprintf(pFile,"%f\n",z);
		    fprintf(pFile,"%d\n",geld);
		    fprintf(pFile,"%d\n",rugzak->gezondheid);
		    fprintf(pFile,"%d\n",rugzak->maxgezondheid);
		    fprintf(pFile,"%d\n",rugzak->maxzak);
		    fprintf(pFile,"%d\n",rugzak->power);
		    fprintf(pFile,"%d\n",rugzak->vechtxp);
		    for(i=0;i<rugzak->zaklijst.size();i++){
		    	fprintf(pFile,"%s\n",rugzak->zaklijst.at(i)->getnaam());
		    }

		    fclose (pFile);


		break;
	case 'p':
		printf("\n laden");
		pFile = fopen ("save.txt","r");
			fscanf (pFile, "%f\n", &xnieuw);
			fscanf (pFile, "%f\n", &ynieuw);
			fscanf (pFile, "%f\n", &z);
			fscanf (pFile, "%d\n", &geld);
			fscanf(pFile,"%d\n",&rugzak->gezondheid);
			fscanf(pFile,"%d\n",&rugzak->maxgezondheid);
			fscanf(pFile,"%d\n",&rugzak->maxzak);
			fscanf(pFile,"%d\n",&rugzak->power);
			fscanf(pFile,"%d\n",&rugzak->vechtxp);

		    fclose (pFile);
		break;
	case 38:
	case 49:
		if(toonzak){
			actierugzak(1);
		}else{
		aarde->actie(x,y,1);
		}
		break;
	case 233:
	case 50:
		if(toonzak){
			actierugzak(2);
		}else{
		aarde->actie(x,y,2);
		}
		break;
	case 34:
	case 51:
		if(toonzak){
			actierugzak(3);
		}else{
		aarde->actie(x,y,3);
		}
		break;
	case 39:
	case 52:
		if(toonzak){
			actierugzak(4);
		}else{
		aarde->actie(x,y,4);
		}
		break;
	case 40:
	case 53:
		if(toonzak){
			actierugzak(5);
		}else{
		aarde->actie(x,y,5);
		}
		break;
	case 167:
	case 54:
		if(toonzak){
			actierugzak(6);
		}else{
		aarde->actie(x,y,6);
		}
		break;
	case 232:
	case 55:
		if(toonzak){
			actierugzak(7);
		}else{
		aarde->actie(x,y,7);
		}
		break;
	case 33:
	case 56:
		if(toonzak){
			actierugzak(8);
		}else{
		aarde->actie(x,y,8);
		}
		break;
	case 231:
	case 57:
		if(toonzak){
			actierugzak(9);
		}else{
		aarde->actie(x,y,9);
		}
		break;
	case 224:
	case 48:
		if(toonzak){
			actierugzak(0);
		}else{
		aarde->actie(x,y,0);
		}
		break;
	}
	printf("\n %d",key);
	float debug=aarde->zfunction(xnieuw,ynieuw,z);
	if(z+5>aarde->zfunction(xnieuw,ynieuw,debug)&&!teleport){
		printf("\nlucht coordinaten=%f;%f;z=%f;zfunction=%f\n",x,y,z,aarde->zfunction(xnieuw,ynieuw,z));
		z=aarde->zfunction(xnieuw,ynieuw,z);
		x=xnieuw;
		y=ynieuw;
		printf("\nlucht2 coordinaten=%f;%f;z=%f;zfunction=%f\n",x,y,z,aarde->zfunction(xnieuw,ynieuw,z));
		}else{
		printf("\nmuur coordinaten=%f;%f;z=%f;zfunction=%f\n",x,y,z,aarde->zfunction(xnieuw,ynieuw,z));

		//pech je kan er niet op
	}
	teleport=0;
	
	/*
	float dx,dy;
	dx=(x-((int)x/10*10))/10.0;
	dy=(y-((int)y/10*10))/10.0;
	//printf("\n\n %f,%f \n",dx,dy);
	//z=(1.0-(y-((int)y/10*10)))*((x-((int)x/10*10)*relief[(int)(x/10)+1][(int)(y/10)]+(1.0-(x-((int)x/10*10)))*relief[(int)(x/10)][(int)(y/10)]))+(y-((int)y/10*10))*((x-((int)x/10*10)*relief[(int)(x/10)+1][(int)(y/10)+1]+(1.0-(x-((int)x/10*10)))*relief[(int)(x/10)][(int)(y/10)+1]));
	//goed-\>
	z=(1.0-dy)*(dx*relief[(int)(x/10)+1][(int)(y/10)]+(1.0-dx)*relief[(int)(x/10)][(int)(y/10)])+dy*(dx*relief[(int)(x/10)+1][(int)(y/10)+1]+(1.0-dx)*relief[(int)(x/10)][(int)(y/10)+1])+5.0;
    z=5;
	*/
	
	//z=aarde->zfunction(x,y,z);
	
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

void gameboy(int button, int state){
	printf("button=%d, state=%d\n",button,state);
}

void joystick(unsigned int buttonMask, int x, int y, int z){
printf("buttonMask=%d, x=%d, y=%d, z=%d\n",buttonMask,x,y,z);
}

int main(int argc, char** argv){
	aarde =  new world();
	aarde->makeworld();
	xv=0;yv=0;
	teleport=0;
	toggel=0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	loadTexture(0,0);
	x=50;y=50;z=100;
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);

	//test baxie li
	glutButtonBoxFunc(gameboy);
	glutJoystickFunc(joystick, 0);
	//glutJoystickFunc(void (GLUTCALLBACK *func)(unsigned int buttonMask, int x, int y, int z), int pollInterval);
    //glutMouseFunc(mouse);
	//glutPassiveMotionFunc(motionpassief);
	//glutIdleFunc(idle);
	glutMainLoop();

	system("PAUSE");
}
