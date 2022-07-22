#pragma once
#include "Error.h"
#include "HashSet.h"

#include "Edge.h"

#include <map>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 3D coordinates
*/
struct coordinates {
	float x;
	float y;
	float z;
};

//TODO : we will need a way to select it with the mouse
//TODO : we will need a way to change the position -> will need to notify the edges and triangles
//TODO : we will need a way to draw the vertex
//TODO : refactor -> put the definitions in the .cpp

struct edge;
class Shape;

/*
* A vertex 
*/
struct vertex {
	coordinates pos;
	Shape* owner = nullptr;
	hash_set<edge*>* edges_set = nullptr;
	bool freeing = false;
} ;

/*
* Create a vertex
*/
vertex* v_create(Shape* owner, coordinates coords);

/*
* Free a vertex : serves as the deletion mechanism
*/
void v_free(vertex* v);

/*
* Add the edge to the list of edges of the vertex
* - one of the vertices of that edge is this vertex
*/
void v_addToEdge(vertex* v, edge* e);
/*
* Remove the edge to the list of edges of the vertex
*/
void v_removeFromEdge(vertex* v, edge* e);

/*
* Check whether this vertex belongs to this edge
*/
bool v_belongsTo(vertex* v, edge* e);

/*
* Change the position of the vertex
*/
void v_changePos(vertex* v, coordinates newPos);


