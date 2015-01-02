//*********************************************************
//*  objecten
//*********************************************************
#include <iostream>
#include <GL/glut.h>
#include <time.h>
#include "objecten.h"
#include "lijst.h"
#include "math.h"
#include <string.h>
#include <stdio.h>
#define PI 3.141592653 //.....
#define ROT(x,y,a,b,hoek) ( x + a *cos( hoek ) - b *sin( hoek )) , ( y + a *sin( hoek )+ b *cos( hoek ))
//#define ROT(x,y,a,b,hoek) x+a,y+b
//#include "glovar.h"
char strtemp[500];
char strtempp[500];

extern char* filenameh[FILEAANTAL];
extern float relief[100][100];
extern GLuint*  textures;
extern float x,y,z,xv,yv;
extern int keyoud,teleport;
zak* rugzak=new zak();

void glutPrint(float xxx, float yyy, char* text, float rr, float gg, float bb, float aa){
	float color[4];
	glGetFloatv(GL_CURRENT_COLOR, color);
	glDisable(GL_LIGHTING);
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
	glEnable(GL_LIGHTING);
	glColor4fv(color);
} 


float object::zfunction(float xx,float yy,float zz){
	printf("\noproepen van object zfunction,fout");
	return -1.0;
}
void object::draw(){
	printf("\noproepen object, fout");
}

int object::actie(zak* koffer,land* temp,int act){
	printf("\noproepen actie object, fout");
	return -2;
}
//object::naam="object";
char* object::getnaam(){
	return "object";
}

int object::getprijs(){
	return -1;
}

brughout::brughout(float xx,float yy,float zz){
	xobj=xx;yobj=yy;zobj= zz;hoogteblok=0.5;
	open=false;
}
char* brughout::getnaam(){
	return "brughout";
}

int brughout::getprijs(){
	return -1;
}
float brughout::zfunction(float xx,float yy,float zz){
if(open==true){
	if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
		if(zz>zobj-2){
			return zobj+hoogteblok;
		}else{
			return MINHEIGHT;
		}
	}else{
		return MINHEIGHT;
	}
}else{
	if(xx>xobj+10 && xx<xobj+12 && yy>yobj-10 && yy<yobj+10){
		return zobj+20.0;
	}else{
		return MINHEIGHT;
	}

}
}

int brughout::actie(zak* koffer,land* temp,int act){
if(x>xobj+10 && x<xobj+20 && y>yobj-10 && y<yobj+10){
	open=!open;
	return 1;
}else{
	return -1;
}
}

void brughout::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	if(open==true){
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
	glEnd();
	}else{
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10+hoogteblok, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10+hoogteblok, yobj+10, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10+hoogteblok, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10+hoogteblok, yobj-10, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10+hoogteblok, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10+hoogteblok, yobj+10, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10+hoogteblok, yobj-10, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10+hoogteblok, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10+hoogteblok, yobj+10, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10+hoogteblok, yobj-10, zobj+20);
	glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


trap::trap(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	zobj= zz;
}
char* trap::getnaam(){
	return "helling";
}
int trap::getprijs(){
	return -1;
}
float trap::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return ((x-(xobj-10))/20.0*hoogteblok)+zobj;
}else{
	return MINHEIGHT;
}
}

int trap::actie(zak* koffer,land* temp,int act){
	return -1;
}


void trap::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		//driehoek
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);
		//driehoek
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);


		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


toren::toren(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=13;
	zobj= zz;
}
char* toren::getnaam(){
	return "toren";
}
int toren::getprijs(){
	return 1;
}
float toren::zfunction(float xx,float yy,float zz){
if(xx>xobj-12 && xx<xobj+12 && yy>yobj-12 && yy<yobj+12){
	if(zz>zobj-2){
		return zobj+hoogteblok;
	}else{
		return MINHEIGHT;
	}
}else{
	return MINHEIGHT;
}
}

int toren::actie(zak* koffer,land* temp,int act){
	return -1;
}

void toren::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+12, yobj+12, zobj-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-12, yobj+12, zobj-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+12, yobj-12, zobj-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+12, yobj-12, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-12, yobj-12, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-12, yobj-12, zobj-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+12, yobj+12, zobj-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+12, yobj-12, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+12, yobj-12, zobj-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-12, yobj-12, zobj-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-12, yobj-12, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-12, yobj+12, zobj-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-12, yobj-12, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+12, yobj+12, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+12, yobj-12, zobj+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

boomblok::boomblok(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* boomblok::getnaam(){
	return "boomblok";
}
int boomblok::getprijs(){
	return -1;
}
float boomblok::zfunction(float xx,float yy,float zz){
if(xx>xobj-4 && xx<xobj+4 && yy>yobj-4 && yy<yobj+4){
	return zobj+hoogteblok*3;
}else{
	return MINHEIGHT;
}
}

int boomblok::actie(zak* koffer,land* temp,int act){
	return -1;
}

void boomblok::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[22] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+3, yobj+3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-3, yobj+3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+3, yobj-3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+3, yobj-3, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-3, yobj-3, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-3, yobj-3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+3, yobj+3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+3, yobj-3, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+3, yobj-3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj-3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-3, yobj-3, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-3, yobj+3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj-3, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+3, yobj+3, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+3, yobj-3, zobj+hoogteblok);

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[23] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok*3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok*3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


winkel::winkel(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
	toon=0;
	soort=0;
}
winkel::winkel(float xx,float yy,float zz,int soortt){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
	toon=0;
	soort=soortt;
	// soort 0 = verkoop
	// 1 = algemeen koop
	// 2 = wapens koop
	// 3 = magic koop
}
char* winkel::getnaam(){
	return "winkel";
}
int winkel::getprijs(){
	return -1;
}
float winkel::zfunction(float xx,float yy,float zz){
if((xx>xobj-20 && xx<xobj+20 && yy>yobj-20 && yy<yobj+20)&&!(xx>xobj-18 && xx<xobj+18 && yy>yobj-18 && yy<yobj+18)&&!(xx>xobj-3 && xx<xobj+3 && yy>yobj+10 && yy<yobj+20)){
	return zobj+hoogteblok;
}else if(xx>xobj-20 && xx<xobj+20 && yy>yobj-14 && yy<yobj-10){
	return zobj+3.0;
}else if(xx>xobj-20 && xx<xobj+20 && yy>yobj-20 && yy<yobj+20){
	return zobj+0.1;
}else{
	return MINHEIGHT;
}
}

int winkel::actie(zak* koffer,land* temp,int act){
	if(act==0){
		toon=1-toon;
		return 1;
	}else{
		if(soort==0){
			if(act<=koffer->zaklijst.size()&&act>0){
				koffer->geld=koffer->geld+koffer->zaklijst.at(act-1)->getprijs();
				koffer->zaklijst.erase(koffer->zaklijst.begin()+(act-1));
			}
		}
		if(soort==2){
			if(act==1){
				if(rugzak->geld>=10 && rugzak->zaklijst.size()< rugzak->maxzak){
					rugzak->geld=rugzak->geld-10;
					rugzak->insertzak(new zwaard(0,0));
				}
			}
		}
	}
	return -1;
}

void winkel::draw(){
	int i;
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[24] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20, yobj+20, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+3, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+3, yobj+20, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj+20, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-3, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-20, yobj+20, zobj);


		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20, yobj-20, zobj);
		glTexCoord2f(0.0, 2.0);glVertex3f(xobj+20, yobj-20, zobj+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xobj-20, yobj-20, zobj+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-20, yobj-20, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20, yobj+20, zobj);
		glTexCoord2f(0.0, 2.0);glVertex3f(xobj+20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xobj+20, yobj-20, zobj+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+20, yobj-20, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-20, zobj);
		glTexCoord2f(0.0, 2.0);glVertex3f(xobj-20, yobj-20, zobj+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xobj-20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-20, yobj+20, zobj);
		//boven dak zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+20, yobj, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+20, yobj, zobj+hoogteblok*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+20, yobj-20, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj+20, zobj+hoogteblok);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj-20, yobj, zobj+hoogteblok*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj-20, yobj, zobj+hoogteblok*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-20, yobj-20, zobj+hoogteblok);
		//vloer

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-20, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj+20, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+20, yobj+20, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+20, yobj-20, zobj+0.1);
	glEnd();
	// kasten
	glBindTexture(GL_TEXTURE_2D,textures[31] );
	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+18, yobj-18, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+18, yobj-18, zobj+hoogteblok-2);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj-18, yobj-18, zobj+hoogteblok-2);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-18, yobj-18, zobj);
	glEnd();
	//toon bank

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj-10, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+20, yobj-10, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+20, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-10, zobj+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj-14, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+20, yobj-14, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+20, yobj-10, zobj+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-14, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj-14, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+20, yobj-14, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+20, yobj-14, zobj);



	glEnd();

	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+22, yobj+22, zobj+hoogteblok-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+22, yobj, zobj+hoogteblok*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-22, yobj, zobj+hoogteblok*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-22, yobj+22, zobj+hoogteblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+22, yobj-22, zobj+hoogteblok-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+22, yobj, zobj+hoogteblok*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-22, yobj, zobj+hoogteblok*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-22, yobj-22, zobj+hoogteblok-2);
		

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//toon aankoop papier
		if(toon){
		glPushMatrix(); 
		glLoadIdentity();
		glTranslated(0,0,-1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[26] );
		glBegin(GL_QUADS);
			 glTexCoord2f(0.0, 0.0);glVertex3f(-1.0,-1.0,-1.0);
			 glTexCoord2f(0.0, 1.0);glVertex3f(-1.0,1.0,-1.0);
				 glTexCoord2f(1.0, 1.0);glVertex3f(1.0,1.0,-1.0);
			 glTexCoord2f(1.0, 0.0);glVertex3f(1.0,-1.0,-1.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		if(soort==0){
			sprintf(strtemp,"verkoop winkel geld %d coins",rugzak->geld);
			glutPrint(-0.45, 0.45, strtemp, 1, 1, 1, 0);
			for(i=0;i<rugzak->zaklijst.size();i++){
				sprintf(strtemp,"%d) %s %d coins",i+1,rugzak->zaklijst.at(i)->getnaam(),rugzak->zaklijst.at(i)->getprijs());
				glutPrint(-0.45, 0.40-0.05*i, strtemp, 1, 1, 1, 0);
			}
		}
		if(soort==1){
			sprintf(strtemp,"algemeen winkel geld %d coins",rugzak->geld);
			glutPrint(-0.45, 0.45, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"1) hout 3 coins");
			glutPrint(-0.45, 0.40, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"2) bronzen bijl 30 coins");
			glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"3) appel 10 coins");
			glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
		}
		if(soort==2){
			sprintf(strtemp,"wapen winkel geld %d coins",rugzak->geld);
			glutPrint(-0.45, 0.45, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"1) zwaard 10 coins");
			glutPrint(-0.45, 0.40, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"2) 2-hands zwaard 100 coins");
			glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
		}
		glPopMatrix();
		}
			/*
			glDisable(GL_TEXTURE_2D);
			sprintf(str,"rugzak");
			glutPrint(-0.45, 0.45, str, 1, 1, 1, 0);
			for(i=0;i<rugzak->zaklijst.size();i++){
				//sprintf(str,"%p",rugzak->zaklijst.at(i));
				sprintf(str,"%s",rugzak->zaklijst.at(i)->getnaam());
				glutPrint(-0.40, 0.35-i*0.1, str, 1, 1, 1, 0);
			}
			*/


	glDisable(GL_BLEND);
}


muurblok::muurblok(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* muurblok::getnaam(){
	return "muur";
}
int muurblok::getprijs(){
	return -1;
}
float muurblok::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int muurblok::actie(zak* koffer,land* temp,int act){
	return -1;
}


void muurblok::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}



muurx::muurx(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* muurx::getnaam(){
	return "muurx";
}
int muurx::getprijs(){
	return -1;
}
float muurx::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int muurx::actie(zak* koffer,land* temp,int act){
	return -1;
}

void muurx::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		
		//lange kanteel boven
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+8, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+8, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj+8, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj+8, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj+8, zobj+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj+8, zobj+hoogteblok+2);

		//lange kanteel onder (2d vlak)
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-8, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-8, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-8, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-8, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-8, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-8, zobj+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-8, zobj+hoogteblok+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

muury::muury(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* muury::getnaam(){
	return "muury";
}
int muury::getprijs(){
	return -1;
}
float muury::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int muury::actie(zak* koffer,land* temp,int act){
	return -1;
}

void muury::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		
		//lange kanteel boven
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+8, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+8, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj+10, zobj+hoogteblok+2);

		//lange kanteel
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-8, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-8, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj+10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj+10, zobj+hoogteblok+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}




kasteel::kasteel(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=20;
	
	zobj= zz;
}

char* kasteel::getnaam(){
	return "kasteel";
}
int kasteel::getprijs(){
	return -1;
}

int kasteel::actie(zak* koffer,land* temp,int act){
	return -1;
}

void kasteel::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[2] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-10, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+10, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-10, zobj+hoogteblok);


	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}
float kasteel::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}


kerk::kerk(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=20;
	
	zobj= zz;
}

char* kerk::getnaam(){
	return "kerk";
}
int kerk::getprijs(){
	return -1;
}

int kerk::actie(zak* koffer,land* temp,int act){
	return -1;
}

void kerk::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[27] );
	glBegin(GL_QUADS);

	//voorgevel
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+15, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+15, zobj+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+10, yobj+5, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj);
		glTexCoord2f(0.0, 2.0);glVertex3f(xobj+10, yobj-5, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-15, zobj+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-15, zobj);
	//achterkant
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj+15, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj+15, zobj+10);
		glTexCoord2f(3.0, 1.0);glVertex3f(xobj-30, yobj-15, zobj+10);
		glTexCoord2f(3.0, 0.0);glVertex3f(xobj-30, yobj-15, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj+15, zobj+10);
		glTexCoord2f(1.5, 1.5);glVertex3f(xobj-30, yobj, zobj+25);
		glTexCoord2f(1.5, 1.5);glVertex3f(xobj-30, yobj, zobj+25);
		glTexCoord2f(3.0, 0.0);glVertex3f(xobj-30, yobj-15, zobj+10);


		//toren
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj+10);
		glTexCoord2f(0.0, 2.0);glVertex3f(xobj+10, yobj+5, zobj+30);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+10, yobj-5, zobj+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+10);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-5, zobj+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj-5, zobj+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-5, zobj+20);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj+5, zobj+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj+5, zobj+20);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj-5, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj, yobj-5, zobj+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj+5, zobj+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj+5, zobj+20);
		//zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-15, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-15, zobj+10);
		glTexCoord2f(4.0, 1.0);glVertex3f(xobj-30, yobj-15, zobj+10);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-30, yobj-15, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+15, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+15, zobj+10);
		glTexCoord2f(4.0, 1.0);glVertex3f(xobj-30, yobj+15, zobj+10);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-30, yobj+15, zobj);
	glEnd();
	//vloer
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj-15, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj+15, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+15, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-15, zobj+0.1);

	//altaar
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-23, yobj-3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-23, yobj-3, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj-3, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-20, yobj-3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-23, yobj+3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-23, yobj+3, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj+3, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-20, yobj+3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-23, yobj+3, zobj+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-23, yobj-3, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj-3, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-20, yobj+3, zobj+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj-3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj-3, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj+3, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-20, yobj+3, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-23, yobj-3, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-23, yobj-3, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-23, yobj+3, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-23, yobj+3, zobj);
	glEnd();
	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+12, yobj+17, zobj+8);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+12, yobj, zobj+25);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-32, yobj, zobj+25);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-32, yobj+17, zobj+8);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+12, yobj-17, zobj+8);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+12, yobj, zobj+25);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-32, yobj, zobj+25);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-32, yobj-17, zobj+8);
		//toren
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+11, yobj+6, zobj+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-1, yobj+6, zobj+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+11, yobj-6, zobj+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-1, yobj-6, zobj+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+11, yobj+6, zobj+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+11, yobj-6, zobj+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+6, zobj+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+5, yobj, zobj+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-1, yobj-6, zobj+28);



	glEnd();
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);

}
float kerk::zfunction(float xx,float yy,float zz){
float a; 
if(xx>xobj-30 && xx<xobj+10 && yy>yobj-15 && yy<yobj+15){
	a=zobj+10;//blokkeer alles;
	if(xx>xobj-28 && xx<xobj+8 && yy>yobj-13 && yy<yobj+13)
		a=zobj;//binnen;
	if(xx>xobj+8 && xx<xobj+12 && yy>yobj-5 && yy<yobj+5)
		a=zobj;//deur;
	if(xx>xobj-23 && xx<xobj-20 && yy>yobj-3 && yy<yobj+3)
		a=zobj+3;
	return a;
}else{
	return MINHEIGHT;
}
}



rots::rots(float xx,float yy,float zz,int tt){
	xobj=xx;yobj=yy;hoogteblok=5;
	
	zobj= zz;
	tex=tt;
	mining=0;
}
char* rots::getnaam(){
		switch (tex){
		case 6:
			return "rots kool";
		case 7:
			return "rots ijzer";
		case 8:
			return "rots goud";
		case 9:
			return "rots platina";
		case 20:
			return "rots steen";
		case 10:
			return "rots diamand";
		default:
			return "rots erts";
	}
	return "rots";
}

int rots::getprijs(){
	return -1;
}

int rots::actie(zak* koffer,land* temp,int act){
	int i;
	int jj=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		if(rugzak->zaklijst.at(i)->getnaam()=="houweel") jj=1;
	}
	if(jj){
	if(100>(((int)rand())%1000)){
	printf("\n neem erts <----------------------");
	mining=5;
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(new erts(0,0,tex));
		return 1;
	}
	}
	return 1;
	}
	return -1;
}

void rots::draw(){

    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[tex] );
	glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2.5, yobj+4.33, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj, zobj-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-4.33, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2.5, yobj+4.33, zobj-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj+4.33, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2.5, yobj-4.33, zobj-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-4.33, zobj);

	glEnd();
	if(mining!=0){
		int texx;
		texx=tex;
		if(tex==10)texx=30;
		float xblok=xobj;float yblok=yobj;float zblok=zobj;
		zblok=zblok+8-mining;
		glBindTexture(GL_TEXTURE_2D,textures[texx] );
		glBegin(GL_QUADS);
	//onderkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok+0.81, zblok+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+0.707, yblok+0.40, zblok+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+0.707, yblok-0.40, zblok+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok+0.81, zblok+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-0.707, yblok+0.40, zblok+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-0.707, yblok-0.40, zblok+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+0.707, yblok-0.40, zblok+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok-0.81, zblok+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-0.707, yblok-0.40, zblok+0.57);
	//bovenkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-0.81, zblok+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+0.707, yblok-0.40, zblok+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+0.707, yblok+0.40, zblok+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-0.81, zblok+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-0.707, yblok-0.40, zblok+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-0.707, yblok+0.40, zblok+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok, zblok+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+0.707, yblok+0.40, zblok+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok+0.81, zblok+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-0.707, yblok+0.40, zblok+1.14);
	glEnd();
	if(mining>0)mining--;

	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}
float rots::zfunction(float xx,float yy,float zz){
	if(xx>xobj-1 && xx<xobj+1 && yy>yobj-1 && yy<yobj+1){
		return zobj+1.0;
	}else{
		return MINHEIGHT;
	}
}


meteor::meteor(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=320;
	
	zobj= zz;
}
char* meteor::getnaam(){
	return "meteor";
}
int meteor::getprijs(){
	return -1;
}

int meteor::actie(zak* koffer,land* temp,int act){
	return -1;
}


void meteor::draw(){
	float hoek=0.7;
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.0f,0.0f);  
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+(100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)+100*sin(hoek)), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+(100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+(-100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+(-100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)-100*sin(hoek)), zobj);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-(100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)+100*sin(hoek)), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-(100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-(-100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-(-100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)-100*sin(hoek)), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+(100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)+100*sin(hoek)), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+(100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-(-100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-(-100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)-100*sin(hoek)), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-(100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)+100*sin(hoek)), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-(100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+(-100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+(-100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)-100*sin(hoek)), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+(100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+(-100*cos(hoek)-20*sin(hoek)), yobj+(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-(100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)+100*sin(hoek)), zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-(-100*cos(hoek)-20*sin(hoek)), yobj-(20*cos(hoek)-100*sin(hoek)), zobj+hoogteblok);

	glEnd();

}

float meteor::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

boom::boom(float xx,float yy,float zz,float hhoogte){
	xboom=xx;yboom=yy;hoogteboom=hhoogte;
	xobj=xboom;yobj=yboom;
	zboom= zz;
}
char* boom::getnaam(){
	return "boom";
}
int boom::getprijs(){
	return -1;
}
boom::boom(float xx,float yy){
	xboom=xx;yboom=yy;hoogteboom=20.0;
	xobj=xboom;yobj=yboom;
	zboom= 0;
}

int boom::actie(zak* koffer,land* temp,int act){
	return -1;
}

void boom::draw(){
	float dx,dy;
	dx=(xboom-x)/(sqrt((xboom-x)*(xboom-x)+(yboom-y)*(yboom-y)));
	dy=(yboom-y)/(sqrt((xboom-x)*(xboom-x)+(yboom-y)*(yboom-y)));

	   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // Black Background
    glClearDepth(1.0f);                         // Depth Buffer Setup
    glDepthFunc(GL_LEQUAL);                         // Type Of Depth Testing
    glEnable(GL_DEPTH_TEST);                        // Enable Depth Testing
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);          // Enable Alpha Blending (disable alpha testing)
    glEnable(GL_BLEND);                         // Enable Blending       (disable alpha testing)
//  glAlphaFunc(GL_GREATER,0.1f);                       // Set Alpha Testing     (disable blending)
//  glEnable(GL_ALPHA_TEST);                        // Enable Alpha Testing  (disable blending)
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
    //glEnable(GL_CULL_FACE);                         // Remove Back Face
	glBindTexture(GL_TEXTURE_2D,textures[2] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xboom-4*dy, yboom+4*dx, zboom);
		glTexCoord2f(0.0, 1.0);glVertex3f(xboom-4*dy, yboom+4*dx, zboom+hoogteboom);
		glTexCoord2f(1.0, 1.0);glVertex3f(xboom+4*dy, yboom-4*dx, zboom+hoogteboom);
		glTexCoord2f(1.0, 0.0);glVertex3f(xboom+4*dy, yboom-4*dx, zboom);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

float boom::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}


hekken::hekken(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=320;
	
	zobj= zz;
}
char* hekken::getnaam(){
	return "omheining wildernis";
}
int hekken::getprijs(){
	return -1;
}

int hekken::actie(zak* koffer,land* temp,int act){
	return -1;
}


void hekken::draw(){
	float hoek=0.7;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
	//begin
		//balk1
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj+5.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj+5.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj+5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj+4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj+4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+1, yobj+5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj+5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+1, yobj+4.5, zobj+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj+5.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj+5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+3, yobj+4.5, zobj+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-1, yobj+4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+3, yobj+4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj+5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj+4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj+4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj+4.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+4.5, zobj);
		
		//balk2
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj+5.4, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+5.4, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj+5.4, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj+5.4, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj+4.4, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+4.4, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj, yobj+5.4, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+4, yobj+5.4, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj+4.4, zobj+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+5.4, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj+5.4, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj+4.4, zobj+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+2, yobj+4.4, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj-2, yobj+4.4, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj+5.4, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj+5.4, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj+4.4, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+4.4, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj+4.4, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj+4.4, zobj);



	//midden balk
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj-5, zobj+2);
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj-5, zobj+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+5, zobj+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj, yobj+5, zobj+2);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj-5, zobj+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+5, zobj+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+1, yobj+5, zobj+3);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+1, yobj-5, zobj+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+1, yobj-5, zobj+2);
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+1, yobj-5, zobj+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj+5, zobj+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+1, yobj+5, zobj+2);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj-5, zobj+2);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj+5, zobj+2);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+1, yobj+5, zobj+2);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+1, yobj-5, zobj+2);
	//eind
		//balk1
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj-5.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj-5.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj-5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj-5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj-4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj-4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+1, yobj-5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj-5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+1, yobj-4.5, zobj+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj-5.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj-5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+3, yobj-4.5, zobj+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-1, yobj-4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+3, yobj-4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj-5.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj-5.5, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj-3, yobj-4.5, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj+1, yobj-4.5, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj+3, yobj-4.5, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj-4.5, zobj);
		
		//balk2
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj-5.6, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj-5.6, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj-5.6, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj-5.6, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj-4.6, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj-4.6, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj, yobj-5.6, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+4, yobj-5.6, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj-4.6, zobj+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj-5.6, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj-5.6, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-4.6, zobj+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+2, yobj-4.6, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj-2, yobj-4.6, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj-5.6, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj-5.6, zobj);

		glTexCoord2f(0.0, 0.2);glVertex3f(xobj+4, yobj-4.6, zobj);
		glTexCoord2f(0.2, 0.2);glVertex3f(xobj, yobj-4.6, zobj+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xobj-2, yobj-4.6, zobj+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj-4.6, zobj);
		
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float hekken::zfunction(float xx,float yy,float zz){
	if(xx>xobj-1 && xx<xobj+1 && yy>yobj-6 && yy<yobj+6){
		return zobj+3.0;
	}else{
		return MINHEIGHT;
	}
}


tarwe::tarwe(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=3;
	
	zobj= zz;
}
char* tarwe::getnaam(){
	return "tarwe veld";
}
int tarwe::getprijs(){
	return -1;
}
float tarwe::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return zobj+0.1;
}else{
	return MINHEIGHT;
}
}

int tarwe::actie(zak* koffer,land* temp,int act){
	return -1;
}


void tarwe::draw(){
	int i;
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[32] );
	glBegin(GL_QUADS);
	
	for(i=-30;i<=30;i+=2){
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj+i, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj+i, zobj+hoogteblok);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj-30, yobj+i, zobj+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-30, yobj+i, zobj);
	
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+i, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+i, yobj+30, zobj+hoogteblok);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj+i, yobj-30, zobj+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+i, yobj-30, zobj);
	}
		
	glEnd();                     
	glBindTexture(GL_TEXTURE_2D,textures[5] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-34, yobj-34, zobj+0.1);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj-34, yobj+34, zobj+0.1);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj+34, yobj+34, zobj+0.1);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj+34, yobj-34, zobj+0.1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

kruis::kruis(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* kruis::getnaam(){
	return "kruis kerkhof";
}
int kruis::getprijs(){
	return -1;
}
float kruis::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+1 && yy>yobj-1 && yy<yobj+1){
	return zobj+2;
}else{
	return MINHEIGHT;
}
}

int kruis::actie(zak* koffer,land* temp,int act){
	return -1;
}


void kruis::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		//houten kruis
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj+0.5, zobj);
		glTexCoord2f(1.0, 0.2);glVertex3f(xobj, yobj+0.5, zobj+5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-0.5, zobj+5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj-0.5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj+2.0, zobj+3.0);
		glTexCoord2f(0.0, 0.2);glVertex3f(xobj, yobj+2.0, zobj+4.0);
		glTexCoord2f(1.0, 0.2);glVertex3f(xobj, yobj-2.0, zobj+4.0);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-2.0, zobj+3.0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D,textures[5] );
		glBegin(GL_QUADS);
		//aarde graf		
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj+2, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+2, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj-2, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj-1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-2, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj+2, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-2, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-2, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+2, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-9, yobj-1, zobj+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj+1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-1, yobj-1, zobj+1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

ton::ton(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=4;
	straal=4;
	
	zobj= zz;
}
char* ton::getnaam(){
	return "ton";
}
int ton::getprijs(){
	return 100;
}
float ton::zfunction(float xx,float yy,float zz){
if(xx>xobj-straal && xx<xobj+straal && yy>yobj-straal && yy<yobj+straal){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int ton::actie(zak* koffer,land* temp,int act){
	return -1;
}


void ton::draw(){
	float r;
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		for(r=0;r<2*3.14;r+=0.2){
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(r)*straal, yobj+sin(r)*straal, zobj);
			glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(r)*straal, yobj+sin(r)*straal, zobj+hoogteblok);
			glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(r+0.2)*straal, yobj+sin(r+0.2)*straal, zobj+hoogteblok);
			glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(r+0.2)*straal, yobj+sin(r+0.2)*straal, zobj);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

apotheek::apotheek(float xx,float yy,float zz){
	xobj=xx;yobj=yy;
	
	zobj= zz;
	toon=0;
}
char* apotheek::getnaam(){
	return "apotheek";
}
int apotheek::getprijs(){
	return -1;
}
float apotheek::zfunction(float xx,float yy,float zz){
if(z<zobj+5){
	if((xx>xobj-20 && xx<xobj+20 && yy>yobj-20 && yy<yobj+20)&&!(xx>xobj-18 && xx<xobj+18 && yy>yobj-18 && yy<yobj+18)&&!(xx>xobj-3 && xx<xobj+3 && yy<yobj-10 && yy>yobj-20)){
		return zobj+10;
	}else if(xx>xobj-20 && xx<xobj+20 && yy<yobj+14 && yy>yobj+10){
		return zobj+3.0;
	}else if(xx>xobj-20 && xx<xobj+20 && yy>yobj-20 && yy<yobj+20){
		return zobj+0.1;
	}else{
		return MINHEIGHT;
	}
}else{//op dak
	if(xx>xobj-20 && xx<xobj+20 && yy>yobj && yy<yobj+20){
		return zobj+30-(yy-yobj);
	}else if(xx>xobj-20 && xx<xobj+20 && yy>yobj-20 && yy<yobj){
		return zobj+30+(yy-yobj);
	}else{
		return MINHEIGHT;
	}
}
}

int apotheek::actie(zak* koffer,land* temp,int act){
	if(act==0){
		toon=1-toon;
		return 1;
	}else{
		switch(act){
		case 1:	if(rugzak->geld>=10 && rugzak->zaklijst.size()< rugzak->maxzak){
					rugzak->geld=rugzak->geld-10;
					rugzak->insertzak(new fles(0,0,0,10));
				}
				break;
		case 2:	if(rugzak->geld>=1000 && rugzak->zaklijst.size()< rugzak->maxzak){
					rugzak->geld=rugzak->geld-1000;
					rugzak->insertzak(new fles(0,0,0,100));
				}
				break;
		case 3:	if(rugzak->geld>=rugzak->power*rugzak->power*1000){
					rugzak->geld=rugzak->geld-rugzak->power*rugzak->power*1000;
					rugzak->power++;
				}
				break;
		case 4:	if(rugzak->geld>=1000){
					rugzak->geld=rugzak->geld-1000;
					rugzak->maxzak++;
				}
				break;
			}
		}
	return -1;
}


void apotheek::draw(){
	float r;
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		for(r=0;r<2*3.14;r+=0.2){
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20+cos(r)*10, yobj+sin(r)*10, zobj);
			glTexCoord2f(0.0, 1.0);glVertex3f(xobj+20+cos(r)*5, yobj+sin(r)*5, zobj+40);
			glTexCoord2f(0.2, 1.0);glVertex3f(xobj+20+cos(r+0.2)*5, yobj+sin(r+0.2)*5, zobj+40);
			glTexCoord2f(0.2, 0.0);glVertex3f(xobj+20+cos(r+0.2)*10, yobj+sin(r+0.2)*10, zobj);
		}
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+19, yobj-19, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+20, yobj-20, zobj+10);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+3, yobj-20, zobj+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+3, yobj-19, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj-19, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-3, yobj-20, zobj+10);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-20, yobj-20, zobj+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-19, yobj-19, zobj);


		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+19, yobj+19, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+20, yobj+20, zobj+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj-20, yobj+20, zobj+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-19, yobj+19, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+19, yobj+19, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+20, yobj+20, zobj+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj+20, yobj-20, zobj+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+19, yobj-19, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-19, yobj-19, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-20, yobj-20, zobj+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj-20, yobj+20, zobj+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-19, yobj+19, zobj);
		//boven dak zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+20, yobj+20, zobj+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+18, yobj, zobj+10*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj+18, yobj, zobj+10*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj+20, yobj-20, zobj+10);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-20, yobj+20, zobj+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj-18, yobj, zobj+10*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xobj-18, yobj, zobj+10*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-20, yobj-20, zobj+10);
		//vloer

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-19, yobj-19, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-19, yobj+19, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+19, yobj+19, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+19, yobj-19, zobj+0.1);
	glEnd();
	// kasten
	glBindTexture(GL_TEXTURE_2D,textures[31] );
	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+18, yobj+18, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+18, yobj+18,zobj+10-2);
		glTexCoord2f(2.0, 1.0);glVertex3f(xobj-18, yobj+18, zobj+10-2);
		glTexCoord2f(2.0, 0.0);glVertex3f(xobj-18, yobj+18, zobj);
	glEnd();
	//toon bank

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-19, yobj+10, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-19, yobj+10, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+19, yobj+10, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+19, yobj+10, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-19, yobj+10, zobj+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-19, yobj+14, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+19, yobj+14, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+19, yobj+10, zobj+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-19, yobj+14, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-19, yobj+14, zobj+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+19, yobj+14, zobj+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+19, yobj+14, zobj);



	glEnd();

	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+22, yobj+22, zobj+10-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+20, yobj, zobj+10*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-20, yobj, zobj+10*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-22, yobj+22, zobj+10-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+22, yobj-22, zobj+10-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xobj+20, yobj, zobj+10*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xobj-20, yobj, zobj+10*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xobj-22, yobj-22, zobj+10-2);
		

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//toon aankoop papier
		if(toon){
		glPushMatrix(); 
		glLoadIdentity();
		glTranslated(0,0,-1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[26] );
		glBegin(GL_QUADS);
			 glTexCoord2f(0.0, 0.0);glVertex3f(-1.0,-1.0,-1.0);
			 glTexCoord2f(0.0, 1.0);glVertex3f(-1.0,1.0,-1.0);
				 glTexCoord2f(1.0, 1.0);glVertex3f(1.0,1.0,-1.0);
			 glTexCoord2f(1.0, 0.0);glVertex3f(1.0,-1.0,-1.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

			sprintf(strtemp,"apotheek geld %d coins",rugzak->geld);
			glutPrint(-0.45, 0.45, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"1)gezondheid(+10) 10 coins");
			glutPrint(-0.45, 0.40, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"2)gezondheid(+100) 1000 coins");
			glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"3)verbeter power %d coins",rugzak->power*rugzak->power*1000);
			glutPrint(-0.45, 0.30, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"4)verbeter rugzak 1000 coins");
			glutPrint(-0.45, 0.25, strtemp, 1, 1, 1, 0);
		}
		glPopMatrix();
}


tafel::tafel(float xx,float yy,float zz){
	xobj=xx;yobj=yy;zobj= zz;hoogteblok=2;
}
char* tafel::getnaam(){
	return "tafel";
}

int tafel::getprijs(){
	return -1;
}
float tafel::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-5 && yy<yobj+5){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int tafel::actie(zak* koffer,land* temp,int act){
	return -1;
}

void tafel::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj+1.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+5, zobj+1.5);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+1.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-5, zobj+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-5, zobj+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj+1.5);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj+1.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-5, zobj+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+1.5);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj+1.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-5, zobj+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+5, zobj+1.5);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+2);
		//poten
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj+4, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj+4, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj+4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj+3, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj+3, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+9, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+9, yobj+4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+8, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+8, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj+4, zobj);

		
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj-4, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj-4, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj-4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj-3, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj-3, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+9, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+9, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+9, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+9, yobj-4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+8, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+8, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+8, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+8, yobj-4, zobj);

		
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj+4, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj+4, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj+4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj+3, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj+3, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-9, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-9, yobj+4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-8, yobj+3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-8, yobj+3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj+4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj+4, zobj);


		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj-4, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj-4, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj-4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj-3, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj-3, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-9, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-9, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-9, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-9, yobj-4, zobj);

		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-8, yobj-3, zobj);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-8, yobj-3, zobj+1.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-8, yobj-4, zobj+1.5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-8, yobj-4, zobj);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// mensen
//--------------------------------------------------------->>>

mens::mens(float xx,float yy,float zz){
	xobj=xx;yobj=yy;zobj= zz;hoogteblok=6;
	mag=6.0;
}
char* mens::getnaam(){
	return "mens";
}

int mens::getprijs(){
	return -1;
}
float mens::zfunction(float xx,float yy,float zz){
if(xx>xobj-2 && xx<xobj+2 && yy>yobj-2 && yy<yobj+2){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int mens::actie(zak* koffer,land* temp,int act){
	return -1;
}

void mens::draw(){
    glEnable(GL_TEXTURE_2D); 
float hoekbeen=0.0;
float	hoekarm1=0.5*sin(0.0);
float 	hoekarm2=-0.2*sin(0.0);
	glBindTexture(GL_TEXTURE_2D,textures[12] );
	//been1
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4+mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025-mag*0.025*cos(hoekbeen));
		 //been2
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.5-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-mag*0.2*sin(hoekbeen)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.025+mag*0.025*cos(hoekbeen));

	glEnd();

	//buik
	glBindTexture(GL_TEXTURE_2D,textures[11] );		//waldo truitje
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.3);
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.3);

		 //armen boven ook trui textures
		  glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);

		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);

	glEnd();

	//arm rechts
	glBindTexture(GL_TEXTURE_2D,textures[18] );		
	glBegin(GL_QUADS);
		

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

	glEnd();

	//arm links
	glBindTexture(GL_TEXTURE_2D,textures[18] );		
	glBegin(GL_QUADS);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

	glEnd();

	//hoofd
	glBindTexture(GL_TEXTURE_2D,textures[17] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[13] );
	glBegin(GL_QUADS);
		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[15] );
	glBegin(GL_QUADS);
		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[16] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[14] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}




priest::priest(float xx,float yy,float zz,std::string temp){
	xobj=xx;yobj=yy;zobj= zz;hoogteblok=6;
	mag=6.0;toon=0;
	text=temp;
}
char* priest::getnaam(){
	return "priest";
}

int priest::getprijs(){
	return -1;
}
float priest::zfunction(float xx,float yy,float zz){
if(xx>xobj-2 && xx<xobj+2 && yy>yobj-2 && yy<yobj+2){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int priest::actie(zak* koffer,land* temp,int act){
	if(act==0){
		toon=1-toon;
		return 1;
	}else{
		return -1;
	}
}

void priest::draw(){
    glEnable(GL_TEXTURE_2D); 
float hoekbeen=0.0;
float	hoekarm1=0.5*sin(0.0);
float 	hoekarm2=-0.2*sin(0.0);
float color[4];
	glGetFloatv(GL_CURRENT_COLOR, color);                        // Enable Texture Mapping
	glColor4f(0.722,0.476,0.339,1.0);
	glBindTexture(GL_TEXTURE_2D,textures[48] );	
	glBegin(GL_QUADS);
	//buik
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj);

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj);

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.3-0.5*mag, zobj);
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.7-0.5*mag, zobj);

		 //armen boven ook trui textures
		  glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);

		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);

	glEnd();
	glColor4fv(color);
	//arm rechts
	glBindTexture(GL_TEXTURE_2D,textures[47] );		
	glBegin(GL_QUADS);
		

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.2-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm2)-0.5*mag, yobj+mag*0.3-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm2));

	glEnd();

	//arm links
	glBindTexture(GL_TEXTURE_2D,textures[47] );		
	glBegin(GL_QUADS);

		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.7-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.55+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.55-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.45-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.5);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.45+mag*0.3*sin(hoekarm1)-0.5*mag, yobj+mag*0.8-0.5*mag, zobj+mag*0.6-mag*0.3*cos(hoekarm1));

	glEnd();

	//hoofd
	glBindTexture(GL_TEXTURE_2D,textures[17] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,0.0,1.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[13] );
	glBegin(GL_QUADS);
		 glNormal3f(-1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[15] );
	glBegin(GL_QUADS);
		 glNormal3f(1.0,0.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[16] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,-1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.4-0.5*mag, zobj+mag*0.6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[14] );
	glBegin(GL_QUADS);
		 glNormal3f(0.0,1.0,0.0);
		 glTexCoord2f(0.0, 0.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);
		 glTexCoord2f(0.0, 1.0);glVertex3f(xobj+mag*0.6-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 1.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.8);
		 glTexCoord2f(1.0, 0.0);glVertex3f(xobj+mag*0.4-0.5*mag, yobj+mag*0.6-0.5*mag, zobj+mag*0.6);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	if(toon){
		glPushMatrix(); 
		glLoadIdentity();
		glTranslated(0,0,-1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[26] );
		glBegin(GL_QUADS);
			 glTexCoord2f(0.0, 0.0);glVertex3f(-1.0,-1.0,-1.0);
			 glTexCoord2f(0.0, 1.0);glVertex3f(-1.0,1.0,-1.0);
				 glTexCoord2f(1.0, 1.0);glVertex3f(1.0,1.0,-1.0);
			 glTexCoord2f(1.0, 0.0);glVertex3f(1.0,-1.0,-1.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		std::string temp;
		int i=0;
		int hoogte=0;
		int lengte=0;

		for(i=0;i<text.size();i++){
		lengte++;
		if(lengte>40&&text.at(i)==' '){
			temp=text.substr(i-lengte+1,lengte);
			strtemp[temp.size()]=0;
			memcpy(strtemp,temp.c_str(),temp.size());
			glutPrint(-0.45, 0.45-0.05*hoogte, strtemp, 1, 1, 1, 0);
			hoogte++;
			lengte=0;
		}
		}
		glPopMatrix();
		/*
		sprintf(strtemp,"hoi ik ben nico de monk.");
		glutPrint(-0.45, 0.45, strtemp, 1, 1, 1, 0);
		sprintf(strtemp,"ons dorp wordt aangevallen, en de poort is gesloten.");
		glutPrint(-0.45, 0.40, strtemp, 1, 1, 1, 0);
		sprintf(strtemp,"wij kunnen niet meer  binnen in ons fort.");
		glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
		sprintf(strtemp,"kan jij de poort openen voor ons?");
		glutPrint(-0.45, 0.30, strtemp, 1, 1, 1, 0);
		sprintf(strtemp,"Er moet ergens een tunnel zijn tot in het fort.");
		glutPrint(-0.45, 0.25, strtemp, 1, 1, 1, 0);
		glPopMatrix();
		*/
	}



}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// TUNNEL
//--------------------------------------------------------->>>
luik::luik(float xx,float yy,float zz,float telxx,float telyy,float telzz){
	xobj=xx;yobj=yy;zobj= zz;hoogteblok=0.2;
	telx=telxx;tely=telyy;telz=telzz;
}
char* luik::getnaam(){
	return "luik";
}

int luik::getprijs(){
	return -1;
}
float luik::zfunction(float xx,float yy,float zz){
if(xx>xobj-2.5 && xx<xobj+2.5 && yy>yobj-5 && yy<yobj+5){
	return zobj+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int luik::actie(zak* koffer,land* temp,int act){
if(x>xobj-2.5 && x<xobj+2.5 && y>yobj-5 && y<yobj+5){
	teleport=1;
	x=telx;y=tely;z=telz;
	return 1;
}else{
	return -1;
}
}

void luik::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2.5, yobj+5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2.5, yobj+5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2.5, yobj-5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2.5, yobj-5, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2.5, yobj-5, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2.5, yobj-5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2.5, yobj+5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2.5, yobj-5, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2.5, yobj-5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2.5, yobj-5, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2.5, yobj+5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2.5, yobj-5, zobj+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2.5, yobj+5, zobj+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-5, zobj+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

tunnelx::tunnelx(float xx,float yy,float zz,float telxx,float telyy,float telzz){
	xobj=xx;yobj=yy;hoogteblok=10;
	telx=telxx;tely=telyy;telz=telzz;
	zobj= zz;
}
char* tunnelx::getnaam(){
	return "tunnelx";
}
int tunnelx::getprijs(){
	return -1;
}
float tunnelx::zfunction(float xx,float yy,float zz){
if((xx>xobj-30 && xx<xobj+30 && yy>yobj-30 && yy<yobj+30)||(xx>xobj-5 && xx<xobj+5 && yy>yobj && yy<yobj+55)){
	return zobj;
}else{
	return zobj+10.0;
}
}

int tunnelx::actie(zak* koffer,land* temp,int act){
	if(x>xobj-2.5 && x<xobj+2.5 && y>yobj-30 && y<yobj-20){
		teleport=1;
		x=telx;y=tely;z=telz;
		return 1;
	}else{
		return -1;
	}
}


void tunnelx::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj+30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj);
		//vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj+0.1);
		//plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		//inkom
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+5, yobj+50, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj+30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-5, yobj+50, zobj);
		//inkom vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj+30, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj+30, zobj+0.1);
		//inkom plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj+30, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj+30, zobj+20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
	int i;
		for(i=0;i<10;i++){
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj-28, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj-30, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-30, zobj+i*2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-30, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj-30, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2, yobj-28, zobj+i*2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-28, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-28, zobj+i*2);
		//inkom vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-30, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj-28, zobj+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj-28, zobj+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-30, zobj+i*2);
		//inkom plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-30, zobj+0.5+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj-28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-30, zobj+0.5+i*2);
		}
		//luik
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2.5, yobj-30, zobj+19.9);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2.5, yobj-20, zobj+19.9);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2.5, yobj-20, zobj+19.9);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-30, zobj+19.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}



tunnelminx::tunnelminx(float xx,float yy,float zz,float telxx,float telyy,float telzz){
	xobj=xx;yobj=yy;hoogteblok=10;
	telx=telxx;tely=telyy;telz=telzz;
	zobj= zz;
}
char* tunnelminx::getnaam(){
	return "tunnelminx";
}
int tunnelminx::getprijs(){
	return -1;
}
float tunnelminx::zfunction(float xx,float yy,float zz){
if((xx>xobj-30 && xx<xobj+30 && yy>yobj-30 && yy<yobj+30)||(xx>xobj-5 && xx<xobj+5 && yy>yobj-55 && yy<yobj)){
	return zobj;
}else{
	return zobj+10.0;
}
}

int tunnelminx::actie(zak* koffer,land* temp,int act){
	if(x>xobj-2.5 && x<xobj+2.5 && y<yobj+30 && y>yobj+20){
		teleport=1;
		x=telx;y=tely;z=telz;
		return 1;
	}else{
		return -1;
	}
}


void tunnelminx::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+30, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-30, yobj-30, zobj);
		//vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj+0.1);
		//plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-30, yobj+30, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+30, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+30, yobj+30, zobj+20);
		//inkom
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+5, yobj-50, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj-30, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-30, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-30, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj-30, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-5, yobj-50, zobj);
		//inkom vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-30, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj-50, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj-50, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-30, zobj+0.1);
		//inkom plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-30, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-30, zobj+20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
	int i;
		for(i=0;i<10;i++){
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj+28, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj+30, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj+30, zobj+i*2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj+30, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj+30, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2, yobj+28, zobj+i*2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj+28, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj+28, zobj+i*2);
		//inkom vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj+30, zobj+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj+28, zobj+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj+28, zobj+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj+30, zobj+i*2);
		//inkom plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj+30, zobj+0.5+i*2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj+28, zobj+0.5+i*2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj+30, zobj+0.5+i*2);
		}
		//luik
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2.5, yobj+30, zobj+19.9);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2.5, yobj+20, zobj+19.9);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2.5, yobj+20, zobj+19.9);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj+30, zobj+19.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


tunnelxx::tunnelxx(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	zobj= zz;
}
char* tunnelxx::getnaam(){
	return "tunnelxx";
}
int tunnelxx::getprijs(){
	return -1;
}
float tunnelxx::zfunction(float xx,float yy,float zz){
if((xx>xobj-5 && xx<xobj+5 && yy>yobj-55 && yy<yobj+55)){
	return zobj;
}else{
	return zobj+10.0;
}
}

int tunnelxx::actie(zak* koffer,land* temp,int act){
		return -1;
}


void tunnelxx::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		//inkom
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+5, yobj+50, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-50, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-50, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj-50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-5, yobj+50, zobj);
		//inkom vloer
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-50, zobj+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-50, zobj+0.1);
		//inkom plafond
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-5, yobj-50, zobj+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+5, yobj+50, zobj+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+5, yobj-50, zobj+20);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// winkerl gerief
//--------------------------------------------------------->>>

fles::fles(float xx,float yy,float zz,int llevel){
	level=llevel;
	xobj=xx;yobj=yy;hoogteblok=sqrt((float)level)/5.0;
	straal=sqrt((float)level)/10.0;
	
	zobj= zz;
}
char* fles::getnaam(){
	sprintf(strtempp,"fles gezondheid %d",level);
	return strtempp;
}
int fles::getprijs(){
	return level*level/10.0;
}
float fles::zfunction(float xx,float yy,float zz){
if(xx>xobj-straal && xx<xobj+straal && yy>yobj-straal && yy<yobj+straal){
	return zobj+hoogteblok*3;
}else{
	return MINHEIGHT;
}
}

int fles::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem fles <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}


void fles::draw(){
	float r;
	float color[4];
	glGetFloatv(GL_CURRENT_COLOR, color);
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glColor4f(0.0,0.0,1.0,1.0);
	glBegin(GL_QUADS);
		for(r=0;r<2*3.14;r+=0.2){
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(r)*straal, yobj+sin(r)*straal, zobj);
			glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(r)*straal*2, yobj+sin(r)*straal*2, zobj+hoogteblok);
			glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(r+0.2)*straal*2, yobj+sin(r+0.2)*straal*2, zobj+hoogteblok);
			glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(r+0.2)*straal, yobj+sin(r+0.2)*straal, zobj);

			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(r)*straal*2, yobj+sin(r)*straal*2, zobj+hoogteblok);
			glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(r)*straal*0.5, yobj+sin(r)*straal*0.5, zobj+hoogteblok*3);
			glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(r+0.2)*straal*0.5, yobj+sin(r+0.2)*straal*0.5, zobj+hoogteblok*3);
			glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(r+0.2)*straal*2, yobj+sin(r+0.2)*straal*2, zobj+hoogteblok);
		}
	glEnd();
	glColor4f(1.0,0.0,0.0,1.0);
	glBegin(GL_QUADS);
		for(r=0;r<2*3.14;r+=0.2){
			glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(r)*0.0, yobj+sin(r)*0.0, zobj+hoogteblok*2);
			glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(r)*straal*0.7, yobj+sin(r)*straal*0.7, zobj+hoogteblok*3.5);
			glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(r+0.2)*straal*0.7, yobj+sin(r+0.2)*straal*0.7, zobj+hoogteblok*3.5);
			glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(r+0.2)*0.0, yobj+sin(r+0.2)*0.0, zobj+hoogteblok*2);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor4fv(color);
}

car::car(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteblok=10;
	
	zobj= zz;
}
char* car::getnaam(){
	return "Bugatti Veyron";
}
int car::getprijs(){
	return 2200000;
}
float car::zfunction(float xx,float yy,float zz){
if(xx>xobj-10 && xx<xobj+10 && yy>yobj-10 && yy<yobj+10){
	return MINHEIGHT;
}else{
	return MINHEIGHT;
}
}

int car::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem car <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}


void car::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[1] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj-5, zobj+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj-5, zobj+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+10, yobj+5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj-5, zobj+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj-5, zobj+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-10, yobj+5, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-10, yobj-5, zobj+2.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+10, yobj+5, zobj+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+10, yobj-5, zobj+2.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}




geld::geld(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}
char* geld::getnaam(){
	return "geld";
}
int geld::getprijs(){
	return 1;
}
geld::geld(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}

int geld::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem geld <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

void geld::draw(){
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[8] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-0.2, yobj-0.2, zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-0.2, yobj+0.2, zobj+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+0.2, yobj+0.2, zobj+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+0.2, yobj-0.2, zobj+hoogteding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float geld::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}



zwaard::zwaard(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}
char* zwaard::getnaam(){
	return "zwaard";
}
int zwaard::getprijs(){
	return 10;
}
zwaard::zwaard(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.5;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}
void zwaard::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[19] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-0.25, zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-2, yobj+0.25, zobj+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2, yobj+0.25, zobj+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-0.25, zobj+hoogteding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

int zwaard::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem zwaard <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

float zwaard::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

mantel::mantel(float xx,float yy,float zz,int texx){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
	tex=texx;
}

mantel::mantel(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
	tex=28;
}
char* mantel::getnaam(){
	switch(tex){
		case 28: return "mantel";
		case 34: return "mantel lucht";
		case 35: return "mantel water";
		case 36: return "mantel vuur";
		case 37: return "mantel aarde";
		default: return "mantel";
	}
	return "mantel";
}
int mantel::getprijs(){
	return 10;
}
mantel::mantel(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.5;
	xobj=xobj;yobj=yobj;
	zobj= 0;
	tex=28;
}
void mantel::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[tex] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-2, yobj-3, zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj+3, zobj+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+1, yobj+3, zobj+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2, yobj-3, zobj+hoogteding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

int mantel::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem mantel <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

float mantel::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

houweel::houweel(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}
char* houweel::getnaam(){
	return "houweel";
}
int houweel::getprijs(){
	return 10;
}
houweel::houweel(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.5;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}
void houweel::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-2, yobj-0.25, zobj+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-2, yobj+0.25, zobj+hoogteding);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj+0.25, zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2, yobj-0.25, zobj+hoogteding);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,textures[29] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+2, yobj-2, zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+2, yobj+2, zobj+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+2.5, yobj+2, zobj+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+2.5, yobj-2, zobj+hoogteding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

int houweel::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem houweel <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

float houweel::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}






erts::erts(float xx,float yy,float zz,int tt){
	tex=tt;
	if(tt==10)tex=30;	//diamand krijgt een andere tecture
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}

char* erts::getnaam(){
	switch (tex){
		case 6:
			return "kool";
		case 7:
			return "ijzer";
		case 8:
			return "goud";
		case 9:
			return "platina";
		case 20:
			return "steen";
		case 30:
			return "diamand";
		default:
			return "erts";
	}
	return "erts";
}
int erts::getprijs(){
	switch (tex){
		case 6:
			return 10;
		case 7:
			return 20;
		case 8:
			return 100;
		case 9:
			return 50;
		case 20:
			return 2;
		case 30:
			return 1000;
		default:
			return 1;
	}
	return 10;
}
erts::erts(float xx,float yy,int tt){
	tex=tt;
	if(tt==10)tex=30;	//diamand krijgt een andere tecture
	xobj=xx;yobj=yy;hoogteding=0.5;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}
void erts::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[tex] );
	glBegin(GL_QUADS);
	//onderkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj+0.81, zobj+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+0.707, yobj+0.40, zobj+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+0.707, yobj-0.40, zobj+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj+0.81, zobj+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-0.707, yobj+0.40, zobj+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-0.707, yobj-0.40, zobj+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+0.707, yobj-0.40, zobj+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj-0.81, zobj+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-0.707, yobj-0.40, zobj+0.57);
	//bovenkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-0.81, zobj+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+0.707, yobj-0.40, zobj+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+0.707, yobj+0.40, zobj+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj, yobj-0.81, zobj+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-0.707, yobj-0.40, zobj+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-0.707, yobj+0.40, zobj+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xobj, yobj, zobj+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+0.707, yobj+0.40, zobj+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj, yobj+0.81, zobj+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-0.707, yobj+0.40, zobj+1.14);
	glEnd();
}

int erts::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem diamand <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

float erts::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}



kelk::kelk(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}
char* kelk::getnaam(){
	return "kelk";
}
int kelk::getprijs(){
	return 1;
}
kelk::kelk(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}

int kelk::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem kelk <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

void kelk::draw(){
	float dx,dy;
	float u,v;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[8] );
	glBegin(GL_QUADS);
	for(u=0;u<2*3.1415;u=u+(2*3.1415)/10){
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(u), yobj+sin(u), zobj+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(u)*0.2, yobj+sin(u)*0.2, zobj+hoogteding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(u+(2*3.1415)/10)*0.2, yobj+sin(u+(2*3.1415)/10)*0.2, zobj+hoogteding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(u+(2*3.1415)/10), yobj+sin(u+(2*3.1415)/10), zobj+hoogteding);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(u)*0.2, yobj+sin(u)*0.2, zobj+hoogteding+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(u)*0.7, yobj+sin(u)*0.7, zobj+hoogteding+1.2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(u+(2*3.1415)/10)*0.7, yobj+sin(u+(2*3.1415)/10)*0.7, zobj+hoogteding+1.2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(u+(2*3.1415)/10)*0.2, yobj+sin(u+(2*3.1415)/10)*0.2, zobj+hoogteding+1);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+cos(u)*0.7, yobj+sin(u)*0.7, zobj+hoogteding+1.2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+cos(u), yobj+sin(u), zobj+hoogteding+1.7);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+cos(u+(2*3.1415)/10), yobj+sin(u+(2*3.1415)/10), zobj+hoogteding+1.7);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+cos(u+(2*3.1415)/10)*0.7, yobj+sin(u+(2*3.1415)/10)*0.7, zobj+hoogteding+1.2);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float kelk::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

blok::blok(float xx,float yy,float zz){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
}
char* blok::getnaam(){
	return "blok";
}
int blok::getprijs(){
	return 1;
}
blok::blok(float xx,float yy){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= 0;
}

int blok::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n neem blok <----------------------");
	if(koffer->zaklijst.size()<koffer->maxzak){
		koffer->insertzak(this);
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
	}
	return -1;
}

void blok::draw(){
	float dx,dy;
	float u,v;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj-1, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+1, yobj-1, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+1, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+1, yobj+1, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+1, yobj+1, zobj+1);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj+1, yobj-1, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj+1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj+1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj+1, yobj+1, zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(xobj-1, yobj-1, zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(xobj-1, yobj-1, zobj+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xobj-1, yobj+1, zobj+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xobj-1, yobj+1, zobj);




	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float blok::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// vijanden
//--------------------------------------------------------->>>


slak::slak(float xx,float yy,float zz,int levell){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= zz;
	level=levell;
	gezondheid=100;
	hoek=0.0;
	seconds = time (NULL);
}
char* slak::getnaam(){
	return "slak";
}
int slak::getprijs(){
	return -1;
}
slak::slak(float xx,float yy,int levell){
	xobj=xx;yobj=yy;hoogteding=0.1;
	xobj=xobj;yobj=yobj;
	zobj= 0;
	level=levell;
	gezondheid=100;
	hoek=0.0;
	seconds = time (NULL);
}

int slak::actie(zak* koffer,land* temp,int act){
	int i;
	float afstand=sqrt((y-yobj)*(y-yobj)+(x-xobj)*(x-xobj));
	if(afstand<5){
	printf("\n vecht slak <----------------------");
	gezondheid=gezondheid-(koffer->vechtlevel()+koffer->extravechtlevel())*((int)rand()%10);
	koffer->gezondheid=koffer->gezondheid-level*((int)rand()%10);
	if(gezondheid<0){  //if slak dood, verdwijn slak.
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);
				rugzak->vechtxp+=100*level;
				return 1;
			}
		}
	}
	return 1;
	}
	return -1;
}

void slak::draw(){
	float dx,dy;
	float u,v;
	char str[100];
	float mag;
	mag=sqrt((float)level);
	//verplaatsen en aanvallen of blinde wandeling
	time_t ds;
	ds = time (NULL);
	ds=ds-seconds;
	seconds = time (NULL);
	float afstand=sqrt((y-yobj)*(y-yobj)+(x-xobj)*(x-xobj));
	if(afstand<5*mag){//straal 5 bijten
		rugzak->gezondheid=rugzak->gezondheid-ds*level*((int)rand()%10);

	}else if(afstand<20*mag){//straal 20	aanvallen
		float xxobj,yyobj;
		hoek=atan((y-yobj)/(x-xobj));
		if((x-xobj)>0) hoek=hoek+PI;
		yyobj=((y-yobj)/afstand)*ds+yobj;
		xxobj=((x-xobj)/afstand)*ds+xobj;
		if(zfunction(xxobj,yyobj,zobj)<zobj+2){
			//zobj=zfunction(xxobj,yyobj);
			if(floor(yyobj/100)==floor(yobj/100) && floor(xxobj/100) == floor(xobj/100)){
				yobj=yyobj;xobj=xxobj;
			}
		}
	}else{//blinde wandeling

	}
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[8] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-2*mag,-0.5*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-2*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+1*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+1*mag,-0.5*mag,hoek), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-2*mag,+0.5*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-2*mag,+0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+1*mag,+0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+1*mag,+0.5*mag,hoek), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-2*mag,+0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-2*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+1*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+1*mag,+0.5*mag,hoek), zobj+1*mag);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,+1*mag,-0.5*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,+1*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+1*mag,+0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+1*mag,+0.5*mag,hoek), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-2*mag,-0.5*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-2*mag,-0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,-2*mag,+0.5*mag,hoek), zobj+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,-2*mag,+0.5*mag,hoek), zobj);
	glEnd();
	//schelp gedraaid
	glBindTexture(GL_TEXTURE_2D,textures[22] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-1*mag,-0.7*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-1*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+2*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+2*mag,-0.7*mag,hoek), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-1*mag,+0.7*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-1*mag,+0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+2*mag,+0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+2*mag,+0.7*mag,hoek), zobj);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-1*mag,+0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-1*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+2*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+2*mag,+0.7*mag,hoek), zobj+2*mag);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,+2*mag,-0.7*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,+2*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,+2*mag,+0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,+2*mag,+0.7*mag,hoek), zobj);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xobj,yobj,-1*mag,-0.7*mag,hoek), zobj);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xobj,yobj,-1*mag,-0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xobj,yobj,-1*mag,+0.7*mag,hoek), zobj+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xobj,yobj,-1*mag,+0.7*mag,hoek), zobj);
	glEnd();
	glDisable(GL_TEXTURE_2D);
/*
//tekst gezondheid slak
	glPushMatrix();
			glLoadIdentity();
			glTranslated(0,0,-1);
			sprintf(str,"slak %d",gezondheid);
			glutPrint(-1, 0.4, str, 1, 1, 1, 0);
		glPopMatrix();
*/
}

float slak::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

///////////////////////kader

kader::kader(float xx,float yy,float zz, int ff){
	xobj=xx;yobj=yy;hoogteblok=320;
	foto=ff;
	zobj= zz;
}
char* kader::getnaam(){
	return "kader";
}
int kader::getprijs(){
	return -1;
}

int kader::actie(zak* koffer,land* temp,int act){
	return -1;
}


void kader::draw(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[foto] );
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);glVertex3f(xobj-3, yobj, zobj+3);
	glTexCoord2f(0.0, 1.0);glVertex3f(xobj-3, yobj, zobj+7);
	glTexCoord2f(1.0, 1.0);glVertex3f(xobj+3, yobj, zobj+7);
	glTexCoord2f(1.0, 0.0);glVertex3f(xobj+3, yobj, zobj+3);
	glEnd();
}

float kader::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

