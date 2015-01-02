//*********************************************************
//*  wereld lijst
//*********************************************************
#include "lijst.h"
#include "objecten.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string>
std::vector<land*> landlijst;

extern char* filenameh[FILEAANTAL];
extern float relief[100][100];
extern GLuint*  textures;
extern float x,y,z,xv,yv;
extern int keyoud,teleport;
extern zak* rugzak;





// **********************************************************************
// ZAK class functions
// **********************************************************$->->->->->->_�_<-<-<-<-<-<-<

zak::zak(){
	maxzak=5;
	geld=100;
	gezondheid=100;
	maxgezondheid=100;
	vechtxp=0;
	power=1;
}
int zak::vechtlevel(){
	int i;
	int uitrusting=1;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string str1 = rugzak->zaklijst.at(i)->getnaam();
		if(str1.compare("houweel")==0 ){
			if(uitrusting<2)uitrusting=2;
		}
		if(str1.compare("zwaard")==0) {
			if(uitrusting<3)uitrusting=3;
		}

	}
	return uitrusting*(((int)sqrt((float)vechtxp/100.0))+1.0)*power;
}


int zak::extravechtlevel(){
	int i;
	int bonus=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string str1 = rugzak->zaklijst.at(i)->getnaam();
		if(str1.compare("mantel aarde")==0 )		bonus=bonus+10;
	}
	return bonus;
}


int zak::extramaxgezondheid(){
	int i;
	int bonus=0;
	for(i=0;i<rugzak->zaklijst.size();i++){
		std::string str1 = rugzak->zaklijst.at(i)->getnaam();
		if(str1.compare("mantel water")==0 )		bonus=bonus+50;
	}
	return bonus;
}



void zak::insertzak(object *obj){
	if(zaklijst.size()<=maxzak){
		zaklijst.push_back(obj);
	}else{
	//waarschuwing zak zit vol.
	}
}

// **********************************************************************
// LAND class functions
// **********************************************************$->->->->->->_�_<-<-<-<-<-<-<
land::land(){
	boven=NULL;
	onder=NULL;
	links=NULL;
	rechts=NULL;
	int i,j,k;
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
				map[i][j]=0.0;
		}
	}
	xland=0;yland=0;
	landlijst.push_back(this);
}


land::land(int xx,int yy,int sfeer){
	int i,j,k;
	boven=NULL;
	onder=NULL;
	links=NULL;
	rechts=NULL;
	xland=xx;yland=yy;
	
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			if(sfeer==1){
				map[i][j]=10.0;
			}else if(sfeer==200){
				map[i][j]=(rand()%5)+2.0;
			}else if(sfeer==2){
				map[i][j]=-6.0;
			}else if(sfeer==101){
				map[i][j]=2.0;
				if(i==1)map[i][j]=-3.0;
				if(j==1)map[i][j]=-3.0;
			}else if(sfeer==102){
				map[i][j]=2.0;
				if(i==1)map[i][j]=-3.0;
				if(j==9)map[i][j]=-3.0;
			}else if(sfeer==103){
				map[i][j]=2.0;
				if(i==9)map[i][j]=-3.0;
				if(j==1)map[i][j]=-3.0;
			}else if(sfeer==104){
				map[i][j]=2.0;
				if(i==9)map[i][j]=-3.0;
				if(j==9)map[i][j]=-3.0;
			}else{
				map[i][j]=2.0;
			}
		}
	}
	/*
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			relief[i][j]=(float) (rand()%100);
			if(i==0||j==0||i==99||j==99)
				map[i][j]=100.;
		}
	}
	for(k=0;k<10;k++){
	for(i=1;i<99;i++){
		for(j=1;j<99;j++){
			map[i][j]=(4*map[i][j]+map[i+1][j]+map[i-1][j]+map[i][j+1]+map[i][j-1])/8;
		}
	}
	}
	*/
	for(i=0;i<landlijst.size();i++){
		if(landlijst.at(i)->xland==xx && landlijst.at(i)->yland ==yy+1){
			landlijst.at(i)->onder=this;
			boven=landlijst.at(i);
			for(j=0;j<11;j++){
				map[j][10]=0.5*(landlijst.at(i)->map[j][0]+map[j][10]);
				landlijst.at(i)->map[j][0]=map[j][10];
			}
		}
		if(landlijst.at(i)->xland==xx && landlijst.at(i)->yland ==yy-1){
			landlijst.at(i)->boven=this;
			onder=landlijst.at(i);
			for(j=0;j<11;j++){
				map[j][0]=0.5*(landlijst.at(i)->map[j][10]+map[j][0]);
				landlijst.at(i)->map[j][10]=map[j][0];
			}
		}
		if(landlijst.at(i)->xland==xx+1 && landlijst.at(i)->yland ==yy){
			landlijst.at(i)->links=this;
			rechts=landlijst.at(i);
			for(j=0;j<11;j++){
				map[10][j]=0.5*(landlijst.at(i)->map[0][j]+map[10][j]);
				landlijst.at(i)->map[0][j]=map[10][j];
			}
		}
		if(landlijst.at(i)->xland==xx-1 && landlijst.at(i)->yland ==yy){
			landlijst.at(i)->rechts=this;
			links=landlijst.at(i);
			for(j=0;j<11;j++){
				map[0][j]=0.5*(landlijst.at(i)->map[10][j]+map[0][j]);
				landlijst.at(i)->map[10][j]=map[0][j];
			}
		}
	}
	//randdom bomen toevoegen
	if(sfeer==0){
		float xxx,yyy;
		for(i=0;i<10;i++){
		xxx=100*xland+((int)rand())%100;
		yyy=100*yland+((int)rand())%100;
		if(isgrond(xxx,yyy))objectlijst.push_back(new boomblok(xxx,yyy,zfunctiongrond(xxx,yyy)));
		}
	}
	if(sfeer==201){
		float xxx,yyy;
		for(i=0;i<10;i++){
		xxx=100*xland+((int)rand())%100;
		yyy=100*yland+((int)rand())%100;
		if(isgrond(xxx,yyy))objectlijst.push_back(new boomblok(xxx,yyy,zfunctiongrond(xxx,yyy)));
		}
	}

	//hekkens toevoegen bij wildernis

	/***********************************************************************************
	/* beesten en grondstoffen bij de wildernis 
	/**********************************************************************************/
	if(sfeer==0 && xland==3){
		float xxx,yyy;
		for(i=0;i<10;i++){
			if(isgrond(350,yland*100+5+i*10))objectlijst.push_back(new hekken(350,yland*100+5+i*10,zfunctiongrond(350,yland*100+5+i*10)));
		}
	}
	if(sfeer==0 && xland>3){
		float xxx,yyy;
		float test;
		for(i=0;i<3;i++){
			xxx=100*xland+((int)rand())%100;
			yyy=100*yland+((int)rand())%100;
			if(isgrond(xxx,yyy))objectlijst.push_back(new slak(xxx,yyy,zfunctiongrond(xxx,yyy),xland-3));
		}
		if(xland>5){//kool
			for(i=0;i<3;i++){
				xxx=100*xland+((int)rand())%100;
				yyy=100*yland+((int)rand())%100;
				if(isgrond(xxx,yyy))objectlijst.push_back(new rots(xxx,yyy,zfunctiongrond(xxx,yyy),6));
			}
		}
		if(xland>8){//kool
			for(i=0;i<3;i++){
				xxx=100*xland+((int)rand())%100;
				yyy=100*yland+((int)rand())%100;
				if(isgrond(xxx,yyy))objectlijst.push_back(new rots(xxx,yyy,zfunctiongrond(xxx,yyy),7));
			}
		}
		if(xland>9){//kool
			for(i=0;i<1;i++){
				xxx=100*xland+((int)rand())%100;
				yyy=100*yland+((int)rand())%100;
				if(isgrond(xxx,yyy))objectlijst.push_back(new rots(xxx,yyy,zfunctiongrond(xxx,yyy),8));
			}
		}
		if(xland>15){//kool
			for(i=0;i<2;i++){
				xxx=100*xland+((int)rand())%100;
				yyy=100*yland+((int)rand())%100;
				if(isgrond(xxx,yyy))objectlijst.push_back(new rots(xxx,yyy,zfunctiongrond(xxx,yyy),9));
			}
		}
		if(xland>30){//kool
			for(i=0;i<2;i++){
				xxx=100*xland+((int)rand())%100;
				yyy=100*yland+((int)rand())%100;
				if(isgrond(xxx,yyy))objectlijst.push_back(new rots(xxx,yyy,zfunctiongrond(xxx,yyy),30));
			}
		}

	}







	//hoekpunten hoogte oplossen
	float som;
	int aantal;
	//debug stop
	if(yy==-1 && xx==1){
		printf("start debug");
	}
	aantal=1;som=map[0][0];
	if(onder!=NULL){
		som+=onder->map[0][10];
		aantal++;
	}
	if(links!=NULL){
		som+=links->map[10][0];
		aantal++;
		if(links->onder!=NULL){
			som+=links->onder->map[10][10];
			aantal++;
		}
	}

	map[0][0]=som/aantal;
	if(onder!=NULL)onder->map[0][10]=som/aantal;
	if(links!=NULL){links->map[10][0]=som/aantal;
	if(links->onder!=NULL)links->onder->map[10][10]=som/aantal;
	}
	aantal=1;som=map[10][0];
	if(onder!=NULL){
		som+=onder->map[10][10];
		aantal++;
	}
	if(rechts!=NULL){
		som+=rechts->map[0][0];
		aantal++;
		if(rechts->onder!=NULL){
			som+=rechts->onder->map[0][10];
			aantal++;
		}	
	}

	map[10][0]=som/aantal;
	if(onder!=NULL)onder->map[10][10]=som/aantal;
	if(rechts!=NULL){rechts->map[0][0]=som/aantal;
	if(rechts->onder!=NULL)rechts->onder->map[0][10]=som/aantal;
	}
	aantal=1;som=map[0][10];
	if(boven!=NULL){
		som+=boven->map[0][0];
		aantal++;
	}
	if(links!=NULL){
		som+=links->map[10][10];
		aantal++;
		if(links->boven!=NULL){
			som+=links->boven->map[10][0];
			aantal++;
		}
	}

	map[0][10]=som/aantal;
	if(boven!=NULL)boven->map[0][0]=som/aantal;
	if(links!=NULL){links->map[10][10]=som/aantal;
	if(links->boven!=NULL)links->boven->map[10][0]=som/aantal;
	}
	aantal=1;som=map[10][10];
	if(boven!=NULL){
		som+=boven->map[10][0];
		aantal++;
	}
	if(rechts!=NULL){
		som+=rechts->map[0][10];
		aantal++;
		if(rechts->boven!=NULL){
			som+=rechts->boven->map[0][0];
			aantal++;
		}
	}

	map[10][10]=som/aantal;
	if(boven!=NULL)boven->map[10][0]=som/aantal;
	if(rechts!=NULL){rechts->map[0][10]=som/aantal;
	if(rechts->boven!=NULL)rechts->boven->map[0][0]=som/aantal;
	}

	landlijst.push_back(this);
}

void land::drawgrond(){
	int i,j;
	float a,b,c,d;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[0] );
	glBegin(GL_QUADS);
	
	if(links==NULL){
		a=map[0][0];
		b=map[0][1];
	}else{
		a=links->map[10][0];
		b=links->map[10][1];
	}

	if(onder==NULL){
		c=map[0][0];
		d=map[1][0];
	}else{
		c=onder->map[0][10];
		d=onder->map[1][10];
	}

	glNormal3f(a-map[0][0],map[0][0]-c,1.0);
	glTexCoord2f(0.0, 0.0);glVertex3f(xland*100, yland*100, map[0][0]);
	glNormal3f(b-map[0][1],map[0][1]-map[0][0],1.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(xland*100,10+yland*100, map[0][1]);
	glNormal3f(map[0][1]-map[1][1],map[1][1]-map[1][0],1.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(10+xland*100, 10+yland*100, map[1][1]);
	glNormal3f(map[0][0]-map[1][0],map[1][0]-d,1.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(10+xland*100,yland*100, map[1][0]);
	
	for(i=1;i<10;i++){
	if(onder==NULL){
		c=map[i][0];
		d=map[i+1][0];
	}else{
		c=onder->map[i][10];
		d=onder->map[i+1][10];
	}
	glNormal3f(map[i-1][0]-map[i][0],map[i][0]-c,1.0);
	glTexCoord2f(0.0, 0.0);glVertex3f(10*i+xland*100, 10*0+yland*100, map[i][0]);
	glNormal3f(map[i-1][1+0]-map[i][1+0],map[i][1+0]-map[i][1+0-1],1.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(10*i+xland*100, 10*0+10+yland*100, map[i][0+1]);
	glNormal3f(map[1+i-1][1+0]-map[1+i][1+0],map[1+i][1+0]-map[1+i][1+0-1],1.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(10*i+10+xland*100, 10*0+10+yland*100, map[i+1][0+1]);
	glNormal3f(map[1+i-1][0]-map[1+i][0],map[1+i][0]-d,1.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(10*i+10+xland*100,10*0+yland*100, map[i+1][0]);
	}

	for(j=1;j<10;j++){
	if(links==NULL){
		a=map[0][j];
		b=map[0][1+j];
	}else{
		a=links->map[10][j];
		b=links->map[10][1+j];
	}
	glNormal3f(a-map[0][j],map[0][j]-map[0][j-1],1.0);
	glTexCoord2f(0.0, 0.0);glVertex3f(10*0+xland*100, 10*j+yland*100, map[0][j]);
	glNormal3f(b-map[0][1+j],map[0][1+j]-map[0][1+j-1],1.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(10*0+xland*100, 10*j+10+yland*100, map[0][j+1]);
	glNormal3f(map[1+0-1][1+j]-map[1+0][1+j],map[1+0][1+j]-map[1+0][1+j-1],1.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(10*0+10+xland*100, 10*j+10+yland*100, map[0+1][j+1]);
	glNormal3f(map[1+0-1][j]-map[1+0][j],map[1+0][j]-map[1+0][j-1],1.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(10*0+10+xland*100,10*j+yland*100, map[0+1][j]);

	}

	for(i=1;i<10;i++){
	for(j=1;j<10;j++){
	//glNormal3f(map[i+1][j]-map[i][j+1]+map[i+1][j+1]-map[i][j],map[i+1][j]-map[i][j+1]-map[i+1][j+1]+map[i][j],2.0);//totaal viekant normal
	
	/* normale over kruis
	glNormal3f(map[i-1][j]-map[i+1][j],map[i][j+1]-map[i][j-1],1.0);
	glTexCoord2f(0.0, 0.0);glVertex3f(10*i+xland*100, 10*j+yland*100, map[i][j]);
	glNormal3f(map[i-1][1+j]-map[i+1][1+j],map[i][1+j+1]-map[i][1+j-1],1.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(10*i+xland*100, 10*j+10+yland*100, map[i][j+1]);
	glNormal3f(map[1+i-1][1+j]-map[1+i+1][1+j],map[1+i][1+j+1]-map[1+i][1+j-1],1.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(10*i+10+xland*100, 10*j+10+yland*100, map[i+1][j+1]);
	glNormal3f(map[1+i-1][j]-map[1+i+1][j],map[1+i][j+1]-map[1+i][j-1],1.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(10*i+10+xland*100,10*j+yland*100, map[i+1][j]);
	*/
	//normale door halve kruis naar x-1 en y-1
	glNormal3f(map[i-1][j]-map[i][j],map[i][j]-map[i][j-1],1.0);
	glTexCoord2f(0.0, 0.0);glVertex3f(10*i+xland*100, 10*j+yland*100, map[i][j]);
	glNormal3f(map[i-1][1+j]-map[i][1+j],map[i][1+j]-map[i][1+j-1],1.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(10*i+xland*100, 10*j+10+yland*100, map[i][j+1]);
	glNormal3f(map[1+i-1][1+j]-map[1+i][1+j],map[1+i][1+j]-map[1+i][1+j-1],1.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(10*i+10+xland*100, 10*j+10+yland*100, map[i+1][j+1]);
	glNormal3f(map[1+i-1][j]-map[1+i][j],map[1+i][j]-map[1+i][j-1],1.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(10*i+10+xland*100,10*j+yland*100, map[i+1][j]);
	}
	}
	glEnd();


	glBindTexture(GL_TEXTURE_2D,textures[4] );
	glBegin(GL_QUADS);
	

	glTexCoord2f(0.0, 0.0);glVertex3f(xland*100, yland*100,0.0);
	glTexCoord2f(0.0, 1.0);glVertex3f(xland*100, 100+yland*100,0.0);
	glTexCoord2f(1.0, 1.0);glVertex3f(100+xland*100,100+yland*100, 0.0);
	glTexCoord2f(1.0, 0.0);glVertex3f(100+xland*100,yland*100, 0.0);

	glEnd();
	glDisable(GL_TEXTURE_2D);


}
void land::drawobjecten(){
	int i;
	for(i=0;i<objectlijst.size();i++){
		objectlijst.at(i)->draw();
	}
}

float land::zfunctiongrond(float xx,float yy){
	int xxx=((int)floor(xx/10))-10*((int)floor(xx/100));
	int yyy=((int)floor(yy/10))-10*((int)floor(yy/100));
	float dx=(xx-(floor(xx/10)*10))/10.0;
	float dy=(yy-(floor(yy/10)*10))/10.0;
	float zz=(1.0-dy)*(dx*map[xxx+1][yyy]+(1.0-dx)*map[xxx][yyy])+dy*(dx*map[xxx+1][yyy+1]+(1.0-dx)*map[xxx][yyy+1]);
	return zz;
}



float land::zfunction(float xx,float yy,float zzz){
	int i;
	if(zzz>-100){//boven grond
	int xxx=((int)floor(xx/10))-10*((int)floor(xx/100));
	int yyy=((int)floor(yy/10))-10*((int)floor(yy/100));
	float dx=(xx-(floor(xx/10)*10))/10.0;
	float dy=(yy-(floor(yy/10)*10))/10.0;
	float zz=(1.0-dy)*(dx*map[xxx+1][yyy]+(1.0-dx)*map[xxx][yyy])+dy*(dx*map[xxx+1][yyy+1]+(1.0-dx)*map[xxx][yyy+1]);
	for(i=0;i<objectlijst.size();i++){
		if(zz<objectlijst.at(i)->zfunction(xx,yy,zzz))zz=objectlijst.at(i)->zfunction(xx,yy,zzz);
	}
	return zz;
	}else{//ondergrond
		float zz=-300;
		for(i=0;i<objectlijst.size();i++){
			if(zz<objectlijst.at(i)->zfunction(xx,yy,zzz)&&objectlijst.at(i)->zfunction(xx,yy,zzz)<-100)zz=objectlijst.at(i)->zfunction(xx,yy,zzz);
		}
		return zz;
	}
}

bool land::isgrond(float xx,float yy){
	int i;
	for(i=0;i<objectlijst.size();i++){
		if(MINHEIGHT<objectlijst.at(i)->zfunction(xx,yy,0)) return false;
	}
	return true;
}
// **********************************************************************
// WORLD class functions
// **********************************************************$->->->->->->_�_<-<-<-<-<-<-<


world::world(){
	start=NULL;
	temp=NULL;
}

void world::makeworld(){
	int i,j;
	start=new land(0,0,1);

	start->onder=new land(start->xland,start->yland-1,2);
	start->onder->onder=new land(start->xland,start->yland-2,2);
	start->onder->onder->links=new land(start->xland-1,start->yland-2,2);
	start->onder->onder->rechts=new land(start->xland+1,start->yland-2,2);
	start->boven=new land(start->xland,start->yland+1,0);
	start->links=new land(start->xland-1,start->yland,1);
	start->links->onder=new land(start->xland-1,start->yland-1,2);
	start->links->boven=new land(start->xland-1,start->yland+1,1);
	start->links->boven->boven=new land(start->xland-1,start->yland+2,3);
	start->links->boven->boven->boven=new land(start->xland-1,start->yland+3,3);
	start->links->boven->boven->boven->boven=new land(start->xland-1,start->yland+4,2);
	start->links->boven->boven->boven->boven->links=new land(start->xland-2,start->yland+4,2);
	start->links->boven->boven->boven->boven->rechts=new land(start->xland,start->yland+4,2);
	start->links->boven->boven->boven->boven->boven=new land(start->xland-1,start->yland+5,0);
	start->links->boven->boven->boven->boven->boven->links=new land(start->xland-2,start->yland+5,0);
	start->links->boven->boven->boven->boven->boven->rechts=new land(start->xland,start->yland+5,0);
	start->links->boven->boven->boven->boven->boven->boven=new land(start->xland-1,start->yland+6,1);
	start->links->boven->boven->boven->boven->boven->boven->links=new land(start->xland-2,start->yland+6,1);
	start->links->boven->boven->boven->boven->boven->boven->rechts=new land(start->xland,start->yland+6,1);
	start->links->boven->boven->boven->boven->boven->boven->boven=new land(start->xland-1,start->yland+7,1);
	start->links->boven->boven->boven->boven->boven->boven->boven->links=new land(start->xland-2,start->yland+7,1);
	start->links->boven->boven->boven->boven->boven->boven->boven->rechts=new land(start->xland,start->yland+7,1);
	start->links->links=new land(start->xland-2,start->yland,1);
	start->links->links->onder=new land(start->xland-2,start->yland-1,2);
	start->links->links->boven=new land(start->xland-2,start->yland+1,1);
	start->rechts=new land(start->xland+1,start->yland,1);
	start->rechts->onder=new land(start->xland+1,start->yland-1,0);
	start->rechts->boven=new land(start->xland+1,start->yland+1,101);
	start->rechts->boven->boven=new land(start->xland+1,start->yland+2,102);
	start->rechts->boven->rechts=new land(start->xland+2,start->yland+1,103);
	start->rechts->boven->rechts->boven=new land(start->xland+2,start->yland+2,104);



	insert(new rots(0,0,zfunction(0,0,0),20));
	insert(new rots(10,0,zfunction(10,0,0),20));
	insert(new rots(0,10,zfunction(0,10,0),20));
	insert(new rots(20,0,zfunction(20,0,0),20));

	


	insert(new mantel(-150,-50,zfunction(-150,-50,0),35));//watermantel
	insert(new mantel(-150,150,zfunction(-150,150,0)+1,37));//aardemantel
	
	
	//omwalde stad
	for(i=0;i<6;i++){
		if(i!=3)
		insert(new muury(130,150+i*20,zfunction(130,150+i*20,0)));
		insert(new muurx(150+i*20,130,zfunction(150+i*20,130,0)));
		if(i!=3)
		insert(new muury(270,150+i*20,zfunction(270,150+i*20,0)));
		insert(new muurx(150+i*20,270,zfunction(150+i*20,270,0)));
	}
	insert(new brughout(110,210,2.0));
	insert(new trap(250,210,zfunction(250,210,0)));
	insert(new muurblok(270,210,zfunction(270,210,0)));
	insert(new toren(130,130,zfunction(130,130,0)));
	insert(new toren(130,270,zfunction(130,270,0)));
	insert(new toren(270,130,zfunction(270,130,0)));
	insert(new toren(270,270,zfunction(270,270,0)));
	insert(new apotheek(230,240,zfunction(230,240,0)));
	insert(new winkel(170,170,zfunction(170,170,0),0));
	insert(new luik(145,155,zfunction(145,155,0),150.0,150.0,-200.0));
	//de tafel
	insert(new tafel(165,240,zfunction(165,240,0)));
	insert(new houweel(170,240,zfunction(170,240,0)));
	insert(new zwaard(167,240,zfunction(167,240,0)));
	insert(new geld(163,240,zfunction(163,240,0)));
	//ondergronds
	insert(new tunnelx(150,150,-200,145.0,155.0,zfunction(145,155,0)));
	insert(new tunnelxx(150,250,-200));
	insert(new tunnelxx(150,350,-200));
	insert(new tunnelminx(150,450,-200,-76.0,50.0,zfunction(-76.0,50.0,0)));
	//boerderij en kerk
	for(j=0;j<4;j++){
	for(i=0;i<6;i++) insert(new kruis(60-j*15,20+i*10,zfunction(60-j*15,20+i*10,0)));
	}
	insert(new priest(75,50,zfunction(75,50,0),"hoi ik ben nico de priest. Omdat ons dorp wordt aangevallen is de poort van het fort dicht. Nu kunnen wij niet meer binnen. help ons en open de poort. Er is een geheime tunnel die naar het fort leid."));
	insert(new kerk(-50,50,zfunction(-50,50,0)));
	insert(new luik(-76.0,50.0,zfunction(-76.0,50.0,0),150.0,450.0,-200.0));
	insert(new kelk(-72,50,zfunction(-72,50,0)-3));
	insert(new fles(-43,38,zfunction(-43,38,0),100));
	insert(new tarwe(-50,150,zfunction(-50,150,0)));
	insert(new tarwe(-150,150,zfunction(-150,150,0)));
	insert(new tarwe(-150,50,zfunction(-150,50,0)));
	insert(new car(-410,110,zfunction(-410,110,0)));
    //bijkamer
	//insert(new toren(270,300,2.5));
	insert(new toren(270,287,2));
	insert(new kelk(270,295,2));
	//toren waterkasteel
	for(i=0;i<10;i++){
	insert(new muurblok(-50,190+i*20,-7));
	}
	for(i=0;i<7;i++){
	insert(new muury(-50,390+i*20,-6+4.5-(i-3)*(i-3)/2.0));
	}
	for(i=0;i<10;i++){
		insert(new boomblok(-25,190+i*20,-25));
		insert(new boomblok(-75,190+i*20,-25));
	}


	//kasteel2
	insert(new toren(90,610,3));
	for(i=1;i<7;i++){
	insert(new muurx(90-i*20,610,4));
	}

	for(i=8;i<14;i++){
	insert(new muurx(90-i*20,610,4));
	}
	insert(new toren(-190,610,3));


	insert(new toren(70,630,10));
	insert(new toren(70,630,20));
	for(i=1;i<6;i++){
	insert(new muurx(70-i*20,630,10));
	insert(new muurx(70-i*20,630,20));
	}

	for(i=7;i<12;i++){
	insert(new muurx(70-i*20,630,10));
	insert(new muurx(70-i*20,630,20));
	}
	insert(new toren(-170,630,10));
	insert(new toren(-170,630,20));




	for(i=1;i<9;i++){
	insert(new muury(90,610+i*20,4));
	insert(new muury(-190,610+i*20,4));
	}

	for(i=1;i<7;i++){
	insert(new muury(70,630+i*20,10));
	insert(new muury(70,630+i*20,20));
	insert(new muury(-170,630+i*20,10));
	insert(new muury(-170,630+i*20,20));
	}


	insert(new toren(70,770,10));
	insert(new toren(70,770,20));
	for(i=1;i<12;i++){
	insert(new muurx(70-i*20,770,10));
	insert(new muurx(70-i*20,770,20));
	}
	insert(new toren(-170,770,10));
	insert(new toren(-170,770,20));


	insert(new toren(90,790,2));
	for(i=1;i<14;i++){
	insert(new muurx(90-i*20,790,4));
	}
	insert(new toren(-190,790,2));


	//trap
	for(i=1;i<5;i++){
	insert(new muurblok(70-i*20,750,10-4*i));
	insert(new muurblok(70-i*20,750,20-4*i));
	}


	//toren
	brughout* plankje=new brughout(90,630,33.0);
	plankje->open=true;
	insert(plankje);
	plankje=new brughout(-50,630,30.0);
	plankje->open=true;
	insert(plankje);



	insert(new meteor(600,-200,0));



	insert(new toren(110,630,2));
	insert(new toren(110,630,10));
	insert(new toren(110,630,20));
	insert(new toren(110,610,2));
	insert(new toren(110,610,10));
	insert(new toren(110,610,20));
	insert(new toren(110,610,24));
	insert(new toren(110,590,2));
	insert(new toren(110,590,10));
	insert(new toren(110,590,20));
	insert(new toren(110,590,28));

	//kaders
	for(i=0;i<8;i++){
	insert(new kader(-30-10*i,759.9,10,38+i));
	}


	//kerk2
	for(i=-1;i<2;i++){
		for(j=0;j<4;j++){
			insert(new muurblok(-110-j*20,670+i*20,3));
		}
	}
	insert(new kerk(-120,670,13));
	insert(new kader(-145,684.9,13,46));

}

void world::drawgrond(float xx,float yy){
//#define LOW
#define HIGH
	land *loop;
	land *oudloop;
	int i,j,ii,jj;
	i=0;
	if(temp==NULL) temp=start;
	while(temp->xland!=(int)floor(xx/100) || temp->yland!=(int)floor(yy/100)){
		if(i>=landlijst.size()){
			//maak een nieuw land aan;
			temp=new land((int)floor(xx/100),(int)floor(yy/100),0);
			break;
		}
		temp=landlijst.at(i);
		i++;
	}
#ifdef LOW
	temp->drawgrond();
	if(temp->links==NULL)temp->links=new land(temp->xland-1,temp->yland,0);
	temp->links->drawgrond();
	
	if(temp->links->boven==NULL)temp->links->boven=new land(temp->xland-1,temp->yland+1,0);
	temp->links->boven->drawgrond();
	
	if(temp->boven==NULL)temp->boven=new land(temp->xland,temp->yland+1,0);
	temp->boven->drawgrond();

	if(temp->rechts==NULL)temp->rechts=new land(temp->xland+1,temp->yland,0);
	temp->rechts->drawgrond();

	if(temp->rechts->boven==NULL)temp->rechts->boven=new land(temp->xland+1,temp->yland+1,0);
	temp->rechts->boven->drawgrond();

	if(temp->rechts->onder==NULL)temp->rechts->onder=new land(temp->xland+1,temp->yland-1,0);
	temp->rechts->onder->drawgrond();

	if(temp->onder==NULL)temp->onder=new land(temp->xland,temp->yland-1,0);
	temp->onder->drawgrond();

	if(temp->links->onder==NULL)temp->links->onder=new land(temp->xland-1,temp->yland-1,0);
	temp->links->onder->drawgrond();
#endif
#ifdef HIGH



	for(i=-3;i<4;i++){
		for(j=-3;j<4;j++){
			loop=temp;
			if(i>0){
				for(ii=0;ii<i;ii++){
					oudloop=loop;
					loop=loop->rechts;
					if(loop==NULL){
						oudloop->rechts=new land(oudloop->xland+1,oudloop->yland,0);
						loop=oudloop->rechts;
					}
				}
			}
			if(i<0){
				for(ii=0;ii>i;ii--){
					oudloop=loop;
					loop=loop->links;
					if(loop==NULL){
						oudloop->links=new land(oudloop->xland-1,oudloop->yland,0);
						loop=oudloop->links;
					}
				}
			}
			if(j>0){
				for(jj=0;jj<j;jj++){
					oudloop=loop;
					loop=loop->boven;
					if(loop==NULL){
						oudloop->boven=new land(oudloop->xland,oudloop->yland+1,0);
						loop=oudloop->boven;
					}
				}
			}
			if(j<0){
				for(jj=0;jj>j;jj--){
					oudloop=loop;
					loop=loop->onder;
					if(loop==NULL){
						oudloop->onder=new land(oudloop->xland,oudloop->yland-1,0);
						loop=oudloop->onder;
					}
				}
			}

		loop->drawgrond();
		loop->drawobjecten();
//niettekenen:
		ii=0; //dummie opdracht voor goto
		}
	}
#endif
}

void world::drawobjecten(float xx,float yy){
	int i;
	i=0;
	if(temp==NULL) temp=start;
	//int getal=(int)floor(yy/100);
	while(temp->xland!=(int)floor(xx/100) || temp->yland!=(int)floor(yy/100)){
		if(i>=landlijst.size()){
			//maak een nieuw land aan;
			temp=new land((int)floor(xx/100),(int)floor(yy/100),0);
			break;
		}
		temp=landlijst.at(i);
		i++;
	}

	
	#ifdef LOW	

	if(temp->links==NULL)			temp->links=		new land(temp->xland-1,temp->yland,0);
	if(temp->links->boven==NULL)	temp->links->boven=	new land(temp->xland-1,temp->yland+1,0);
	if(temp->boven==NULL)			temp->boven=		new land(temp->xland,temp->yland+1,0);
	if(temp->rechts==NULL)			temp->rechts=		new land(temp->xland+1,temp->yland,0);
	if(temp->rechts->boven==NULL)	temp->rechts->boven=new land(temp->xland+1,temp->yland+1,0);
	if(temp->rechts->onder==NULL)	temp->rechts->onder=new land(temp->xland+1,temp->yland-1,0);
	if(temp->onder==NULL)			temp->onder=		new land(temp->xland,temp->yland-1,0);
	if(temp->links->onder==NULL)	temp->links->onder=	new land(temp->xland-1,temp->yland-1,0);

	temp->drawobjecten();
	temp->links->onder->drawobjecten();
	temp->links->drawobjecten();
	temp->links->boven->drawobjecten();
	temp->boven->drawobjecten();
	temp->rechts->boven->drawobjecten();
	temp->rechts->drawobjecten();
	temp->rechts->onder->drawobjecten();
	temp->onder->drawobjecten();
#endif
}

float world::zfunction(float xx,float yy,float zzz){
	int i;
	i=0;
	if(temp==NULL) temp=start;
	while(temp->xland!=(int)floor(xx/100) || temp->yland!=(int)floor(yy/100)){
		if(i>=landlijst.size()){
			//maak een nieuw land aan;
			temp=new land((int)floor(xx/100),(int)floor(yy/100),0);
			break;
		}
		temp=landlijst.at(i);
		i++;
	}
	return temp->zfunction(xx,yy,zzz);
}

void world::insert(object* obj){
	int i;
	i=0;
	while(temp->xland!=(int)floor(obj->xobj/100) || temp->yland!=(int)floor(obj->yobj/100)){
		if(i>=landlijst.size()){
			//maak een nieuw land aan;
			temp=new land((int)floor(obj->xobj/100),(int)floor(obj->yobj/100),0);
			break;
		}
		temp=landlijst.at(i);
		i++;
	}
	temp->objectlijst.push_back(obj);
}


void world::actie(float xx,float yy,int act){
	int i;
	i=0;
	while(temp->xland!=(int)floor(xx/100) || temp->yland!=(int)floor(yy/100)){
		if(i>=landlijst.size()){
			//land bestaat niet waar actie wordt uitgevoerd
			return;
		}
		temp=landlijst.at(i);
		i++;
	}
	float min=10000000; //zeer groot
	object* object1=NULL;
	object* object2=NULL; 
	for(i=0;i<temp->objectlijst.size();i++){
		if((temp->objectlijst.at(i)->xobj-x)*(temp->objectlijst.at(i)->xobj-x)+(temp->objectlijst.at(i)->yobj-y)*(temp->objectlijst.at(i)->yobj-y)+(temp->objectlijst.at(i)->zobj-z)*(temp->objectlijst.at(i)->zobj-z)<min){
			min=(temp->objectlijst.at(i)->xobj-x)*(temp->objectlijst.at(i)->xobj-x)+(temp->objectlijst.at(i)->yobj-y)*(temp->objectlijst.at(i)->yobj-y);
			object2=object1;
			object1=temp->objectlijst.at(i);
		}
	}
	if(object1!=NULL){
		if(object1->actie(rugzak,temp,act)==-1){
			if(object2!=NULL) object2->actie(rugzak,temp,act);
		}
	}
}
