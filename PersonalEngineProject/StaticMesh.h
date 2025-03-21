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

	void addLocation(glm::vec3 deltaLoc);
	void setWorldLocation(glm::vec3 newLoc);

	glm::vec3 getWorldLocation();
	glm::mat4 getModelMatrix(); 
	
private:
	Shader _shader;
	VAO _vao;
	VBO _vbo;
	bool _isVisible; 
	GLfloat* _initVertices;

	glm::vec3 _worldLocation; 
	int _vertexCount;
	Camera& _camera; 


};

#endif 