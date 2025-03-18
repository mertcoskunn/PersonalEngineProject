#include "ActorObject.h"


ActorObject::ActorObject(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, InputSystem& inputs)
	:
	_staticMesh(vertex_file, fragment_file, vertices, vertex_count),
	_movSystem(inputs)
{

	std::cout<<_movSystem.getIsEnabled();
	_speed = 0.0025; 
	_vertexCount = vertex_count; 
	
}



void ActorObject::Show() {

	_staticMesh.setIsVisible(true);
	_staticMesh.drawMesh();

}

void ActorObject::Hide() {

	_staticMesh.setIsVisible(false); 
}



void ActorObject::Activate() {

	this->AddLocation(); 
	this->Show(); 
}


void ActorObject::AddLocation() {
	
	std::vector<int> movDirect = _movSystem.getMovementDirections();
	_staticMesh.AddLocation((movDirect[3] - movDirect[2])* _speed, (movDirect[0] - movDirect[1]) * _speed);

}