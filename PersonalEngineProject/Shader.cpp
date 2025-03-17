#include"Shader.h"



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

Shader::Shader(const char* vertex_file, const char* fragment_file) {

	
	std::string vertexCode = get_file_contents(vertex_file);
	const char* vertexSource = vertexCode.c_str();

	std::string fragmentCode = get_file_contents(fragment_file);
	const char* fragmentSource = fragmentCode.c_str();
	

	// Shader objects are created
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	CompileErrors(vertexShader, "VERTEX");

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	CompileErrors(fragmentShader, "FRAGMENT");


	

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CompileErrors(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
}


GLuint Shader::getID(){
	return ID; 
}


void Shader::Activate() {

	glUseProgram(ID);
}

void Shader::Delete() {

	glDeleteProgram(ID); 
}


void Shader::CompileErrors(unsigned int shader, const char* type) {


	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM") {

		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {

			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << std::endl;


		}

	}

	else {

		glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {

			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << std::endl;


		}

	}


}

