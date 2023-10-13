#pragma once
#include "includes.h"
namespace Utilis {

std::string readShaderSource(const char* filePath);
GLuint createShaderProgram(const char* Vsource, const char* Fsource);
void printShaderLog(GLuint shader);
void printProgramLog(int prog);
bool checkOpenGLError();
}

