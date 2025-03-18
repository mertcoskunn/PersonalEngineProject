#ifndef ACTOROBJECT_CLASS_H
#define ACTOROBJECT_CLASS_H


#include "StaticMesh.h"
#include "MovementSystem.h"


class ActorObject {

public:
	ActorObject(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, InputSystem& inputs);

	void Activate(); 
	void Show();
	void Hide();
	void AddLocation();
	

private: 
	StaticMesh _staticMesh; 
	MovementSystem _movSystem;
	GLfloat _speed; 
	int _vertexCount;


}; 

#endif