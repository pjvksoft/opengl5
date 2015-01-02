#include "objecten.h"
#ifndef BST_H
#define BST_H

#define MINHEIGHT 0.0

class treeElement{
public:
	treeElement* more;
	treeElement* less;
	float maxx;
	float minx;
	float maxy;
	float miny;
	object* voorwerp;
	treeElement();
	treeElement(float maxx,float minx,float maxy,float miny);
	treeElement(object* obj,float maxx,float minx,float maxy,float miny);
};

class bst{
public:
	treeElement* root;
	bst();
	void insert(float maxx,float minx,float maxy,float miny);
	void insert(object* obj,float maxx,float minx,float maxy,float miny);
	void insert(object* obj);
	float zfunction(float xx, float yy, float zz);
	float conmaxx(treeElement* pointer,float xx, float yy, float zz);
	float conminx(treeElement* pointer,float xx, float yy, float zz);
	float conmaxy(treeElement* pointer,float xx, float yy, float zz);
	float conminy(treeElement* pointer,float xx, float yy, float zz);

};

#endif