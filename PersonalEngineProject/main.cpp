#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



const unsigned int windowWidth = 800;
const unsigned int windowHeight = 600; 
const char windowName[] = "MainWindow";


void framebuffer_size_callback(GLFWwindow* window, int width, int height); 

int main() {

	//Configure GLFW 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create GLFW window
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl; 
		glfwTerminate();
		return -1; 

	}
	//Adjust current context 
	glfwMakeContextCurrent(window); 

	//Check GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1; 
	}

	//Set gl viewport 
	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

	while (!glfwWindowShouldClose(window)) {

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clean/delete all of GLFW's resources 
	glfwTerminate();
	return 0; 

}





void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height); 

}