#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "inc/Drawable.h"

using namespace std;

static void error_callback(int error, const char* description){
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
int main(void)
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	
	if (!glfwInit()){
		exit(EXIT_FAILURE);
	
	}
	
	Drawable d;
	
	d.setVertices( "models/cube.obj" );
	const vector< glm::vec3* >* v = d.getVertices();
	
	for(unsigned int i=0; i<v->size(); i++){
		cout << v->at(i)->x << ' ';
		cout << v->at(i)->y << ' ';
		cout << v->at(i)->z << endl;
	}
	
	window = glfwCreateWindow(800, 600, "Arkanoid 3D", NULL, NULL);
	if (!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window)){
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}
