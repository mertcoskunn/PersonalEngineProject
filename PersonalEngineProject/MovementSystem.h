#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include"InputSystem.h"

class MovementSystem {

public: 
	MovementSystem(InputSystem& inputs);
	std::vector<int> getMovementDirections(); 
	bool getIsEnabled() const { return _isEnabled; }; 
	void setIsEnabled(bool val) { _isEnabled = val; };

private: 
	bool _isEnabled;
	InputSystem& _inputs; 
};

#endif 