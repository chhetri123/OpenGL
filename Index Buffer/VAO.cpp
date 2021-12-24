#include "VAO.h"
VAO::VAO() {
	glGenVertexArrays(1, &ID);

}
void VAO::  LinkVBO (VBO VBO, GLuint layout) {
	VBO.Bind();
	//Configure the vertex Attribute so that openGL knows how to read VBO
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//Enable the vertex Attributes so that OpenGL Knows how to use it 
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}
void VAO::Bind() {
	glBindVertexArray(ID);

}
void VAO::Unbind() {
	glBindVertexArray(ID);

}
void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);

}