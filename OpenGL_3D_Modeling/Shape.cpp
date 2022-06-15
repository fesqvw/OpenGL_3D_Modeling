#include "Shape.h"
#include "MapUtils.h"



void Shape::addVertex(Vertex* v) {
	if (!v || v->getOwner() != this) {
		throw IllegalArgument;
	}
	
	if ( !mapContains(vertices, v)) {
		vertices.insert(v,v);
		++nbVertices;
	}

}

void Shape::addEdge(Edge* e) {
	if (!e || e->getOwner() != this) {
		throw IllegalArgument;
	}

	if (!mapContains(edges, e)) {
		edges.insert(e, e);
		++nbEdges;
	}

}

void Shape::addTriangle(Triangle* t) {
	if (!t || t->getOwner() != this) {
		throw IllegalArgument;
	}

	if (!mapContains(triangles, t)) {
		triangles.insert(t, t);
		++nbTriangles;
	}

}


Shape::Shape(Triangle** setupTriangles, size_t n) {

	if (n <= 0  || !setupTriangles) {
		throw IllegalArgument;
	}
	for (int i = 0; i < n; ++i) {
		if (!setupTriangles[i]) {
			throw IllegalArgument;
		}
		//add elements to shape
		triangles.insert(setupTriangles[i], setupTriangles[i]); //add the triangle
		//add the edges
		map<Edge* const, Edge* const> triangleEdges = setupTriangles[i]->getEdges(); //add teh vertices of every edge, there should be (exactly) 3 distinct ones
		for (map<Edge* const, Edge* const>::iterator it = triangleEdges.begin(); it != triangleEdges.end(); ++it) {
			edges.insert(it->first, it->first);
		}
		//add the vertices
		map<Vertex* const, Vertex* const> triangleVertices = setupTriangles[i]->getVertices(); //add teh vertices of every edge, there should be (exactly) 3 distinct ones
		for (map<Vertex* const, Vertex* const>::iterator it = triangleVertices.begin(); it != triangleVertices.end(); ++it) {
			vertices.insert(it->first, it->first);
		}
	}

}


