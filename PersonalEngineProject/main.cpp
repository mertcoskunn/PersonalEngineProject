#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//These includes might be related to file content read
#include<string>
#include<fstream>
#include<sstream>
#include<cerrno>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Shader.h"
#include"VBO.h"
#include"VAO.h"
#include"InputSystem.h"
#include"MovementSystem.h"
#include"StaticMesh.h"
#include"Pawn.h"
#include"Camera.h"



const unsigned int windowWidth = 800;
const unsigned int windowHeight = 600; 
const char windowName[] = "MainWindow";


void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void esc_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


GLfloat vertices[] = {
-0.1f, -0.1f, 0.0f,
0.1f, -0.1f, 0.0f,
0.0f, 0.1f, 0.0f
};

GLfloat vertices2[] = {
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
	
	glEnable(GL_DEPTH_TEST);


	glfwSetKeyCallback(window, esc_key_callback);
	
	std::vector<int> keys = { GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D };

	InputSystem inputs(keys);
	inputs.setIsEnabled(true);
	inputs.setupKeyInputs(window);
	inputs.setupMouseInputs(window);
	

	
	glm::vec3 camPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 lookAtPos = glm::vec3(0.0f, 0.0f, 0.0f);

	
	Camera camera(camPosition, lookAtPos);
	Pawn pawn(glm::vec3(0.0f, 0.0f, 0.0f),"default.vert", "default.frag", vertices, sizeof(vertices) / sizeof(vertices[0]),inputs,camera);
	
	StaticMesh testMesh(glm::vec3(0.0f, 0.0f, 0.0f), "default.vert", "red.frag", vertices2, sizeof(vertices2) / sizeof(vertices2[0]), camera);

	
	

	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pawn.Activate();
		testMesh.drawMesh();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	pawn.Deactivate();
	glfwTerminate();
	return 0; 

}





void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height); 

}




void esc_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true); // Pencereyi kapat
	}
}