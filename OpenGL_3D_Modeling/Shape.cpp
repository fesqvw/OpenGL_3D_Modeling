#include "Shape.h"
#include "MapUtils.h"


Shape::Shape(Primitive p) {
	/*
	TODO : create shape using different primitives
	-> for now : it will only create a simple triangle
	*/
	Vertex* v1 = new Vertex(this,1,0,0);
	Vertex* v2 = new Vertex(this,0,1,0);
	Vertex* v3 = new Vertex(this,0,0,1);
	Edge* e1 = new Edge(this,v1,v2);
	Edge* e2 = new Edge(this,v2,v3);
	Edge* e3 = new Edge(this,v3,v1);
	Triangle* t = new Triangle(this, {e1,e2,e3});

}

Shape::Shape(Triangle** setupTriangles, size_t n) {

	if (n <= 0 || !setupTriangles) {
		throw IllegalArgument;
	}
	for (int i = 0; i < n; ++i) {
		if (!setupTriangles[i]) {
			throw IllegalArgument;
		}
		//add elements to shape
		triangles.insert({ setupTriangles[i], setupTriangles[i] }); //add the triangle
		//add the edges
		map<Edge* const, Edge* const> triangleEdges = setupTriangles[i]->getEdges(); //add teh vertices of every edge, there should be (exactly) 3 distinct ones
		for (map<Edge* const, Edge* const>::iterator it = triangleEdges.begin(); it != triangleEdges.end(); ++it) {
			edges.insert({ it->first, it->first });
		}
		//add the vertices
		map<Vertex* const, Vertex* const> triangleVertices = setupTriangles[i]->getVertices(); //add teh vertices of every edge, there should be (exactly) 3 distinct ones
		for (map<Vertex* const, Vertex* const>::iterator it = triangleVertices.begin(); it != triangleVertices.end(); ++it) {
			vertices.insert({ it->first, it->first });
		}
	}

}

void Shape::addVertex(Vertex* v) {
	addElement(vertices, v, &nbVertices);
}

void Shape::removeVertex(Vertex* v) {
	removeElement(vertices, v, &nbVertices);
}

void Shape::addEdge(Edge* e) {
	addElement(edges, e, &nbEdges);
}

void Shape::removeEdge(Edge* const e) {
	removeElement(edges,e,&nbEdges);
}

void Shape::addTriangle(Triangle* const t) {
	addElement(triangles,t,&nbTriangles);
}

void Shape::removeTriangle(Triangle* const t) {
	removeElement(triangles, t, &nbTriangles);
}

void Shape::remove() {
	//delete all vertices, it will make a chain reaction where all edges and triangles will also be deleted
	std::function<void(Vertex* const)> lambda = [](Vertex* const e) { e->remove(); };
	mapForEach(vertices, lambda);
	delete this;
}

template <typename T>
void Shape::addElement( map<T const, T const> toAddMap , T const elem, size_t* counter) {
	if (!elem || elem->getOwner() != this) {
		throw IllegalArgument;
	}

	if (!mapContains(toAddMap, elem)) {
		toAddMap.insert({ elem, elem });
		++(*counter);
	}
}

template <typename T>
void Shape::removeElement(map<T const, T const> toRemoveMap, T const elem, size_t* counter ) {
	if (!elem || elem->getOwner() != this) {
		throw IllegalArgument;
	}
	if (mapContains(toRemoveMap, elem)) {
		toRemoveMap.erase(elem);
		--(*counter);
	}
}


