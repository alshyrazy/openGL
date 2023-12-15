#include "Utilis.h"
#include "iostream"
#pragma region var
unsigned int renderer;
unsigned int vao[1];
unsigned int vbo[2];
unsigned int test;
unsigned int cool;
GLint vertCompiled;
GLint fragCompiled;
#pragma endregion


unsigned int createShader()
{
const char* Vsource = 
	R"(
		#version 430
		layout(location = 0) in vec3 Pos;

		mat4 buildTranslate(float x, float y, float z) {
		return mat4(
        1.0, 0.0, 0.0, x,
        0.0, 1.0, 0.0, y,
        0.0, 0.0, 1.0, z,
        0.0, 0.0, 0.0, 1.0
			);
		}
		mat4 shift = buildTranslate(0.5, 0.5, 0.0);
		void main()
		{
			gl_Position = shift * vec4(Pos, 1.0);
		}
		
	)";

const char* Fsource =
	R"(
		#version 430
		out vec4 color;
		
		void main(void)
		{
			color = vec4(0.0, 1.0, 0.0, 1.0);
		}
	)";

unsigned int Vshader = glCreateShader(GL_VERTEX_SHADER);
unsigned int Fshader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(Vshader, 1, &Vsource, NULL);
glShaderSource(Fshader, 1, &Fsource, NULL);
glCompileShader(Vshader);
Utilis::checkOpenGLError();
glGetShaderiv(Vshader, GL_COMPILE_STATUS, &vertCompiled);
if (vertCompiled != 1) {
	std::cout << "vertex compilation failed" << std::endl;
	Utilis::printShaderLog(Vshader);
}
glCompileShader(Fshader);
Utilis::checkOpenGLError();
glGetShaderiv(Fshader, GL_COMPILE_STATUS, &fragCompiled);
if (fragCompiled != 1) {
	std::cout << "fragment compilation failed" << std::endl;
	Utilis::printShaderLog(Fshader);
}
unsigned int program = glCreateProgram();
glAttachShader(program, Vshader);
glAttachShader(program, Fshader);
glValidateProgram(program);
glLinkProgram(program);
glDeleteShader(Vshader);
glDeleteShader(Fshader);
return program;
}

void init()
{

	float vert2[]
	{
		0.0, 0.0, 1.0,
		0.5, 0.5, 1.0,
		-0.5, 0.5, 1.0

	};

float vert[]
{
	0.0, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.5, -0.5, 0.0,

	0.0, 0.0, 0.0,
	-0.5, 0.5, 0.0,
	-0.5, -0.5, 0.0,
};
	unsigned int renderer = createShader();
	glGenVertexArrays(1, vao);
	glBindVertexArray( vao[0]);
	glGenBuffers(2, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert2), vert2, GL_STATIC_DRAW);
}

void display()
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(renderer);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glPointSize(30.0f);
	glDrawArrays(GL_TRIANGLES, 0, 9);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glPointSize(30.0f);
	glDrawArrays(GL_TRIANGLES, 0, 9);
}

int main()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(800, 800, "jain", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return - 1;
	glfwSwapInterval(1);

	init();

	while (!glfwWindowShouldClose(window))
	{
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	
}