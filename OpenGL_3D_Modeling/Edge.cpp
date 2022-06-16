//1 edge is defined by 2 vertices
#include "Edge.h"
#include "Shape.h"
#include "Triangle.h"
#include "MapUtils.h"

Edge::Edge(Shape* s, Vertex* u, Vertex* v) :ownerShape(s)
{
	if (!s || !u || !v || u == v) {
		throw IllegalArgument;
	}

	vertices.insert({u, u});
	vertices.insert({v, v});
	s->addEdge(this);
	u->addToEdge(this);
	v->addToEdge(this);
}

const map<Vertex* const, Vertex* const> Edge::getVertices()
{
	return vertices;
}


void Edge::addToTriangle(Triangle* t) {
	if (!t) {
		throw IllegalArgument;
	}
	if (belongsTo(t)) {
		return;
	}
	triangles.insert({t,t});
	++nbTriangles;
}

void Edge::removeFromTriangle(Triangle* t) {
	if (!t) {
		throw IllegalArgument;
	}
	if (!belongsTo(t)) {
		return;
	}
	triangles.erase(t);
	--nbTriangles;
}

bool Edge::belongsTo(Triangle* t) {
	if (!t) {
		throw IllegalArgument;
	}
	return mapContains(triangles,t);
}

bool Edge::contains(Vertex* v) {
	if (!v) {
		throw IllegalArgument;
	}
	return mapContains(vertices, v);
}

void Edge::remove() {

	std::function<void(Triangle* const)> lambdat = [](Triangle* const e) { e->remove(); };
	mapForEach(triangles, lambdat);
	for (map<Vertex* const, Vertex* const>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		it->first->removeFromEdge(this);
	}
	ownerShape->removeEdge(this);
	delete this;
}


Shape* Edge::getOwner() {
	return ownerShape;
}
