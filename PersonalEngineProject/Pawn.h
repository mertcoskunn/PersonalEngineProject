#ifndef PAWN_CLASS_H
#define PAWN_CLASS_H


#include "StaticMesh.h"
#include "MovementSystem.h"
#include "Camera.h"


class Pawn {

public:
	Pawn(glm::vec3 worldPosition, const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, InputSystem& inputs, Camera& camera);

	void Activate();
	void Deactivate(); 
	void Show();
	void Hide();
	void AddLocation();

	

private: 
	StaticMesh _staticMesh; 
	MovementSystem _movSystem;
	Camera& _camera;
	
	GLfloat _speed; 
	int _vertexCount;

	


}; 

#endif