#include"StaticMesh.h"




StaticMesh::StaticMesh(const char* vertex_file, const char* fragment_file, GLfloat* vertices, int vertex_count)
	:
	_shader(vertex_file, fragment_file),
	_vao(),
	_vbo(vertices, vertex_count * sizeof(GLfloat))
	{
	
	_vao.LinkAttrib(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	_vao.Bind();

	_vao.Unbind();
	_vbo.Unbind();
}



void StaticMesh::setShader(Shader newShader) {


}


void StaticMesh::drawMesh() {

	_shader.Activate();
	
	_vao.Bind();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cout << "OpenGL Error: " << err << std::endl;
	}
	
}