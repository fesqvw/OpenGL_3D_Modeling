#pragma once
//1 shape is defined by all the triangles it contains
#include "Triangle.h"
#include "Edge.h"
#include "Vertex.h"
#include "Error.h"
#include "Primitive.h"

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

class Shape {

	//TODO : we will need a way to select it with the mouse
	//TODO : we will need a way to change the position of all vertices
	//TODO : we will need a way to draw the whole shape
public:
	Shape(Primitive p); 
	void addShape(Shape* s); //TODO : define it once that will be used - not yet
	void addVertex(Vertex* v);
	void removeVertex(Vertex* v);
	void addEdge(Edge *e);
	void removeEdge(Edge* e);
	void addTriangle(Triangle* t);
	void removeTriangle(Triangle* t);
	void remove();

private:
	Shape(Triangle** triangles, size_t n);
	map<Triangle* const, Triangle* const> triangles;
	size_t nbTriangles = 0;
	map<Edge* const, Edge* const> edges;
	size_t nbEdges = 0;
	map<Vertex* const, Vertex* const> vertices;
	size_t nbVertices = 0;

	template <typename T>
	void addElement(map<T const, T const> toAddMap, T const elem, size_t* counter);
	template <typename T>
	void removeElement(map<T const, T const> toAddMap, T const elem, size_t* counter);
};
