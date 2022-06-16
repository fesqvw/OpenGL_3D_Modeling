#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

//EVENTS
/*
TODO : SEARCH/ADD DIFFERENT KINDS OF EVENTS
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



}