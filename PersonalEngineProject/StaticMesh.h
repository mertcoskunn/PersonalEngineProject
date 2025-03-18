#ifndef STATICMESH_H
#define STATICMESH_H

#include"Shader.h"
#include"VAO.h"
#include"VBO.h"


class StaticMesh {

public:
	StaticMesh(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count);
	void setShader(Shader newShader);
	void drawMesh(); 

	
private:
	Shader _shader;
	VAO _vao;
	VBO _vbo;

};

#endif 