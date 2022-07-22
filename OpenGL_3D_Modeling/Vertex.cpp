#include "Vertex.h"

/*
* Create a vertex
*/
vertex* v_create(Shape* owner, coordinates coords) {
	vertex* v = (vertex*)calloc(1, sizeof(vertex));
	if (!v) {
		throw AllocationProblem;
	}
	v->owner = owner;
	v->pos = coords;
	v->edges_set = hs_createSet<edge*>(10); //TODO : find the correct size
	owner->addVertex(v);
	return v;
}

/*
* Free a vertex : serves as the deletion mechanism
*/
void v_free(vertex* v) {
	if (!v->freeing) {
		return;
	}
	v->freeing = true;
	auto f = [](edge* e, void* ctx) {
		e_free(e);
	};
	hs_forEach<edge*, void*>(v->edges_set, f, nullptr);
	hs_freeSet(v->edges_set);
	free(v);
}

/*
* Add the edge to the list of edges of the vertex
* - one of the vertices of that edge is this vertex
*/
void v_addToEdge(vertex* v, edge* e) {
	hs_insert(v->edges_set, e);
}

/*
* Remove the edge to the list of edges of the vertex
*/
void v_removeFromEdge(vertex* v, edge* e) {
	hs_remove(v->edges_set, e);
	if (v->edges_set->count <= 0 && !v->freeing) {
		v_free(v);
	}
}

/*
* Check whether this vertex belongs to this edge
*/
bool v_belongsTo(vertex* v, edge* e) {
	edge** check = hs_find(v->edges_set, e);
	return check;
}

/*
* Change the position of the vertex
*/
void v_changePos(vertex* v, coordinates newPos) {
	v->pos = newPos;
}


