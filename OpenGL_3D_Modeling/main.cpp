#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "Shape.h"
#include "Primitive.h"
#include "HashSet.h"


#include <functional>
using namespace std;

//EVENTS
/*
TODO : SEARCH/ADD DIFFERENT KINDS OF EVENTS
TODO : create and add these into a WindowManager
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

/*
TODO : make a camera class - learningOpenGl inspired
-> look at the test project
*/

/*
TODO : make a window manager
*/

//Initial height and width
int height = 600;
int width = 800;

int main() {
	//GLFW init
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//maximum version of openGl
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	//minimum version of openGl
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//use openGl core

	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL_3D_Modeling", NULL, NULL); //init window to desired size with title
	if (window == NULL) {	//check if window was created correctly
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {	//check glad is initialized correctly
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	//set input mode : use the cursor (mouse)
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	//set callbacks for events
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	
	/*
	TODO : RESEARCH - use multiple viewports to simulate layers?
	use multiple viewports to separate main window from UI elements on the edges
	*/
	//use main viewport
	glViewport(0, 0, width, height);
	//enable depth
	glEnable(GL_DEPTH_TEST);




	/*
	START TESTING GROUND
	*/
	Shape* s = new Shape(Primitive::SimpleTriangle);
	delete s;
	/*
	END TESTING GROUND
	*/




	//test->remove(); //PROBLEMA ACA


	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		processInput(window);
		/*
		TODO : define background color in window manager
		*/
		glClearColor(0.3f, 0.1f, 0.1f, 1.0f); //background : 
		glClear(GL_COLOR_BUFFER_BIT);

		/*
		TODO - window manager : draw window content 
		*/
		
		/*
		TODO : Figure out how to pass how things have to be drawn
		Global state in window manager?
		Global state for the main window?
		As parameters for draw?
		*/
	//	Shape* testShape = new Shape(Primitive::SimpleTriangle);
	//	testShape->draw();
	//	testShape->remove();

		glfwPollEvents();
		glfwSwapBuffers(window);

	}

	return 0;
}

/*
TODO : manage events in window manager
TODO : window manager should contain info of all main viewPorts
*/
void framebuffer_size_callback(GLFWwindow* window, int widthF, int heightF) {

	height = heightF;
	width = widthF;
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
}