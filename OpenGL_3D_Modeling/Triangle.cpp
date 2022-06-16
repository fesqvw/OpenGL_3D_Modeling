#include "Triangle.h"
#include "Shape.h"
#include "MapUtils.h"

/*
Create a triangle while having all the information
*/
Triangle::Triangle(Shape* s , array<Edge*, 3> edges) : ownerShape(s)
{
	if (!s) {
		throw IllegalArgument;
	}
	for (int i = 0 ; i < 3 ; ++i) //add all edges to the triangle
	{
		if (!edges[i]) {
			throw IllegalArgument;
		}
		this->edges.insert({ edges[i], edges[i] });
		map<Vertex* const, Vertex* const> edgeVertices = edges[i]->getVertices(); //add teh vertices of every edge, there should be (exactly) 3 distinct ones

		std::function<void(Vertex* const)> lambda = [](Vertex* const e) { e->remove(); };
		mapForEach(edgeVertices, lambda);
		
	}

	if (this->edges.size() != 3 || this->vertices.size() != 3) { //check that the arguments are correct
		this->edges.clear();
		this->vertices.clear();
		delete this;
		throw IllegalArgument;
	}
	
	//everything is correct 
	for (int i = 0; i < 3; ++i) //notify the edges they have been added to this triangle
	{
		edges[i]->addToTriangle(this);
	}
}

const map<Edge* const, Edge* const> Triangle::getEdges() {
	return edges;
}

const map<Vertex* const, Vertex* const> Triangle::getVertices() {
	return vertices;
}

void Triangle::remove() {

	std::function<void(Edge* const)> lambda = [](Edge* const e) { e->remove(); };
	mapForEach(edges, lambda);
	ownerShape->removeTriangle(this);
	delete this;
}

Shape* Triangle::getOwner() {
	return ownerShape;
}