//*********************************************************
//*  objecten
//*********************************************************
#include <iostream>
#include <GL/glut.h>
#include <time.h>
#include "lijst.h"
#include <string>

#ifndef OBJECTEN_H
#define OBJECTEN_H

#ifndef MINHEIGHT
#define MINHEIGHT -100.0
#endif

class zak;
class land;

#define FILEAANTAL 49
extern char* filenameh[FILEAANTAL];
extern float relief[100][100];
extern GLuint*  textures;
extern float x,y,z,xv,yv;
extern int keyoud,teleport;
extern zak* rugzak;


void glutPrint(float xxx, float yyy, char* text, float rr, float gg, float bb, float aa);


class object{
public:
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual char* getnaam();
	virtual int getprijs();
	object(){}
	~object(){}
	float xobj,yobj,zobj;

};


class brughout: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	bool open;
	brughout(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};


class trap: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	trap(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class toren: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	toren(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};


class boomblok: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	boomblok(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};



class winkel: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	winkel(float xx,float yy,float zz);
	winkel(float xx,float yy,float zz,int soortt);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
	int toon;
	int soort;
};


class muurblok: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	muurblok(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class muurx: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	muurx(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class muury: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	muury(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class kasteel:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	kasteel(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};


class kerk:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	kerk(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};
class rots:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	int tex;
	int mining;
	rots(float xx,float yy,float zz,int tt);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class meteor:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	meteor(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class boom:public object{
public:
	float xboom;
	float yboom;
	float zboom;
	float hoogteboom;
	boom(float xx,float yy,float zz,float hhoogte);
	boom(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class hekken:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	hekken(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class tarwe: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	tarwe(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class kruis: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	kruis(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class ton: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	float straal;
	ton(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class apotheek: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	int toon;
	apotheek(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class tafel: public object{
public:
	float hoogteblok;
	tafel(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// mensen
//--------------------------------------------------------->>>
class mens: public object{
public:
	float hoogteblok;
	mens(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
	float mag;
};

class priest: public object{
public:
	float hoogteblok;
	priest(float xx,float yy,float zz,std::string temp);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
	float mag;
	int toon;
	std::string text;
};


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// TUNNEL
//--------------------------------------------------------->>>

class luik: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float telx,tely,telz;
	float hoogteblok;
	luik(float xx,float yy,float zz,float telxx,float telyy,float telzz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};


class tunnelx: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float telx,tely,telz;
	float hoogteblok;
	tunnelx(float xx,float yy,float zz,float telxx,float telyy,float telzz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class tunnelminx: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float telx,tely,telz;
	float hoogteblok;
	tunnelminx(float xx,float yy,float zz,float telxx,float telyy,float telzz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class tunnelxx: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	tunnelxx(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// winkerl gerief
//--------------------------------------------------------->>>

class fles: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	float straal;
	int level;
	fles(float xx,float yy,float zz,int llevel);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};


class car: public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	car(float xx,float yy,float zz);
	virtual float zfunction(float xx,float yy,float zz);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual int getprijs();
	virtual char* getnaam();
};

class geld:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	geld(float xx,float yy,float zz);
	geld(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};


class zwaard:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	zwaard(float xx,float yy,float zz);
	zwaard(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class mantel:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	int tex;
	mantel(float xx,float yy,float zz,int texx);
	mantel(float xx,float yy,float zz);
	mantel(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class houweel:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	houweel(float xx,float yy,float zz);
	houweel(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};


class erts:public object{
public:
	float xding;
	float yding;
	float zding;
	int tex;
	float hoogteding;
	erts(float xx,float yy,float zz,int tt);
	erts(float xx,float yy,int tt);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class kelk:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	kelk(float xx,float yy,float zz);
	kelk(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

class blok:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	int tex;
	blok(float xx,float yy,float zz);
	blok(float xx,float yy);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};



class kader:public object{
public:
	float xblok;
	float yblok;
	float zblok;
	float hoogteblok;
	int foto;
	kader(float xx,float yy,float zz,int ff);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};













//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// vijand
//--------------------------------------------------------->>>

class slak:public object{
public:
	float xding;
	float yding;
	float zding;
	float hoogteding;
	int level;
	int gezondheid;
	float hoek;
	time_t seconds;
	zak* kofferr;
	slak(float xx,float yy,float zz,int levell);
	slak(float xx,float yy,int levell);
	virtual void draw();
	virtual int actie(zak* koffer,land* temp,int act);
	virtual float zfunction(float xx,float yy,float zz);
	virtual int getprijs();
	virtual char* getnaam();
};

#endif
