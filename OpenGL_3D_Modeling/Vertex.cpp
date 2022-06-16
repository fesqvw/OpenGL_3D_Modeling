//1 vertex is defined by 3 points in space
#include "Vertex.h"
#include "Edge.h"
#include "Shape.h"
#include "MapUtils.h"

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
	edges.insert({ e, e });
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


bool Vertex::belongsTo(Edge* const e) {
	if (!e) {
		throw IllegalArgument;
	}
	return mapContains(edges,e);
}

void Vertex::remove() {
	std::function<void(Edge* const)> lambda = [](Edge* const e) { e->remove(); };
	mapForEach(edges, lambda);
	ownerShape->removeVertex(this);
	delete this;
}

Shape* Vertex::getOwner() {
	return ownerShape;
}


