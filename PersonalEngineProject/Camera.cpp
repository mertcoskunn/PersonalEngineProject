#include "Camera.h"
#include<glm/gtc/matrix_transform.hpp>



Camera::Camera(glm::vec3 position, glm::vec3 lookAtPos) {

	_location = position; 
	_lookAtLoc = lookAtPos;
	
	updateForwardVector();

	_fov = 45.0f; 
	_projection = glm::perspective(glm::radians(_fov), 800.0f / 600.0f, 0.1f, 100.0f);


	_yaw = -90.0f; 
	_pitch = 0.0f; 
	_roll = 0.0f; 
}

void Camera::setLocation(glm::vec3 newPos) {
	_location = newPos;
}


void Camera::setLookAtLocation(glm::vec3 newPos) {

	_lookAtLoc = newPos;
	updateForwardVector();

}


void Camera::addLocation(glm::vec3 deltaLoc) {

	setLocation(getLocation() + deltaLoc); 
}

//every time when you update _lookAt, you have to call updateDirectionVectors()
void Camera::updateForwardVector() {
	_forward = glm::normalize(_lookAtLoc - _location);
}



void Camera::addRotation(float deltaYaw, float deltaPitch, float deltaRoll) {

	_yaw += deltaYaw;
	_pitch += deltaPitch;

	if (_pitch > 89.0f)
		_pitch = 89.0f;
	if (_pitch < -89.0f)
		_pitch = -89.0f;

	glm::vec3 tempDirection;
	tempDirection.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	tempDirection.y = sin(glm::radians(_pitch));
	tempDirection.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));


	_forward = glm::normalize(tempDirection);

}


glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(_location, _location + getForwardVector(), getUpVector());
}

glm::mat4 Camera::getProjectionMatrix() {
	return _projection;
}


glm::vec3 Camera::getLocation() {
	return _location;
}


glm::vec3 Camera::getForwardVector() {
	return _forward;
}

glm::vec3 Camera::getRightVector() {
	return glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), _forward));
}


glm::vec3 Camera::getUpVector() {
	return glm::normalize(glm::cross(getForwardVector(), getRightVector()));
}