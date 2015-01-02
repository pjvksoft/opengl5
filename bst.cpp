#include <iostream>
#include "bst.h"
#include "objecten.h"

treeElement::treeElement(){
	more=NULL;less=NULL;
}
treeElement::treeElement(float maxx,float minx,float maxy,float miny){
	this->maxx=maxx;this->maxy=maxy;this->minx=minx;this->miny=miny;
	this->voorwerp=NULL;
}

treeElement::treeElement(object* obj,float maxx,float minx,float maxy,float miny){
	this->maxx=maxx;this->maxy=maxy;this->minx=minx;this->miny=miny;
	this->voorwerp=obj;
}

bst::bst(){
root=NULL;

}
void bst::insert(float maxx,float minx,float maxy,float miny){
		//controleer volgorde maxx,minx,maxy,miny
		if(root==NULL){
			root = new treeElement(maxx,minx,maxy,miny);
		}else{
			int niveau=0;
			treeElement* pointer;
			pointer=this->root;
			while(true){
				if(niveau%4==0){
					if(maxx>=pointer->maxx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==1){
					if(minx>=pointer->minx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==2){
					if(maxy>=pointer->maxy){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==3){
					if(miny>=pointer->miny){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
			}//end while
		}
}
void bst::insert(object* obj){
	if(root==NULL){
			root = new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
		}else{
			int niveau=0;
			treeElement* pointer;
			pointer=this->root;
			while(true){
				if(niveau%4==0){
					if(obj->maxx>=pointer->maxx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==1){
					if(obj->minx>=pointer->minx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==2){
					if(obj->maxy>=pointer->maxy){
						if(pointer->more==NULL){
							pointer->more=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==3){
					if(obj->miny>=pointer->miny){
						if(pointer->more==NULL){
							pointer->more=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(obj->maxx,obj->minx,obj->maxy,obj->miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
			}//end while
		}


}
void bst::insert(object* obj,float maxx,float minx,float maxy,float miny){
		//controleer volgorde maxx,minx,maxy,miny
		if(root==NULL){
			root = new treeElement(maxx,minx,maxy,miny);
		}else{
			int niveau=0;
			treeElement* pointer;
			pointer=this->root;
			while(true){
				if(niveau%4==0){
					if(maxx>=pointer->maxx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==1){
					if(minx>=pointer->minx){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==2){
					if(maxy>=pointer->maxy){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
				if(niveau%4==3){
					if(miny>=pointer->miny){
						if(pointer->more==NULL){
							pointer->more=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->more;
						niveau++;
					}else{
						if(pointer->less==NULL){
							pointer->less=new treeElement(maxx,minx,maxy,miny);
							break;
						}
						pointer=pointer->less;
						niveau++;
					}
				}
			}//end while
		}
}

float bst::zfunction(float xx, float yy, float zz){
		//controleer volgorde maxx,minx,maxy,miny
		if(root==NULL){
			return MINHEIGHT;
		}else{
			return conmaxx(root,xx,yy,zz);
		}
}

float bst::conmaxx(treeElement* pointer,float xx, float yy, float zz){
		float a,b;
		if(pointer==NULL){
			return MINHEIGHT;
		}else if(pointer->maxx>xx && pointer->minx<xx && pointer->maxy > yy && pointer->miny < yy){
			return 1.0; // link naar de zfunctie;
		}else{
			if(pointer->maxx>xx){
				a=conminx(pointer->less,xx,yy,zz);
				b=conminx(pointer->more,xx,yy,zz);
				return (b>a)?a:b;
			}else{
				return conminx(pointer->more,xx,yy,zz);
			}
		}
}

float bst::conminx(treeElement* pointer,float xx, float yy, float zz){
		float a,b;
		if(pointer==NULL){
			return MINHEIGHT;
		}else if(pointer->maxx>xx && pointer->minx<xx && pointer->maxy > yy && pointer->miny < yy){
			return 1.0; // link naar de zfunctie;
		}else{
			if(pointer->minx<xx){
				a=conmaxy(pointer->less,xx,yy,zz);
				b=conmaxy(pointer->more,xx,yy,zz);
				return (b>a)?a:b;
			}else{
				return conminx(pointer->less,xx,yy,zz);
			}
		}
}

float bst::conmaxy(treeElement* pointer,float xx, float yy, float zz){
		float a,b;
		if(pointer==NULL){
			return MINHEIGHT;
		}else if(pointer->maxx>xx && pointer->minx<xx && pointer->maxy > yy && pointer->miny < yy){
			return 1.0; // link naar de zfunctie;
		}else{
			if(pointer->maxy>yy){
				a=conminy(pointer->less,xx,yy,zz);
				b=conminy(pointer->more,xx,yy,zz);
				return (b>a)?a:b;
			}else{
				return conminx(pointer->more,xx,yy,zz);
			}
		}
}

float bst::conminy(treeElement* pointer,float xx, float yy, float zz){
		float a,b;
		if(pointer==NULL){
			return MINHEIGHT;
		}else if(pointer->maxx>xx && pointer->minx<xx && pointer->maxy > yy && pointer->miny < yy){
			return 1.0; // link naar de zfunctie;
		}else{
			if(pointer->miny<yy){
				a=conmaxy(pointer->less,xx,yy,zz);
				b=conmaxy(pointer->more,xx,yy,zz);
				return (b>a)?a:b;
			}else{
				return conminx(pointer->less,xx,yy,zz);
			}
		}
}