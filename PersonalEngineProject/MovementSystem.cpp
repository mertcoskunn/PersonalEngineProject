#include "MovementSystem.h"



MovementSystem::MovementSystem(InputSystem& inputs):_inputs(inputs) {
	
	
	_isEnabled = true; 
}



std::vector<int> MovementSystem::getMovementDirections() {

	std::vector<int> result = {0,0,0,0};
	if (_isEnabled){ 
		if (_inputs.getIsKeyDown(GLFW_KEY_W)) {
			result[0] = 1; 
		}
		if (_inputs.getIsKeyDown(GLFW_KEY_S)) {
			result[1] = 1;
		}
		if (_inputs.getIsKeyDown(GLFW_KEY_A)) {
			result[2] = 1;
		}
		if (_inputs.getIsKeyDown(GLFW_KEY_D)) {
			result[3] = 1;
		}
	}
	return result;
	
}


