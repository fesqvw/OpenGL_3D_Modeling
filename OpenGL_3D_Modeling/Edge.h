#pragma once
#include "Error.h"
#include "HashSet.h"

/*
An edge : it is defined by 2 pointers to vertices
@author : Abel Vexina Wilkinson (Fesq vw)
*/


//TODO : we will need a way to select it with the mouse
//TODO : we will need a way to change the position of the vertices
//TODO : we will need a way to draw the edge
//TODO : we will need a way to split up and edge into 2

struct vertex;
struct face;
class Shape;


/*
* An edge
*/
struct edge {
	vertex* u = nullptr;
	vertex* v = nullptr;
	hash_set<face*>* faces_set = nullptr;
	Shape* owner = nullptr;
	bool freeing = false; //TODO : evaluate if useful
};

/*
Create an edge
*/
edge* e_create(Shape* owner, vertex* u, vertex* v);

/*
Free an edge 
*/
void e_free(edge* e);

/*
Add this edge to the face
*/
void e_addToFace(edge* e, face* f);

/*
Remove this edge from the face
*/
void e_removeFromFace(edge* e, face* f);

/*
Check if this edge belongs to that face
*/
bool e_belongsTo(edge* e, face* f);