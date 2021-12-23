#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;

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
		cout << "Failed to create GLFW window" << endl;
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
		//Take care of all GLFW event 
		glfwPollEvents();
	}

	//Delete the window before ending the program
	glfwDestroyWindow(window);
	//terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}