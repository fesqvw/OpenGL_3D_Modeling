#include "Shape.h"

//TODO : adjust sizes -> no magic numbers hopefully
Shape::Shape(Primitive p) {
	vertices = hs_createSet<vertex*>(10);
	edges = hs_createSet<edge*>(10);
	faces = hs_createSet<face*>(10);

	vertex* v1 = v_create(this, { 1,0,0 } );
	vertex* v2 = v_create(this, { 0,1,0 } );
	vertex* v3 = v_create(this, { 0,0,1 } );

	edge* e1 = e_create(this,v1,v2);
	edge* e2 = e_create(this,v2,v3);
	edge* e3 = e_create(this,v3,v1);

	edge* edges[3] = {e1,e2,e3};

	face* f = f_create(this,edges,3);

	addVertex(v1);
	addVertex(v2);
	addVertex(v3);

	addEdge(e1);
	addEdge(e2);
	addEdge(e3);

	addFace(f);
}

void Shape::addShape(Shape* s) {

}

void Shape::addVertex(vertex* v) {
	hs_insert(vertices,v);
}

void Shape::addEdge(edge* e) {
	hs_insert(edges, e);
}

void Shape::addFace(face* f) {
	hs_insert(faces, f);
}

void Shape::removeVertex(vertex* v) {
	hs_remove(vertices,v);
}

void Shape::removeEdge(edge* e) {
	hs_remove(edges, e);
}

void Shape::removeFace(face* f) {
	hs_remove(faces,f);
}

//TODO : remove all vertices of the shape
void Shape::free() {
	hs_freeSet(vertices);
	hs_freeSet(edges);
	hs_freeSet(faces);
}

void Shape::draw() {

}
