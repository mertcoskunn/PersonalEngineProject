#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//These includes might be related to file content read
#include<string>
#include<fstream>
#include<sstream>
#include<cerrno>

#include"Shader.h"
#include"VBO.h"
#include"VAO.h"
#include"InputSystem.h"
#include"MovementSystem.h"




const unsigned int windowWidth = 800;
const unsigned int windowHeight = 600; 
const char windowName[] = "MainWindow";


void framebuffer_size_callback(GLFWwindow* window, int width, int height); 



float vertices[] = {
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};


int main() {
	 
	// Configure GLFW 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create GLFW window
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl; 
		glfwTerminate();
		return -1; 

	}
	
	// Adjust current context 
	glfwMakeContextCurrent(window); 

	
	// Check GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1; 
	}
	
	// Set gl viewport 
	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

	
	Shader shader1("default.vert", "default.frag");
	
	VAO VAO1;
	VBO VBO1(vertices, sizeof(vertices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	VAO1.Bind();

	VAO1.Unbind();
	VBO1.Unbind();


	std::vector<int> keys = {GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D};

	InputSystem inputs(keys);
	inputs.setIsEnabled(true);
	inputs.setupKeyInputs(window);


	MovementSystem movementInputs(&inputs); 
	
	std::vector<int> mov = { 0,0,0,0 };

	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (inputs.getIsKeyDown(GLFW_KEY_W)) {
			mov = movementInputs.getMovementDirections();
			std::cout << mov[0]<<" "<<mov[1] << " " << mov[2] << " " << mov[3] << "\n";
		
		}
		

		// Used program and drawed first triangle 
		shader1.Activate();
		VAO1.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

		

	}

	// Clean/delete all of GLFW's resources 
	shader1.Delete();
	VBO1.Delete();
	VAO1.Delete();
	glfwTerminate();
	return 0; 

}





void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height); 

}




