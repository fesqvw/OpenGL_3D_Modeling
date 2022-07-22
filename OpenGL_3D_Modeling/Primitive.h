#pragma once

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



