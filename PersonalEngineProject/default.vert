#version 330 core
layout (location = 0) in vec3 aPos; 


uniform vec2 deltaMov; 

void main(){

		gl_Position = vec4(aPos.x+deltaMov.x, aPos.y+deltaMov.y, aPos.z, 1.0); 

}