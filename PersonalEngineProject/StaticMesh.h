#ifndef STATICMESH_H
#define STATICMESH_H

#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Camera.h" 

class StaticMesh {

public:
	StaticMesh(glm::vec3 worldPosition,const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, Camera& camera);
	void setShader(Shader newShader);
	void drawMesh();
	void deleteRefs();
	void setIsVisible(bool newVisible) { _isVisible = newVisible;  };
	bool getIsVisible() { return _isVisible; };

	//void AddLocation(GLfloat dx, GLfloat dy);
	GLfloat* getCurrentVertexLocation();

	
private:
	Shader _shader;
	VAO _vao;
	VBO _vbo;
	bool _isVisible; 
	GLfloat* _initVertices;
	//GLfloat* _deltaLocation;
	
	glm::vec3 _worldPosition; 
	int _vertexCount;
	Camera& _camera; 


	glm::mat4 _model;
};

#endif 