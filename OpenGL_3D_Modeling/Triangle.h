#pragma once
//1 Triangle is defined by 3 edges / 3 vertices
#include "Edge.h"
#include "Error.h"

#include <iostream>
#include <iterator>
#include <set>
#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()
#include<map> // for get()
using namespace std;


/*
A complete triangle : it is defined by 3 edges
@author : Abel Vexina Wilkinson (Fesq vw)
*/
class Triangle {

	//TODO : we will need a way to select it with the mouse
	//TODO : we will need a way to change the position of the vertices
	//TODO : we will need a way to draw the triangle, transparent or not
public:
	Triangle(Shape* s, array<Edge*, 3> edges);
	const map<Edge* const, Edge* const> getEdges();
	const map<Vertex* const, Vertex* const> getVertices();
	void remove();
	Shape* getOwner();

private:
	//We use fixed sized arrays because a triangle can only have 3 edges/vertices
	//array<const Edge* ,3> edges = {nullptr,nullptr,nullptr};
	map<Edge* const, Edge* const> edges;
	size_t nbEdges = 3;
	map<Vertex* const, Vertex* const> vertices;
	size_t nbVertices = 3;
	Shape* const ownerShape = nullptr;
};