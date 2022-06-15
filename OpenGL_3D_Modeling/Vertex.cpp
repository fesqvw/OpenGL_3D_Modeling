//1 vertex is defined by 3 points in space
#include "Vertex.h"
#include "Edge.h"
#include "Shape.h"

Vertex::Vertex(Shape* s, double x, double y, double z) : x(x),y(y),z(z),ownerShape(s) {
	if (!s) {
		throw IllegalArgument;
	}
	s->addVertex(this);
}


void Vertex::addToEdge(Edge* const e) {
	if (!e || !e->contains(this)) {
		throw IllegalArgument;
	}
	if (belongsTo(e)) {
		return;
	}
	edges.insert(e, e);
	++nbEdges;
}

void Vertex::removeFromEdge(Edge* const e) {
	if (!e) {
		throw IllegalArgument;
	}
	if (!belongsTo(e)) {
		return;
	}
	edges.erase(e);
	--nbEdges;
	if (nbEdges == 0) {
		remove();
	}
}

/*
TODO : create util --> mapContains(element,map) 
*/
bool Vertex::belongsTo(Edge* const e) {
	if (!e) {
		throw IllegalArgument;
	}
	try
	{
		edges.at(e);
		return true;
	}
	catch (const std::exception)
	{
		return false;
	}
}

/*
TODO : create util -> map for each , taking a type T and lambda T -> Unit
*/
void Vertex::remove() {
	for (map<Edge* const, Edge* const>::iterator it = edges.begin(); it != edges.end(); ++it ) {
		it->first->remove();
	}
	ownerShape->removeVertex(this);
	delete this;
}

Shape* Vertex::getOwner() {
	return ownerShape;
}


