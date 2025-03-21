#include "InputSystem.h"
#include<algorithm>



std::vector<InputSystem*> InputSystem::_instances ;  
float InputSystem::_xPosMouse;
float InputSystem::_yPosMouse;

InputSystem::InputSystem(std::vector<int> userKeys) {

	for (int key: userKeys) {

		_keys[key] = false;
	}
	_xPosMouse = 0.0f;
	_yPosMouse = 0.0f;

	InputSystem::_instances.push_back(this);

	
}


InputSystem::~InputSystem() {

	_instances.erase(std::remove(_instances.begin(), _instances.end(), this), _instances.end());
}


bool InputSystem::getIsKeyDown(int key) {
	bool result = false; 
	if (_isEnabled) {
		std::map<int, bool>::iterator it = _keys.find(key);
		if (it != _keys.end()) {
			result = _keys[key];
		}

	}
	return result; 

}


void InputSystem::setIsKeyDown(int key, bool isDown) {
	std::map<int, bool>::iterator it = _keys.find(key);
	if (it != _keys.end()) {
		_keys[key] = isDown; 
	}
}


void InputSystem::setupKeyInputs(GLFWwindow* window) {
	glfwSetKeyCallback(window, keyboardCallback);

}

void InputSystem::setupMouseInputs(GLFWwindow* window) {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouseCallback);

}

void InputSystem::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	for (InputSystem* input : _instances) {
		input->setIsKeyDown(key, action != GLFW_RELEASE);
	}
}


void InputSystem::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	_xPosMouse = static_cast<float>(xpos);
	_yPosMouse = static_cast<float>(ypos);
}

std::vector<float> InputSystem::getMouseCoordinates() {

	std::vector<float> coordinates = {_xPosMouse, _yPosMouse };
	return coordinates;
}