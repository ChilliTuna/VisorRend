#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "ColourTester.h"

void DisplayErrorMessage(std::string errorMessage)
{
	std::cout << errorMessage << std::endl;
}

int main()
{
	int* windowWidth = new int(1280);
	int* windowHeight = new int(720);

	if (!glfwInit())
	{
		DisplayErrorMessage("You've experienced a crash on initialising glfw!");
		std::getchar;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "VisorRender", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		DisplayErrorMessage("You've experienced a crash on creating a window!");
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		DisplayErrorMessage("You've experienced a crash on loading GLAD!");
		return -1;
	}

	ColourTester* colTest = new ColourTester(0);

	while (!glfwWindowShouldClose(window))
	{
		glfwGetWindowSize(window, windowWidth, windowHeight);
		glViewport(0, 0, *windowWidth, *windowHeight);

		//render logic
		glClearColor(*(*colTest).colours[0], *(*colTest).colours[1], *(*colTest).colours[2], 0);
		(*colTest).CycleColours();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}