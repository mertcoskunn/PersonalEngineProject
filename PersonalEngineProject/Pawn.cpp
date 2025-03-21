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

	_prevMouseX = 0.0f; 
	_prevMouseY = 0.0f; 


	_distance = glm::distance(worldPosition, _camera.getLocation());
	_sensitivity = 0.1f; 
	
}



void Pawn::Show() {

	_staticMesh.setIsVisible(true);
	_staticMesh.drawMesh();

}

void Pawn::Hide() {

	_staticMesh.setIsVisible(false); 
}



void Pawn::Activate() {

	updateDirection();
	AddLocation(); 
	Show(); 
}


void Pawn::Deactivate() {

	_staticMesh.deleteRefs();
}


void Pawn::updateDirection() {

	float xpos = _movSystem.getMouseCoordinates()[0];
	float ypos = _movSystem.getMouseCoordinates()[1];

	float deltaX = xpos - _prevMouseX;
	float deltaY = _prevMouseY - ypos; // reversed since y-coordinates go from bottom to top
	_prevMouseX = xpos;
	_prevMouseY = ypos;


	
	deltaX *= _sensitivity;
	deltaY *= _sensitivity;


	_camera.addRotation(deltaX, deltaY, 0.0f);
}

void Pawn::AddLocation() {

	std::vector<int> movDirect = _movSystem.getMovementDirections();
	
	
	_camera.addLocation(_camera.getForwardVector()*((movDirect[0] - movDirect[1]) * _speed));
	
	//(movDirect[2] - movDirect[3]), be sure order of the subtraction ????  
	_camera.addLocation(_camera.getRightVector() * ((movDirect[2] - movDirect[3]) * _speed));
	
	_staticMesh.setWorldLocation((_camera.getForwardVector() * _distance) + _camera.getLocation());

}