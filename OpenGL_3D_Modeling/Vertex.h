#pragma once

#include "Error.h"
#include <map>
#include<iostream>
#include<iterator>
#include<tuple>
using namespace std;

class Shape;
class Edge;

/*
An edge : it is defined by 1 point in space, with 3 coordinates (x,y,z)
@author : Abel Vexina Wilkinson (Fesq vw)
*/
class Vertex {

	//TODO : we will need a way to select it with the mouse
	//TODO : we will need a way to change the position
	//TODO : we will need a way to draw the vertex
public:
	Vertex(Shape* s, float x, float y, float z);
	void addToEdge(Edge* e);
	void removeFromEdge(Edge* e);
	bool belongsTo(Edge* e);
	void remove();
	Shape* getOwner();

private:
	const float x = 0.0;
	const float y = 0.0;
	const float z = 0.0;
	map< Edge* const, Edge* const> edges;
	size_t nbEdges = 0;
	Shape* const ownerShape = nullptr;
};
