#pragma once
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H


#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader {
public:
	GLuint ID;
	// Constructs that build the shader Progrma from 2 Different shaders 
	Shader(const char* vertexFile, const char* fragmentfile);

	//Activates the shader Program 
	void Activate();

	//Deletes th shader Programs
	void Delete();

};


#endif