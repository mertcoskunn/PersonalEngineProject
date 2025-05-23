#ifndef  SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>


std::string get_file_contents(const char* filename);



class Shader {

	public:
		Shader(const char* vertex_file, const char* fragment_file);
		GLuint getID();

		void Activate();
		void Delete();
		GLuint getModelUniformID() { return _modelLoc;}; 
		GLuint getViewUniformID() { return _viewLoc; };
		GLuint getProjectionUniformID() { return _projectionLoc;};

	private:
		GLuint ID;
		void CompileErrors(unsigned int shader, const char* type);

		GLuint _modelLoc;
		GLuint _viewLoc; 
		GLuint _projectionLoc; 
};

#endif