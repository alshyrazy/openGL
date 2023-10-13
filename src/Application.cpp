/*#include "Utilis.h"

#define numVAOs 1
GLuint renderingProgram;
GLuint vao[numVAOs];


float indec[]
{
	0.0, 0.0,
	0.5, 0.0
};
void init(GLFWwindow* window)
{
	//unsigned int buff;
	renderingProgram = Utilis::createShaderProgram("res/shader/vertex.shader", "res/shader/fragment.shader");
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);

	//glGenBuffers(1, &buff);
	//glBindBuffer(GL_ARRAY_BUFFER, buff);
	//glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float), indec, GL_STATIC_DRAW);
	
}

float x = 0.0f; 
float inc = 1.0f;
float y = 0.0f;

// DISPLAY

	//GLuint vao[1];
	//GLuint vbo[2];
	//float vPosition[]
	//{
	//	0.0
	//};
void display(GLFWwindow* window, double currentTime) {

	//glGenVertexArrays(1, vao);
	//glBindVertexArray(vao[0]);
	//glGenBuffers(2, vbo);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vPosition), vPosition, GL_STATIC_DRAW);

	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);
	y += inc; 
	if (y > 360.0f) inc = -1.0f; 
	if (y < -360.0f) inc = 1.0f;
	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offsetM");
	glProgramUniform1f(renderingProgram, offsetLoc, y);

	GLuint offsetLoccol = glGetUniformLocation(renderingProgram, "colc");
	glProgramUniform1f(renderingProgram, offsetLoccol, x);

	glPointSize(30.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}



int main(void) {
	if (!glfwInit())
		return -1;
	//std::string test = Utilis::
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program1", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	glfwSwapInterval(1);
	init(window);

	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	double tim = glfwGetTime();
	std::cout << tim << std::endl;
	glfwDestroyWindow(window);
	glfwTerminate();
	
	exit(EXIT_SUCCESS);
}*/