#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;


// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


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


	// Vertices Coordinates

	GLfloat vertices[] = {
		-0.5f,-0.5f * float(sqrt(3)) / 3,0.0f, //lower left corner
		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,// Lower right corner 
		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f, //Upper corner

	};

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



	//Create Vertex shader object and get its reference 
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//Attach Vertex shader source to the vertex shader object 
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	//compile the vertex shader into the machine code
	glCompileShader(vertexShader);

	//create Fragment shader object and get its reference 
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//Attach Fragment shader source to the Fragment shader object 
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);


	//Compile the vertex shader into machine code 
	glCompileShader(fragmentShader);

	//Create Shader Program Object and get its reference 

	GLuint shaderProgram = glCreateProgram();

	//attach the vertex and fragment Shader to the shader program 
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);


	//Wrap-up/Link all the shaders togethers into the shader Program 
	glLinkProgram(shaderProgram);

	//Delete the useless vertex and Fragment shader object 
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	//Create reference Container for the vertex Array Object and the Vertex Buffer 
	GLuint VAO, VBO;

	//Generate the VAO and VBO with only 1 object 
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//Make the VAO the current Vertex Array object by binding it 
	glBindVertexArray(VAO);


	//Bind the VBO specifing its a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Configure the vertex Attribute so that openGL knows how to read VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//Enable the vertex Attributes so that OpenGL Knows how to use it 
	glEnableVertexAttribArray(0);

	//Bind the both VAO and VBO  to 0 so that we don't accidentally modify the VAO and VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


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
		glUseProgram(shaderProgram);

		// Bind the VAO so OpenGl knows to use it 
		glBindVertexArray(VAO);

		// Draw the triangle using the GL_TRIANGLE 
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		//Take care of all GLFW event 
		glfwPollEvents();
	}

	//Deleting all the object  what we've created 
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VAO);
	glDeleteProgram(shaderProgram);

	//Delete the window before ending the program
	glfwDestroyWindow(window);
	//terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}