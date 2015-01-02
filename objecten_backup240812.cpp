//*********************************************************
//*  objecten
//*********************************************************
#include <iostream>
#include <GL/glut.h>
#include <time.h>
#include "objecten.h"
#include "lijst.h"
#include "math.h"
#define PI 3.141592653 //.....
#define ROT(x,y,a,b,hoek) ( x + a *cos( hoek ) - b *sin( hoek )) , ( y + a *sin( hoek )+ b *cos( hoek ))
//#define ROT(x,y,a,b,hoek) x+a,y+b
//#include "glovar.h"
char strtemp[100];
char strtempp[100];

/*
#define FILEAANTAL 21
char* filenameh[FILEAANTAL]={"gras.bmp","gras.bmp","buy.bmp","sell.bmp","gras.bmp","aardeh.bmp","koolh.bmp","ijzerh.bmp","goudh.bmp","platinah.bmp","diamandh.bmp","waldo.bmp","broek.bmp","gezichtvoor.bmp","gezichtlinks.bmp","gezichtachter.bmp","gezichtrechts.bmp","gezichtboven.bmp","arm.bmp","zwaard1.bmp","rotsh.bmp","papier.h"};
float relief[100][100];
GLuint*  textures;
float x,y,z;
*/


void glutPrint(float xxx, float yyy, char* text, float rr, float gg, float bb, float aa){
	float color[4];
	glGetFloatv(GL_CURRENT_COLOR, color);
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
	xblok=xx;yblok=yy;hoogteblok=0.5;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* brughout::getnaam(){
	return "brughout";
}

int brughout::getprijs(){
	return -1;
}

float brughout::zfunction(float xx,float yy,float zz){
if(x>xblok-10 && x<xblok+10 && y>yblok-10 && y<yblok+10){
	return zblok+hoogteblok;
}else{
	return MINHEIGHT;
}
}

int brughout::actie(zak* koffer,land* temp,int act){
	return -1;
}

void brughout::draw(){
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


trap::trap(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* trap::getnaam(){
	return "helling";
}
int trap::getprijs(){
	return -1;
}
float trap::zfunction(float xx,float yy,float zz){
if(x>xblok-10 && x<xblok+10 && y>yblok-10 && y<yblok+10){
	return ((x-(xblok-10))/20.0*hoogteblok)+zblok;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);
		//driehoek
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);


		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


toren::toren(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=13;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* toren::getnaam(){
	return "toren";
}
int toren::getprijs(){
	return -1;
}
float toren::zfunction(float xx,float yy,float zz){
if(xx>xblok-12 && xx<xblok+12 && yy>yblok-12 && yy<yblok+12){
	return zblok+hoogteblok;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+12, yblok+12, zblok-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-12, yblok+12, zblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+12, yblok-12, zblok-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+12, yblok-12, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-12, yblok-12, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-12, yblok-12, zblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+12, yblok+12, zblok-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+12, yblok-12, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+12, yblok-12, zblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-12, yblok-12, zblok-2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-12, yblok-12, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-12, yblok+12, zblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-12, yblok-12, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+12, yblok+12, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+12, yblok-12, zblok+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

boomblok::boomblok(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* boomblok::getnaam(){
	return "boomblok";
}
int boomblok::getprijs(){
	return -1;
}
float boomblok::zfunction(float xx,float yy,float zz){
if(xx>xblok-4 && xx<xblok+4 && yy>yblok-4 && yy<yblok+4){
	return zblok+hoogteblok*3;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+3, yblok+3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-3, yblok+3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+3, yblok-3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+3, yblok-3, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-3, yblok-3, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-3, yblok-3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+3, yblok+3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+3, yblok-3, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+3, yblok-3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok-3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-3, yblok-3, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-3, yblok+3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok-3, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+3, yblok+3, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+3, yblok-3, zblok+hoogteblok);

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[23] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok*3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok*3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


winkel::winkel(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
	toon=0;
	soort=0;
}
winkel::winkel(float xx,float yy,float zz,int soortt){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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
if((xx>xblok-20 && xx<xblok+20 && yy>yblok-20 && yy<yblok+20)&&!(xx>xblok-18 && xx<xblok+18 && yy>yblok-18 && yy<yblok+18)&&!(xx>xblok-3 && xx<xblok+3 && yy>yblok+10 && yy<yblok+20)){
	return zblok+hoogteblok;
}else if(xx>xblok-20 && xx<xblok+20 && yy>yblok-14 && yy<yblok-10){
	return zblok+3.0;
}else if(xx>xblok-20 && xx<xblok+20 && yy>yblok-20 && yy<yblok+20){
	return zblok+0.1;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20, yblok+20, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+3, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+3, yblok+20, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok+20, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-3, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-20, yblok+20, zblok);


		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20, yblok-20, zblok);
		glTexCoord2f(0.0, 2.0);glVertex3f(xblok+20, yblok-20, zblok+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xblok-20, yblok-20, zblok+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-20, yblok-20, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20, yblok+20, zblok);
		glTexCoord2f(0.0, 2.0);glVertex3f(xblok+20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xblok+20, yblok-20, zblok+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+20, yblok-20, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-20, zblok);
		glTexCoord2f(0.0, 2.0);glVertex3f(xblok-20, yblok-20, zblok+hoogteblok);
		glTexCoord2f(2.0, 2.0);glVertex3f(xblok-20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-20, yblok+20, zblok);
		//boven dak zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+20, yblok, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+20, yblok, zblok+hoogteblok*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+20, yblok-20, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok+20, zblok+hoogteblok);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok-20, yblok, zblok+hoogteblok*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok-20, yblok, zblok+hoogteblok*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-20, yblok-20, zblok+hoogteblok);
		//vloer

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-20, zblok+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok+20, zblok+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+20, yblok+20, zblok+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+20, yblok-20, zblok+0.1);
	glEnd();
	// kasten
	glBindTexture(GL_TEXTURE_2D,textures[31] );
	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+18, yblok-18, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+18, yblok-18, zblok+hoogteblok-2);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok-18, yblok-18, zblok+hoogteblok-2);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-18, yblok-18, zblok);
	glEnd();
	//toon bank

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok-10, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+20, yblok-10, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+20, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-10, zblok+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok-14, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+20, yblok-14, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+20, yblok-10, zblok+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-14, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok-14, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+20, yblok-14, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+20, yblok-14, zblok);



	glEnd();

	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+22, yblok+22, zblok+hoogteblok-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+22, yblok, zblok+hoogteblok*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-22, yblok, zblok+hoogteblok*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-22, yblok+22, zblok+hoogteblok-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+22, yblok-22, zblok+hoogteblok-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+22, yblok, zblok+hoogteblok*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-22, yblok, zblok+hoogteblok*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-22, yblok-22, zblok+hoogteblok-2);
		

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
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* muurblok::getnaam(){
	return "muur";
}
int muurblok::getprijs(){
	return -1;
}
float muurblok::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
	return zblok+hoogteblok;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}



muurx::muurx(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* muurx::getnaam(){
	return "muurx";
}
int muurx::getprijs(){
	return -1;
}
float muurx::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
	return zblok+hoogteblok;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		
		//lange kanteel boven
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+8, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+8, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok+8, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok+8, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok+8, zblok+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok+8, zblok+hoogteblok+2);

		//lange kanteel onder (2d vlak)
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-8, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-8, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-8, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-8, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-8, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-8, zblok+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-8, zblok+hoogteblok+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

muury::muury(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* muury::getnaam(){
	return "muury";
}
int muury::getprijs(){
	return -1;
}
float muury::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
	return zblok+hoogteblok;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		
		//lange kanteel boven
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+8, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+8, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+8, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+8, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+8, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+8, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+8, yblok+10, zblok+hoogteblok+2);

		//lange kanteel
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-8, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-8, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-8, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-8, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-8, yblok+10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-8, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-8, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok+2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-8, yblok+10, zblok+hoogteblok+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}




kasteel::kasteel(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=20;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-10, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+10, zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-10, zblok+hoogteblok);


	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}
float kasteel::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
	return zblok+hoogteblok;
}else{
	return MINHEIGHT;
}
}


kerk::kerk(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=20;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+15, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+15, zblok+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+10, yblok+5, zblok+20);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok+5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok);
		glTexCoord2f(0.0, 2.0);glVertex3f(xblok+10, yblok-5, zblok+20);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-15, zblok+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-15, zblok);
	//achterkant
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-30, yblok+15, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-30, yblok+15, zblok+10);
		glTexCoord2f(3.0, 1.0);glVertex3f(xblok-30, yblok-15, zblok+10);
		glTexCoord2f(3.0, 0.0);glVertex3f(xblok-30, yblok-15, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-30, yblok+15, zblok+10);
		glTexCoord2f(1.5, 1.5);glVertex3f(xblok-30, yblok, zblok+25);
		glTexCoord2f(1.5, 1.5);glVertex3f(xblok-30, yblok, zblok+25);
		glTexCoord2f(3.0, 0.0);glVertex3f(xblok-30, yblok-15, zblok+10);


		//toren
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+5, zblok+10);
		glTexCoord2f(0.0, 2.0);glVertex3f(xblok+10, yblok+5, zblok+30);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+10, yblok-5, zblok+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok+10);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-5, zblok+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok-5, zblok+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-5, zblok+20);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+5, zblok+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+5, zblok+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok+5, zblok+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok+5, zblok+20);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok-5, zblok+20);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok, yblok-5, zblok+30);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok, yblok+5, zblok+30);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok+5, zblok+20);
		//zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-15, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-15, zblok+10);
		glTexCoord2f(4.0, 1.0);glVertex3f(xblok-30, yblok-15, zblok+10);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-30, yblok-15, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+15, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+15, zblok+10);
		glTexCoord2f(4.0, 1.0);glVertex3f(xblok-30, yblok+15, zblok+10);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-30, yblok+15, zblok);
	glEnd();
	//vloer
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-30, yblok-15, zblok+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-30, yblok+15, zblok+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+15, zblok+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-15, zblok+0.1);

	//altaar
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-23, yblok-3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-23, yblok-3, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok-3, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-20, yblok-3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-23, yblok+3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-23, yblok+3, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok+3, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-20, yblok+3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-23, yblok+3, zblok+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-23, yblok-3, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok-3, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-20, yblok+3, zblok+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok-3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok-3, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok+3, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-20, yblok+3, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-23, yblok-3, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-23, yblok-3, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-23, yblok+3, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-23, yblok+3, zblok);
	glEnd();
	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+12, yblok+17, zblok+8);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+12, yblok, zblok+25);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-32, yblok, zblok+25);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-32, yblok+17, zblok+8);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+12, yblok-17, zblok+8);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+12, yblok, zblok+25);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-32, yblok, zblok+25);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-32, yblok-17, zblok+8);
		//toren
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+11, yblok+6, zblok+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-1, yblok+6, zblok+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+11, yblok-6, zblok+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-1, yblok-6, zblok+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+11, yblok+6, zblok+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+11, yblok-6, zblok+28);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok+6, zblok+28);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+5, yblok, zblok+40);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-1, yblok-6, zblok+28);



	glEnd();
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);

}
float kerk::zfunction(float xx,float yy,float zz){
float a; 
if(xx>xblok-30 && xx<xblok+10 && yy>yblok-15 && yy<yblok+15){
	a=zblok+10;//blokkeer alles;
	if(xx>xblok-28 && xx<xblok+8 && yy>yblok-13 && yy<yblok+13)
		a=zblok;//binnen;
	if(xx>xblok+8 && xx<xblok+12 && yy>yblok-5 && yy<yblok+5)
		a=zblok;//deur;
	if(xx>xblok-23 && xx<xblok-20 && yy>yblok-3 && yy<yblok+3)
		a=zblok+3;
	return a;
}else{
	return MINHEIGHT;
}
}



rots::rots(float xx,float yy,float zz,int tt){
	xblok=xx;yblok=yy;hoogteblok=5;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+2.5, yblok+4.33, zblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+5, yblok, zblok-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+2.5, yblok-4.33, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-5, yblok, zblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-2.5, yblok+4.33, zblok-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+2.5, yblok+4.33, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok, zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-5, yblok, zblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-2.5, yblok-4.33, zblok-hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+2.5, yblok-4.33, zblok);

	glEnd();
	if(mining!=0){
		int texx;
		texx=tex;
		if(tex==10)texx=30;
		float xding=xblok;float yding=yblok;float zding=zblok;
		zding=zblok+8-mining;
		glBindTexture(GL_TEXTURE_2D,textures[texx] );
		glBegin(GL_QUADS);
	//onderkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);
	//bovenkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);
	glEnd();
	if(mining>0)mining--;

	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}
float rots::zfunction(float xx,float yy,float zz){
	if(xx>xblok-1 && xx<xblok+1 && yy>yblok-1 && yy<yblok+1){
		return zblok+1.0;
	}else{
		return MINHEIGHT;
	}
}


meteor::meteor(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=320;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+(100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)+100*sin(hoek)), zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+(100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+(-100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+(-100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)-100*sin(hoek)), zblok);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-(100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)+100*sin(hoek)), zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-(100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-(-100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-(-100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)-100*sin(hoek)), zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+(100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)+100*sin(hoek)), zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+(100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-(-100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-(-100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)-100*sin(hoek)), zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-(100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)+100*sin(hoek)), zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-(100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+(-100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+(-100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)-100*sin(hoek)), zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+(100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+(-100*cos(hoek)-20*sin(hoek)), yblok+(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-(100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)+100*sin(hoek)), zblok+hoogteblok);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-(-100*cos(hoek)-20*sin(hoek)), yblok-(20*cos(hoek)-100*sin(hoek)), zblok+hoogteblok);

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
	xblok=xx;yblok=yy;hoogteblok=320;
	xobj=xblok;yobj=yblok;
	zblok= zz;
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
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok+5.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok+5.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok+5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok+5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok+4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok+4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+1, yblok+5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok+5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+1, yblok+4.5, zblok+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok+5.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok+5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+3, yblok+4.5, zblok+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-1, yblok+4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+3, yblok+4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok+5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok+5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok+4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok+4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok+4.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok+4.5, zblok);
		
		//balk2
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok+5.4, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+5.4, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok+5.4, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok+5.4, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok+4.4, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+4.4, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok, yblok+5.4, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+4, yblok+5.4, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok+4.4, zblok+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+5.4, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok+5.4, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-2, yblok+4.4, zblok+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+2, yblok+4.4, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok-2, yblok+4.4, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok+5.4, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok+5.4, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok+4.4, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+4.4, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok+4.4, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok+4.4, zblok);



	//midden balk
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok-5, zblok+2);
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok-5, zblok+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+5, zblok+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok, yblok+5, zblok+2);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok-5, zblok+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+5, zblok+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+1, yblok+5, zblok+3);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+1, yblok-5, zblok+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+1, yblok-5, zblok+2);
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+1, yblok-5, zblok+3);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok+5, zblok+3);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+1, yblok+5, zblok+2);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok-5, zblok+2);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok+5, zblok+2);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+1, yblok+5, zblok+2);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+1, yblok-5, zblok+2);
	//eind
		//balk1
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok-5.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok-5.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok-5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok-5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok-4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok-4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+1, yblok-5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok-5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+1, yblok-4.5, zblok+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok-5.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok-5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+3, yblok-4.5, zblok+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-1, yblok-4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+3, yblok-4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok-5.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok-5.5, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok-3, yblok-4.5, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok+1, yblok-4.5, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok+3, yblok-4.5, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-1, yblok-4.5, zblok);
		
		//balk2
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok-5.6, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok-5.6, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok-5.6, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok-5.6, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok-4.6, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok-4.6, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok, yblok-5.6, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+4, yblok-5.6, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok-4.6, zblok+4);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok-5.6, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok-5.6, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-2, yblok-4.6, zblok+4);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+2, yblok-4.6, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok-2, yblok-4.6, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok-5.6, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok-5.6, zblok);

		glTexCoord2f(0.0, 0.2);glVertex3f(xblok+4, yblok-4.6, zblok);
		glTexCoord2f(0.2, 0.2);glVertex3f(xblok, yblok-4.6, zblok+4);
		glTexCoord2f(0.2, 0.0);glVertex3f(xblok-2, yblok-4.6, zblok+4);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+2, yblok-4.6, zblok);
		
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float hekken::zfunction(float xx,float yy,float zz){
	if(xx>xblok-1 && xx<xblok+1 && yy>yblok-6 && yy<yblok+6){
		return zblok+3.0;
	}else{
		return MINHEIGHT;
	}
}


tarwe::tarwe(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=3;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* tarwe::getnaam(){
	return "tarwe veld";
}
int tarwe::getprijs(){
	return -1;
}
float tarwe::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
	return zblok+0.1;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+30, yblok+i, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+30, yblok+i, zblok+hoogteblok);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok-30, yblok+i, zblok+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-30, yblok+i, zblok);
	
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+i, yblok+30, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+i, yblok+30, zblok+hoogteblok);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok+i, yblok-30, zblok+hoogteblok);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+i, yblok-30, zblok);
	}
		
	glEnd();                     
	glBindTexture(GL_TEXTURE_2D,textures[5] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-34, yblok-34, zblok+0.1);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok-34, yblok+34, zblok+0.1);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok+34, yblok+34, zblok+0.1);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok+34, yblok-34, zblok+0.1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

kruis::kruis(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* kruis::getnaam(){
	return "kruis kerkhof";
}
int kruis::getprijs(){
	return -1;
}
float kruis::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+1 && yy>yblok-1 && yy<yblok+1){
	return zblok+2;
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
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok+0.5, zblok);
		glTexCoord2f(1.0, 0.2);glVertex3f(xblok, yblok+0.5, zblok+5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-0.5, zblok+5);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok-0.5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok+2.0, zblok+3.0);
		glTexCoord2f(0.0, 0.2);glVertex3f(xblok, yblok+2.0, zblok+4.0);
		glTexCoord2f(1.0, 0.2);glVertex3f(xblok, yblok-2.0, zblok+4.0);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-2.0, zblok+3.0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D,textures[5] );
		glBegin(GL_QUADS);
		//aarde graf		
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok+2, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-1, yblok+1, zblok+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-9, yblok+1, zblok+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+2, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok-2, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-1, yblok-1, zblok+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-9, yblok-1, zblok+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-2, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok, yblok+2, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-1, yblok+1, zblok+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-1, yblok-1, zblok+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok, yblok-2, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-2, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-9, yblok-1, zblok+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-9, yblok+1, zblok+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+2, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-9, yblok-1, zblok+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-9, yblok+1, zblok+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-1, yblok+1, zblok+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-1, yblok-1, zblok+1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

ton::ton(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	straal=5;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* ton::getnaam(){
	return "ton";
}
int ton::getprijs(){
	return -1;
}
float ton::zfunction(float xx,float yy,float zz){
if(xx>xblok-straal && xx<xblok+straal && yy>yblok-straal && yy<yblok+straal){
	return zblok+hoogteblok;
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
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+cos(r)*straal, yblok+sin(r)*straal, zblok);
			glTexCoord2f(0.0, 1.0);glVertex3f(xblok+cos(r)*straal, yblok+sin(r)*straal, zblok+hoogteblok);
			glTexCoord2f(1.0, 1.0);glVertex3f(xblok+cos(r+0.2)*straal, yblok+sin(r+0.2)*straal, zblok+hoogteblok);
			glTexCoord2f(1.0, 0.0);glVertex3f(xblok+cos(r+0.2)*straal, yblok+sin(r+0.2)*straal, zblok);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

apotheek::apotheek(float xx,float yy,float zz){
	xblok=xx;yblok=yy;
	xobj=xblok;yobj=yblok;
	zblok= zz;
	toon=0;
}
char* apotheek::getnaam(){
	return "apotheek";
}
int apotheek::getprijs(){
	return -1;
}
float apotheek::zfunction(float xx,float yy,float zz){
if(z<zblok+5){
	if((xx>xblok-20 && xx<xblok+20 && yy>yblok-20 && yy<yblok+20)&&!(xx>xblok-18 && xx<xblok+18 && yy>yblok-18 && yy<yblok+18)&&!(xx>xblok-3 && xx<xblok+3 && yy<yblok-10 && yy>yblok-20)){
		return zblok+10;
	}else if(xx>xblok-20 && xx<xblok+20 && yy<yblok+14 && yy>yblok+10){
		return zblok+3.0;
	}else if(xx>xblok-20 && xx<xblok+20 && yy>yblok-20 && yy<yblok+20){
		return zblok+0.1;
	}else{
		return MINHEIGHT;
	}
}else{//op dak
	if(xx>xblok-20 && xx<xblok+20 && yy>yblok && yy<yblok+20){
		return zblok+30-(yy-yblok);
	}else if(xx>xblok-20 && xx<xblok+20 && yy>yblok-20 && yy<yblok){
		return zblok+30+(yy-yblok);
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
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20+cos(r)*10, yblok+sin(r)*10, zblok);
			glTexCoord2f(0.0, 1.0);glVertex3f(xblok+20+cos(r)*5, yblok+sin(r)*5, zblok+40);
			glTexCoord2f(0.2, 1.0);glVertex3f(xblok+20+cos(r+0.2)*5, yblok+sin(r+0.2)*5, zblok+40);
			glTexCoord2f(0.2, 0.0);glVertex3f(xblok+20+cos(r+0.2)*10, yblok+sin(r+0.2)*10, zblok);
		}
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+19, yblok-19, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+20, yblok-20, zblok+10);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+3, yblok-20, zblok+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+3, yblok-19, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-3, yblok-19, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-3, yblok-20, zblok+10);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-20, yblok-20, zblok+10);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-19, yblok-19, zblok);


		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+19, yblok+19, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+20, yblok+20, zblok+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok-20, yblok+20, zblok+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-19, yblok+19, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+19, yblok+19, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+20, yblok+20, zblok+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok+20, yblok-20, zblok+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+19, yblok-19, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-19, yblok-19, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-20, yblok-20, zblok+10);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok-20, yblok+20, zblok+10);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-19, yblok+19, zblok);
		//boven dak zijkanten

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+20, yblok+20, zblok+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+18, yblok, zblok+10*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok+18, yblok, zblok+10*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok+20, yblok-20, zblok+10);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-20, yblok+20, zblok+10);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok-18, yblok, zblok+10*3);
		glTexCoord2f(1.0, 2.0);glVertex3f(xblok-18, yblok, zblok+10*3);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-20, yblok-20, zblok+10);
		//vloer

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[20] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-19, yblok-19, zblok+0.1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-19, yblok+19, zblok+0.1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+19, yblok+19, zblok+0.1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+19, yblok-19, zblok+0.1);
	glEnd();
	// kasten
	glBindTexture(GL_TEXTURE_2D,textures[31] );
	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+18, yblok+18, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+18, yblok+18,zblok+10-2);
		glTexCoord2f(2.0, 1.0);glVertex3f(xblok-18, yblok+18, zblok+10-2);
		glTexCoord2f(2.0, 0.0);glVertex3f(xblok-18, yblok+18, zblok);
	glEnd();
	//toon bank

	glEnd();
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-19, yblok+10, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-19, yblok+10, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+19, yblok+10, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+19, yblok+10, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-19, yblok+10, zblok+3);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-19, yblok+14, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+19, yblok+14, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+19, yblok+10, zblok+3);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-19, yblok+14, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-19, yblok+14, zblok+3);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+19, yblok+14, zblok+3);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+19, yblok+14, zblok);



	glEnd();

	//dakpannen
	glBindTexture(GL_TEXTURE_2D,textures[25] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+22, yblok+22, zblok+10-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+20, yblok, zblok+10*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-20, yblok, zblok+10*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-22, yblok+22, zblok+10-2);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+22, yblok-22, zblok+10-2);
		glTexCoord2f(0.0, 4.0);glVertex3f(xblok+20, yblok, zblok+10*3);
		glTexCoord2f(4.0, 4.0);glVertex3f(xblok-20, yblok, zblok+10*3);
		glTexCoord2f(4.0, 0.0);glVertex3f(xblok-22, yblok-22, zblok+10-2);
		

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
			sprintf(strtemp,"1)gezondheid(+10) 100 coins");
			glutPrint(-0.45, 0.40, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"2)gezondheid(+100) 1000 coins");
			glutPrint(-0.45, 0.35, strtemp, 1, 1, 1, 0);
			sprintf(strtemp,"3)verbeter power %d coins",rugzak->power*rugzak->power*1000);
			glutPrint(-0.45, 0.30, strtemp, 1, 1, 1, 0);
		}
		glPopMatrix();
}





//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// winkerl gerief
//--------------------------------------------------------->>>

fles::fles(float xx,float yy,float zz,int llevel){
	level=llevel;
	xblok=xx;yblok=yy;hoogteblok=sqrt((float)level)/5.0;
	straal=sqrt((float)level)/10.0;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* fles::getnaam(){
	sprintf(strtempp,"fles gezondheid %d",level);
	return strtempp;
}
int fles::getprijs(){
	return level*level/10.0;
}
float fles::zfunction(float xx,float yy,float zz){
if(xx>xblok-straal && xx<xblok+straal && yy>yblok-straal && yy<yblok+straal){
	return zblok+hoogteblok*3;
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
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+cos(r)*straal, yblok+sin(r)*straal, zblok);
			glTexCoord2f(0.0, 1.0);glVertex3f(xblok+cos(r)*straal*2, yblok+sin(r)*straal*2, zblok+hoogteblok);
			glTexCoord2f(1.0, 1.0);glVertex3f(xblok+cos(r+0.2)*straal*2, yblok+sin(r+0.2)*straal*2, zblok+hoogteblok);
			glTexCoord2f(1.0, 0.0);glVertex3f(xblok+cos(r+0.2)*straal, yblok+sin(r+0.2)*straal, zblok);

			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+cos(r)*straal*2, yblok+sin(r)*straal*2, zblok+hoogteblok);
			glTexCoord2f(0.0, 1.0);glVertex3f(xblok+cos(r)*straal*0.5, yblok+sin(r)*straal*0.5, zblok+hoogteblok*3);
			glTexCoord2f(1.0, 1.0);glVertex3f(xblok+cos(r+0.2)*straal*0.5, yblok+sin(r+0.2)*straal*0.5, zblok+hoogteblok*3);
			glTexCoord2f(1.0, 0.0);glVertex3f(xblok+cos(r+0.2)*straal*2, yblok+sin(r+0.2)*straal*2, zblok+hoogteblok);
		}
	glEnd();
	glColor4f(1.0,0.0,0.0,1.0);
	glBegin(GL_QUADS);
		for(r=0;r<2*3.14;r+=0.2){
			glTexCoord2f(0.0, 0.0);glVertex3f(xblok+cos(r)*0.0, yblok+sin(r)*0.0, zblok+hoogteblok*2);
			glTexCoord2f(0.0, 1.0);glVertex3f(xblok+cos(r)*straal*0.7, yblok+sin(r)*straal*0.7, zblok+hoogteblok*3.5);
			glTexCoord2f(1.0, 1.0);glVertex3f(xblok+cos(r+0.2)*straal*0.7, yblok+sin(r+0.2)*straal*0.7, zblok+hoogteblok*3.5);
			glTexCoord2f(1.0, 0.0);glVertex3f(xblok+cos(r+0.2)*0.0, yblok+sin(r+0.2)*0.0, zblok+hoogteblok*2);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor4fv(color);
}

car::car(float xx,float yy,float zz){
	xblok=xx;yblok=yy;hoogteblok=10;
	xobj=xblok;yobj=yblok;
	zblok= zz;
}
char* car::getnaam(){
	return "Bugatti Veyron";
}
int car::getprijs(){
	return 2200000;
}
float car::zfunction(float xx,float yy,float zz){
if(xx>xblok-10 && xx<xblok+10 && yy>yblok-10 && yy<yblok+10){
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+5, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok-5, zblok+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok-5, zblok+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok-5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok+10, yblok+5, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok+10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok-5, zblok+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-5, zblok);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok-5, zblok+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok-10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok-10, yblok+5, zblok);

		glTexCoord2f(0.0, 0.0);glVertex3f(xblok-10, yblok-5, zblok+2.5);
		glTexCoord2f(0.0, 1.0);glVertex3f(xblok-10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 1.0);glVertex3f(xblok+10, yblok+5, zblok+2.5);
		glTexCoord2f(1.0, 0.0);glVertex3f(xblok+10, yblok-5, zblok+2.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}




geld::geld(float xx,float yy,float zz){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
}
char* geld::getnaam(){
	return "geld";
}
int geld::getprijs(){
	return 1;
}
geld::geld(float xx,float yy){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= 0;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-0.2, yding-0.2, zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.2, yding+0.2, zding+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+0.2, yding+0.2, zding+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+0.2, yding-0.2, zding+hoogteding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float geld::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}



zwaard::zwaard(float xx,float yy,float zz){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
}
char* zwaard::getnaam(){
	return "zwaard";
}
int zwaard::getprijs(){
	return 10;
}
zwaard::zwaard(float xx,float yy){
	xding=xx;yding=yy;hoogteding=0.5;
	xobj=xding;yobj=yding;
	zding= 0;
}
void zwaard::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[19] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-2, yding-0.25, zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-2, yding+0.25, zding+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+2, yding+0.25, zding+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+2, yding-0.25, zding+hoogteding);
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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
	tex=texx;
}

mantel::mantel(float xx,float yy,float zz){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
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
	xding=xx;yding=yy;hoogteding=0.5;
	xobj=xding;yobj=yding;
	zding= 0;
	tex=28;
}
void mantel::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[tex] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-2, yding-3, zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-1, yding+3, zding+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+1, yding+3, zding+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+2, yding-3, zding+hoogteding);
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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
}
char* houweel::getnaam(){
	return "houweel";
}
int houweel::getprijs(){
	return 10;
}
houweel::houweel(float xx,float yy){
	xding=xx;yding=yy;hoogteding=0.5;
	xobj=xding;yobj=yding;
	zding= 0;
}
void houweel::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[21] );
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding-2, yding-0.25, zding+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding-2, yding+0.25, zding+hoogteding);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+2, yding+0.25, zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+2, yding-0.25, zding+hoogteding);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,textures[29] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+2, yding-2, zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+2, yding+2, zding+hoogteding);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+2.5, yding+2, zding+hoogteding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+2.5, yding-2, zding+hoogteding);
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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
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
			return 10;
	}
	return 10;
}
erts::erts(float xx,float yy,int tt){
	tex=tt;
	if(tt==10)tex=30;	//diamand krijgt een andere tecture
	xding=xx;yding=yy;hoogteding=0.5;
	xobj=xding;yobj=yding;
	zding= 0;
}
void erts::draw(){
	float dx,dy;
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[tex] );
	glBegin(GL_QUADS);
	//onderkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);
	//bovenkant
		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding, yding-0.81, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-0.707, yding-0.40, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);

		glTexCoord2f(1.0, 1.0);glVertex3f(xding, yding, zding+1.73);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+0.707, yding+0.40, zding+1.14);
		glTexCoord2f(0.0, 0.0);glVertex3f(xding, yding+0.81, zding+0.57);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-0.707, yding+0.40, zding+1.14);
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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
}
char* kelk::getnaam(){
	return "kelk";
}
int kelk::getprijs(){
	return 1;
}
kelk::kelk(float xx,float yy){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= 0;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xding+cos(u), yding+sin(u), zding+hoogteding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+cos(u)*0.2, yding+sin(u)*0.2, zding+hoogteding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+cos(u+(2*3.1415)/10)*0.2, yding+sin(u+(2*3.1415)/10)*0.2, zding+hoogteding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+cos(u+(2*3.1415)/10), yding+sin(u+(2*3.1415)/10), zding+hoogteding);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding+cos(u)*0.2, yding+sin(u)*0.2, zding+hoogteding+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+cos(u)*0.7, yding+sin(u)*0.7, zding+hoogteding+1.2);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+cos(u+(2*3.1415)/10)*0.7, yding+sin(u+(2*3.1415)/10)*0.7, zding+hoogteding+1.2);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+cos(u+(2*3.1415)/10)*0.2, yding+sin(u+(2*3.1415)/10)*0.2, zding+hoogteding+1);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding+cos(u)*0.7, yding+sin(u)*0.7, zding+hoogteding+1.2);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+cos(u), yding+sin(u), zding+hoogteding+1.7);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+cos(u+(2*3.1415)/10), yding+sin(u+(2*3.1415)/10), zding+hoogteding+1.7);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+cos(u+(2*3.1415)/10)*0.7, yding+sin(u+(2*3.1415)/10)*0.7, zding+hoogteding+1.2);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float kelk::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}

blok::blok(float xx,float yy,float zz){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
}
char* blok::getnaam(){
	return "blok";
}
int blok::getprijs(){
	return 1;
}
blok::blok(float xx,float yy){
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= 0;
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
		glTexCoord2f(0.0, 0.0);glVertex3f(xding-1, yding-1, zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-1, yding-1, zding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+1, yding-1, zding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+1, yding-1, zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding-1, yding+1, zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-1, yding+1, zding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+1, yding+1, zding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+1, yding+1, zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding-1, yding+1, zding+1);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-1, yding-1, zding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+1, yding-1, zding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+1, yding+1, zding+1);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding+1, yding-1, zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding+1, yding-1, zding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding+1, yding+1, zding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding+1, yding+1, zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(xding-1, yding-1, zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(xding-1, yding-1, zding+1);
		glTexCoord2f(1.0, 1.0);glVertex3f(xding-1, yding+1, zding+1);
		glTexCoord2f(1.0, 0.0);glVertex3f(xding-1, yding+1, zding);




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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= zz;
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
	xding=xx;yding=yy;hoogteding=0.1;
	xobj=xding;yobj=yding;
	zding= 0;
	level=levell;
	gezondheid=100;
	hoek=0.0;
	seconds = time (NULL);
}

int slak::actie(zak* koffer,land* temp,int act){
	int i;
	printf("\n vecht slak <----------------------");
	gezondheid=gezondheid-koffer->vechtlevel()*((int)rand()%10);
	koffer->gezondheid=koffer->gezondheid-level*((int)rand()%10);
	if(gezondheid<0){  //if slak dood, verdwijn slak.
		for(i=0;i<temp->objectlijst.size();i++){
			if(temp->objectlijst.at(i)==this){
				temp->objectlijst.erase(temp->objectlijst.begin()+i);	
				return 1;
			}
		}
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
	float afstand=sqrt((y-yding)*(y-yding)+(x-xding)*(x-xding));
	if(afstand<5*mag){//straal 5 bijten
		rugzak->gezondheid=rugzak->gezondheid-ds*level*((int)rand()%10);

	}else if(afstand<20*mag){//straal 20	aanvallen
		float xxding,yyding;
		hoek=atan((y-yding)/(x-xding));
		if((x-xding)>0) hoek=hoek+PI;
		yyding=((y-yding)/afstand)*ds+yding;
		xxding=((x-xding)/afstand)*ds+xding;
		if(zfunction(xxding,yyding,zding)<zding+2){
			//zding=zfunction(xxding,yyding);
			if(floor(yyding/100)==floor(yding/100) && floor(xxding/100) == floor(xding/100)){
				yding=yyding;xding=xxding;
			}
		}
	}else{//blinde wandeling

	}
	glEnable(GL_TEXTURE_2D);   
	glBindTexture(GL_TEXTURE_2D,textures[8] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-2*mag,-0.5*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-2*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+1*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+1*mag,-0.5*mag,hoek), zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-2*mag,+0.5*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-2*mag,+0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+1*mag,+0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+1*mag,+0.5*mag,hoek), zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-2*mag,+0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-2*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+1*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+1*mag,+0.5*mag,hoek), zding+1*mag);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,+1*mag,-0.5*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,+1*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+1*mag,+0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+1*mag,+0.5*mag,hoek), zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-2*mag,-0.5*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-2*mag,-0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,-2*mag,+0.5*mag,hoek), zding+1*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,-2*mag,+0.5*mag,hoek), zding);
	glEnd();
	//schelp gedraaid
	glBindTexture(GL_TEXTURE_2D,textures[22] );
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-1*mag,-0.7*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-1*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+2*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+2*mag,-0.7*mag,hoek), zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-1*mag,+0.7*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-1*mag,+0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+2*mag,+0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+2*mag,+0.7*mag,hoek), zding);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-1*mag,+0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-1*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+2*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+2*mag,+0.7*mag,hoek), zding+2*mag);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,+2*mag,-0.7*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,+2*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,+2*mag,+0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,+2*mag,+0.7*mag,hoek), zding);

		glTexCoord2f(0.0, 0.0);glVertex3f(ROT(xding,yding,-1*mag,-0.7*mag,hoek), zding);
		glTexCoord2f(0.0, 1.0);glVertex3f(ROT(xding,yding,-1*mag,-0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 1.0);glVertex3f(ROT(xding,yding,-1*mag,+0.7*mag,hoek), zding+2*mag);
		glTexCoord2f(1.0, 0.0);glVertex3f(ROT(xding,yding,-1*mag,+0.7*mag,hoek), zding);
	glEnd();
	glDisable(GL_TEXTURE_2D);
		glPushMatrix();
			glLoadIdentity();
			glTranslated(0,0,-1);
			sprintf(str,"slak %d",gezondheid);
			glutPrint(-1, 0.4, str, 1, 1, 1, 0);
		glPopMatrix();
}

float slak::zfunction(float xx,float yy,float zz){
	return MINHEIGHT;
}
