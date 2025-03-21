#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H


#include<glm/glm.hpp>



class Camera {

	public: 
		Camera(glm::vec3 position,  glm::vec3 lookAtPos); 

		void setCameraLocation(glm::vec3 newPos); 
		void setLookAtPosition(glm::vec3 newPos); 
		glm::vec3 getCameraLocation(); 
		//void setCameraRotation();
		//void getCameraRotation();
		glm::vec3  getForwardVector(); 
		glm::vec3 getUpVector();
		glm::vec3 getRightVector();

		
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

	private:
		void updateDirectionVectors(); 
		void updateViewMatrix();
		void addRotation(float deltaYaw, float deltaPitch, float deltaRoll); //Function doesnt update roll yet.  

		glm::vec3 _position; // glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 _lookAtPos;
		glm::vec3 _forward; 
		glm::vec3 _up; 
		glm::vec3 _right;
		
		float _fov;

		glm::mat4 _view;
		glm::mat4 _projection;

		float _yaw;
		float _pitch;
		float _roll; 
};

#endif 