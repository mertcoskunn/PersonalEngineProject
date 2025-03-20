#ifndef STATICMESH_H
#define STATICMESH_H

#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include<glm/glm.hpp>

class StaticMesh {

public:
	StaticMesh(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count);
	void setShader(Shader newShader);
	void drawMesh();
	void deleteRefs();
	void setIsVisible(bool newVisible) { _isVisible = newVisible;  };
	bool getIsVisible() { return _isVisible; };

	void AddLocation(GLfloat dx, GLfloat dy);
	GLfloat* getCurrentVertexLocation();

	
private:
	Shader _shader;
	VAO _vao;
	VBO _vbo;
	bool _isVisible; 
	GLfloat* _initVertices;
	GLfloat* _deltaLocation;
	glm::vec3 worldPosition; 

	int _vertexCount; 
	unsigned int _uniformId;


	//glm::mat4 _model;
};

#endif 