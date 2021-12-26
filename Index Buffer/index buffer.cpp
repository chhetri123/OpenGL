#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


// Vertices Coordinates

GLfloat vertices[] = {
	-0.5f,-0.5f * float(sqrt(3)) / 3,0.0f, //lower left corner
	0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,// Lower right corner 
	0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f, //Upper corner

	-0.5f / 2,0.5f * float(sqrt(3)) / 6,0.0f, //Inner Left  
	0.5f / 2,0.5f * float(sqrt(3)) / 6,0.0f, //Inner Right  
	0.0f,-0.5f * float(sqrt(3)) / 3,0.0f, //Inner down 


};

GLuint indices[] = {
	0,3,5,//Lower left Triangle 
	3,2,4,// Lower Right Triangle 
	5,4,1 //Upper triangle 
};



int main() {




	// Initilization GLFW
	glfwInit();

	//Tell GLFW what  version of openGL we are using 
	//in this case we are using OpenGl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//tell GLFW we are using the CORE profile 
	//so that means we only have the modern functions

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	
	//Create a GLFWwindow object of 800 by 800 pixels,naming it "manish "
	GLFWwindow* window = glfwCreateWindow(800, 800, "Manish", NULL, NULL);

	//Error checking if window fails to create 
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;

	}


	//Introduce the window into the current context 
	glfwMakeContextCurrent(window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();

	//Sepcify the viewPoint of OpenGl in the window
	//In this case the view point goes feom x=0 ,y=0 to x=800,y=800
	glViewport(0, 0, 800, 800);


	//Generates Shader Object using shade default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	//Generates vertex Array Object and Binds it
	VAO VAO1;
	VAO1.Bind();

	//Generates Vertex Buffer Object And links it to vertices 
	VBO VBO1(vertices, sizeof(vertices));

	// Generates Element Buffer Object and Links it to indices
	EBO EBO1(indices, sizeof(indices));

	//Links VAO
	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	// Links VBO and EBO
	VBO1.Unbind();
	EBO1.Unbind();

	


	// specify the color of background 
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// clear color and give another color
	//clean the buffer and assign the new color to it 
	glClear(GL_COLOR_BUFFER_BIT);

	//swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	//glfwMakeContextCurrent(window);


	//main while loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//tell openGL which shader Program we want to use 
		shaderProgram.Activate();


		// Bind the VAO so OpenGl knows to use it 
		VAO1.Bind();

		// Draw the triangle using the GL_TRIANGLE 
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		//Take care of all GLFW event 
		glfwPollEvents();
	}

	//Deleting all the object  what we've created 
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();



	//Delete the window before ending the program
	glfwDestroyWindow(window);
	//terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}