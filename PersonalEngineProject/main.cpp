#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//These includes might be related to file content read
#include<string>
#include<fstream>
#include<sstream>
#include<cerrno>



const unsigned int windowWidth = 800;
const unsigned int windowHeight = 600; 
const char windowName[] = "MainWindow";


void framebuffer_size_callback(GLFWwindow* window, int width, int height); 

std::string get_file_contents(const char* filename);


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

	


	// This part reads the content of shader files
	std::string vertexCode = get_file_contents("default.vert"); 
	const char* vertexSource = vertexCode.c_str();

	std::string fragmentCode = get_file_contents("default.frag");
	const char* fragmentSource = fragmentCode.c_str();


	// Shader objects are created
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER); 
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); 

	unsigned int fragmentShader; 
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader); 


	// Checked for shader compilation error. 
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); 

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER:VERTEX:COMPILATION_FAILED\n" << infoLog << std::endl;

	}

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER:FRAGMENT:COMPILATION_FAILED\n" << infoLog << std::endl;

	}

	// Created shader program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader); 



	// Created VAO and VBO 
	unsigned int VBO,VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Used program and drawed first triangle 
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

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


std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);

	}

	throw(errno);
}