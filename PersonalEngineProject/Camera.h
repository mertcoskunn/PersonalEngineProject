#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H


#include<glm/glm.hpp>



class Camera {

	public: 
		Camera(glm::vec3 position,  glm::vec3 lookAtPos); 

		void setLocation(glm::vec3 newPos); 
		void setLookAtLocation(glm::vec3 newPos);

		void addLocation(glm::vec3 deltaLoc);
		
		//void setCameraRotation();
		//void getCameraRotation();
		void addRotation(float deltaYaw, float deltaPitch, float deltaRoll); //Function doesnt update roll yet.
		
	
		glm::vec3 getLocation();
		glm::vec3 getForwardVector();
		glm::vec3 getUpVector();
		glm::vec3 getRightVector();

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

	private:
		void updateForwardVector(); 
		  

		glm::vec3 _location; 
		glm::vec3 _lookAtLoc;
		glm::vec3 _forward; 
		//glm::vec3 _up; 
		//glm::vec3 _right;
		
		float _fov;
		glm::mat4 _projection;

		float _yaw;
		float _pitch;
		float _roll; 
};

#endif 