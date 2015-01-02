
//#include "dingen.h"
#ifndef LIJST_H
#define LIJST_H

#ifndef MINHEIGHT
#define MINHEIGHT -100.0
#endif



#include "objecten.h"
#include <vector>


extern char* filenameh[FILEAANTAL];
extern float relief[100][100];
extern GLuint*  textures;
extern float x,y,z,xv,yv;
extern int keyoud,teleport;
extern zak* rugzak;


class zak{
public:
	zak();
	std::vector<object*> zaklijst;
	int maxzak;
	int geld;
	void insertzak(object *);
	int vechtlevel();
	int extravechtlevel();
	int extramaxgezondheid();
	int vechtxp;
	int gezondheid;
	int maxgezondheid;
	int power;
	int vechtpower();
};



class land{
public:
	//static std::vector<land*> landlijst;
	float map[11][11];
	int xland,yland;
	land *boven;
	land *onder;
	land *links;
	land *rechts;
	std::vector<object*> objectlijst;
	land();
	land(int xx,int yy,int sfeer);
	void drawgrond();
	void drawobjecten();
	float zfunction(float xx,float yy,float zzz);
	float zfunctiongrond(float xx,float yy);
	bool isgrond(float xx,float yy);
};

class world{
public:
	land* start;
	land* temp;
	world();
	void makeworld();
	void drawgrond(float xx,float yy);
	void drawobjecten(float xx,float yy);
	float zfunction(float xx,float yy,float zzz);
	void insert(object* obj);
	void actie(float xx,float yy,int act);
};



#endif
