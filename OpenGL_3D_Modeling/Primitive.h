#pragma once
#include "Vertex.h"
#include <iostream>
#include <iterator>
#include <set>
#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()

//Must contain all information needed to assemble a starting shape 
/*TODO : arrays/table/files containing the information for the shape composition
	-> vertices : coordinates
	-> edges : which vertices they connect
	-> triangles : which edges it uses
*/

enum class Primitive {
	SimpleTriangle,
	Plane,
	Cube
};



