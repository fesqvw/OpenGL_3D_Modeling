#include "Triangle.h"

/*
Create a face
*/
face* f_create(Shape* owner, edge** creationEdges, size_t nbEdges) {
	face* f = (face*)calloc(1, sizeof(face));
	f->owner = owner;
	f->edges = creationEdges;
	f->nbEdges = nbEdges;
	owner->addFace(f);

	//Check if edges create a cycle
	vertex* prev = creationEdges[nbEdges - 1]->v;
	f->nbVertices = nbEdges;
	for (int i = 0; i < nbEdges; ++i) {
		if (prev != creationEdges[i]->u) {
			free(f);
			throw IllegalArgument;
		}
		prev = creationEdges[i]->v;
	}
}

void f_free(face* f) {
	free(f);
}

bool f_containsVertex(face* f, vertex* v) {
	for (int i = 0; i < f->nbVertices; ++i) {
		if (f->vertices[i] == v) {
			return true;
		}
	}
	return false;
}

bool f_containsEdge(face* f, edge* e) {
	for (int i = 0; i < f->nbVertices; ++i) {
		if (f->edges[i] == e) {
			return true;
		}
	}
	return false;
}