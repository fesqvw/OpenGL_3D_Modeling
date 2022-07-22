#include "Edge.h"

/*
Create an edge
*/
edge* e_create(Shape* owner, vertex* u, vertex* v) {
	edge* e = (edge*)calloc(1, sizeof(edge));
	if (!e) {
		throw AllocationProblem;
	}
	e->faces_set = hs_createSet<face*>(5);
	e->owner = owner;
	e->u = u;
	e->v = v;
	owner->addEdge(e);
	return e;
}

/*
Free an edge
*/
void e_free(edge* e) {
	if (!e->freeing) {
		return;
	}
	e->freeing = true;
	auto f = [](face* f, void* ctx) {
		f_free(f);
	};
	hs_forEach<face*, void*>(e->faces_set, f, nullptr);
	hs_freeSet(e->faces_set);
	free(e);
}

/*
Add this edge to the face
*/
void e_addToFace(edge* e, face* f) {
	hs_insert(e->faces_set, f);
}

/*
Remove this edge from the face
*/
void e_removeFromFace(edge* e, face* f) {
	hs_remove(e->faces_set, f);
}

/*
Check if this edge belongs to that face
*/
bool e_belongsTo(edge* e, face* f) {
	face** check = hs_find(e->faces_set, f);
	return check;
}