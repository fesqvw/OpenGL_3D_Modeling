#pragma once
//1 Triangle is defined by 3 edges / 3 vertices
#include "Error.h"
#include <learnOpenGl/shader_s.h>

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
/*
class Triangle {

public:
	Triangle(Shape* s, array<Edge*, 3> edges);
	const map<Edge* const, Edge* const> getEdges();
	const map<Vertex* const, Vertex* const> getVertices();
	void remove();
	Shape* getOwner();

	void draw();

private:
	//We use fixed sized arrays because a triangle can only have 3 edges/vertices
	map<Edge* const, Edge* const> edges;
	size_t nbEdges = 3;
	map<Vertex* const, Vertex* const> vertices;
	size_t nbVertices = 3;
	Shape* const ownerShape = nullptr;

	//TODO : UNDER CONSTRUCTION - one drawing set per shape, not triangle
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	float drawPositions[9];
	unsigned int drawIndices[3] = { 0,1,2 };
	Shader shader = Shader("Triangle_vShader.txt", "Triangle_fShader.txt");

};*/


//TODO : we will need a way to select it with the mouse
//TODO : we will need a way to change the position of the vertices
//TODO : we will need a way to draw the triangle, transparent or not

struct edge;
struct vertex;
class Shape;

struct face {
	edge** edges = nullptr; //edges does not change + are ordered
	size_t nbEdges = 0;
	vertex** vertices = nullptr; //vertices does not change + are ordered
	size_t nbVertices = 0;
	Shape* owner = nullptr;
};

/*
Create a face
*/
face* f_create(Shape* owner, edge** creationEdges, size_t nbEdges);

void f_free(face* f);

bool f_containsVertex(face* f, vertex* v);

bool f_containsEdge(face* f, edge* e);