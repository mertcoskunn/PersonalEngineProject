#include"StaticMesh.h"




StaticMesh::StaticMesh(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count)
	:
	_shader(vertex_file, fragment_file),
	_vao(),
	_vbo(vertices, vertex_count * sizeof(GLfloat))
	{

	_initVertices = new GLfloat[vertex_count]; 
	_deltaLocation = new GLfloat[2]{ 0.0, 0.0 };
	_vertexCount = vertex_count;

	for (int i = 0; i < vertex_count; i++) {
		_initVertices[i] = vertices[i];
		
	}

	_isVisible = true; 
	_vao.LinkAttrib(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	_vao.Bind();

	_vao.Unbind();
	_vbo.Unbind();

	_uniformId = glGetUniformLocation(_shader.getID(), "deltaMov");
}



void StaticMesh::setShader(Shader newShader) {


}


void StaticMesh::drawMesh() {


	if (_isVisible) {
		_shader.Activate();

		glUniform2fv(_uniformId,1, _deltaLocation);

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



void StaticMesh::AddLocation(GLfloat dx, GLfloat dy) {

	_deltaLocation[0] += dx; 
	_deltaLocation[1] += dy; 

}


GLfloat* StaticMesh::getCurrentVertexLocation() {
	GLfloat* currVertex = new GLfloat[_vertexCount];

	for (int i = 0; i < _vertexCount; i++) {

		if ((i == 0) or (i == 3) or (i == 6)) {
			currVertex[i] = _initVertices[i] + _deltaLocation[0];
		}
		else if ((i == 1) or (i == 4) or (i == 7)) {
			currVertex[i] = _initVertices[i] + _deltaLocation[1];
		}
		else {
			currVertex[i] = _initVertices[i];
		}
		
	}

	return currVertex;
};

