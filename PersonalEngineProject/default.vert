#version 330 core
layout (location = 0) in vec3 aPos; 

/*
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
*/

uniform vec2 deltaMov;

void main(){

		//gl_Position = projection * view * model * vec4(aPos, 1.0f);
		gl_Position = vec4(vec3(aPos.x + deltaMov.x, aPos.y + deltaMov.y, aPos.z), 1.0f);

}