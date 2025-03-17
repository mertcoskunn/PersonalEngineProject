#include "InputSystem.h"
#include<algorithm>



std::vector<InputSystem*> InputSystem::_instances ;  

InputSystem::InputSystem(std::vector<int> userKeys) {

	for (int key: userKeys) {

		_keys[key] = false;
	}

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
	glfwSetKeyCallback(window, callback);

}

void InputSystem::callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	for (InputSystem* input : _instances) {
		input->setIsKeyDown(key, action != GLFW_RELEASE);
	}
}
