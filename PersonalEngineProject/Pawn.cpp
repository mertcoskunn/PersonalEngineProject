#include "Pawn.h"


Pawn::Pawn(glm::vec3 worldPosition, const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, InputSystem& inputs, Camera& camera)
	:
	_staticMesh(worldPosition, vertex_file, fragment_file, vertices, vertex_count, camera),
	_movSystem(inputs),
	_camera(camera)
{
	std::cout<<_movSystem.getIsEnabled();
	_speed = 0.0025f; 
	_vertexCount = vertex_count; 
	
}



void Pawn::Show() {

	_staticMesh.setIsVisible(true);
	_staticMesh.drawMesh();

}

void Pawn::Hide() {

	_staticMesh.setIsVisible(false); 
}



void Pawn::Activate() {

	AddLocation(); 
	Show(); 
}


void Pawn::Deactivate() {

	_staticMesh.deleteRefs();
}


void Pawn::AddLocation() {

	std::vector<int> movDirect = _movSystem.getMovementDirections();
	
	
	_camera.addLocation(_camera.getForwardVector()*((movDirect[0] - movDirect[1]) * _speed));
	_staticMesh.addLocation(_camera.getForwardVector() * ((movDirect[0] - movDirect[1]) * _speed));
	

	//(movDirect[2] - movDirect[3]), be sure order of the subtraction ????  
	_camera.addLocation(_camera.getRightVector() * ((movDirect[2] - movDirect[3]) * _speed));
	_staticMesh.addLocation(_camera.getRightVector() * ((movDirect[2] - movDirect[3]) * _speed));

}