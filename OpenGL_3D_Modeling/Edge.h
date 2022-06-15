#pragma once
#include "Vertex.h"
#include "Error.h"


class Triangle;

/*
An edge : it is defined by 2 pointers to vertices
@author : Abel Vexina Wilkinson (Fesq vw)
*/
class Edge {

	//TODO : we will need a way to select it with the mouse
	//TODO : we will need a way to change the position of the vertices
	//TODO : we will need a way to draw the edge
	//TODO : we will need a way to split up and edge into 2
public:
	Edge(Shape* s, Vertex* u, Vertex* v);
	const map<Vertex* const, Vertex* const> getVertices();
	void addToTriangle(Triangle* t);
	void removeFromTriangle(Triangle* t);
	bool belongsTo(Triangle* t);
	bool contains(Vertex* v);
	void remove();
	Shape* getOwner();

private:
	map<Vertex* const, Vertex* const> vertices;
	size_t nbVertices = 2;
	map<Triangle* const, Triangle* const> triangles;
	size_t nbTriangles = 0;
	Shape* const ownerShape;
};