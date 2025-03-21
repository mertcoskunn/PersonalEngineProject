#include "Camera.h"
#include<glm/gtc/matrix_transform.hpp>



Camera::Camera(glm::vec3 position, glm::vec3 lookAtPos) {

	_position = position; 
	_lookAtPos = lookAtPos; 
	//_forward = glm::normalize( _position - _lookAtPos);
	_forward = glm::normalize(_lookAtPos - _position);
	_up = glm::vec3(0.0f, 1.0f, 0.0f);
	_right = glm::normalize(glm::cross(_up, _forward));
	_up = glm::normalize(glm::cross(_forward, _right));

	_fov = 45.0f; 
	_view = glm::mat4(1.0f);
	_view = glm::lookAt(_position, _position+_forward, _up);
	//_view = glm::lookAt(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, -5.0f)+_forward, _up);
	//_view = glm::translate(_view, glm::vec3(0.0f, 0.0f, -5.0f)); 

	//_projection = glm::perspective(glm::radians(_fov), 800.0f / 600.0f, 0.1f, 100.0f);
	_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	_yaw = -90.0f; 
	_pitch = 0.0f; 
	_roll = 0.0f; 
}

void Camera::setCameraLocation(glm::vec3 newPos) {
	_position = newPos; 
}


void Camera::setLookAtPosition(glm::vec3 newPos) {

	_lookAtPos = newPos; 

}

void Camera::updateDirectionVectors() {
	_forward = glm::normalize(_position - _lookAtPos);
	_up = glm::vec3(0.0f, 1.0f, 0.0f);
	_right = glm::normalize(glm::cross(_up, _forward));
	_up = glm::normalize(glm::cross(_forward, _right));
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
	//This part might be function, I am not sure. 
	_up = glm::vec3(0.0f, 1.0f, 0.0f);
	_right = glm::normalize(glm::cross(_up, _forward));
	_up = glm::normalize(glm::cross(_forward, _right));

}


void Camera::updateViewMatrix() {

	_view = glm::lookAt(_position, _position+_forward, _up);
}

glm::mat4 Camera::getViewMatrix() {
	return _view; 
}

glm::mat4 Camera::getProjectionMatrix() {
	return _projection;
}