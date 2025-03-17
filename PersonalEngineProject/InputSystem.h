#ifndef  INPUTSYSTEM_CLASS_H
#define INPUTSYSTEM_CLASS_H

#include <GLFW/glfw3.h>
#include <map>
#include <vector>

class InputSystem
{
public:
	InputSystem(std::vector<int> userKeys);
	~InputSystem();
	bool getIsKeyDown(int key);
	bool getIsEnabled() { return _isEnabled;  };
	void setIsEnabled(bool val) { _isEnabled = val;  };
	static void setupKeyInputs(GLFWwindow* window);

private:
	std::map<int, bool> _keys;
	static std::vector<InputSystem*> _instances;
	bool _isEnabled;
	void setIsKeyDown(int key, bool isDown);
	static void callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};

#endif 
#pragma once
