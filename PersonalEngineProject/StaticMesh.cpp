#include"StaticMesh.h"




StaticMesh::StaticMesh(glm::vec3 worldPosition, const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count, Camera& camera)
	:
	_shader(vertex_file, fragment_file),
	_vao(),
	_vbo(vertices, vertex_count * sizeof(GLfloat)),
	_camera(camera) 
	{

	_initVertices = new GLfloat[vertex_count]; 
	_vertexCount = vertex_count;

	for (int i = 0; i < vertex_count; i++) {
		_initVertices[i] = vertices[i];
		
	}

	_isVisible = true; 
	_vao.LinkAttrib(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	_vao.Bind();

	_vao.Unbind();
	_vbo.Unbind();

	_worldLocation = worldPosition;
	
}



glm::mat4 StaticMesh::getModelMatrix() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _worldLocation);
	return model;
}

void StaticMesh::setShader(Shader newShader) {


}


void StaticMesh::drawMesh() {


	if (_isVisible) {
		_shader.Activate();

		glUniformMatrix4fv(_shader.getModelUniformID(), 1, GL_FALSE, glm::value_ptr(getModelMatrix()));
		glUniformMatrix4fv(_shader.getViewUniformID(), 1, GL_FALSE, glm::value_ptr(_camera.getViewMatrix()));
		glUniformMatrix4fv(_shader.getProjectionUniformID(), 1, GL_FALSE, glm::value_ptr(_camera.getProjectionMatrix()));

		_vao.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cout << "OpenGL Error: " << err << std::endl;
		}
	}
	
	
}

void StaticMesh::deleteRefs() {
	_shader.Delete();
	_vao.Delete();
	_vbo.Delete();
}



void StaticMesh::addLocation(glm::vec3 deltaLoc) {
	setWorldLocation(getWorldLocation() + deltaLoc); 
}




void StaticMesh::setWorldLocation(glm::vec3 newLoc){

	_worldLocation = newLoc; 


}

glm::vec3 StaticMesh::getWorldLocation() {


	return _worldLocation;
}


