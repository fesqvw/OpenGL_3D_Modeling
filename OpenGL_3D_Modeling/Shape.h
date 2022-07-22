#pragma once
//1 shape is defined by all the triangles it contains
#include "Error.h"
#include "Primitive.h"
#include "HashSet.h"

#include "Vertex.h"
#include "Edge.h"
#include "Triangle.h"


#include <iostream>
#include <iterator>
#include <set>
#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()


/*
A Shape : it is defined by the triangles it is composed of and the edges which not yet create a triangle
It is mutable, as such the triangles can change, reduce, and expand
@author : Abel Vexina Wilkinson (Fesq vw)
*/

struct vertex;
struct edge;
struct face;

class Shape {

	//TODO : we will need a way to select it with the mouse
	//TODO : we will need a way to change the position of all vertices
	//TODO : we will need a way to draw the whole shape
public:
	Shape(Primitive p);
	~Shape();
	void addShape(Shape* s); //TODO : define it once that will be used - not yet
	void addVertex(vertex* v);
	void removeVertex(vertex* v);
	void addEdge(edge *e);
	void removeEdge(edge* e);
	void addFace(face* f);
	void removeFace(face* f);
	void free();
	
	void draw();

private:
	hash_set<face*>* faces = nullptr;
	hash_set<edge*>* edges = nullptr;
	hash_set<vertex*>* vertices = nullptr;

};
