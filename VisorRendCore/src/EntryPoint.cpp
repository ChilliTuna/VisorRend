#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <glm/glm.hpp>
#include "ProofOfConcept/ColourTester.h"
#include "Utilities/WindowManager.h"
#include "Utilities/TimeManager.h"

void ConsolePrint(std::string errorMessage)
{
	std::cout << errorMessage << std::endl;
}

int main()
{
	//Initial setup and error handling
	WindowManager* winManager = new WindowManager();
	{
		if (!glfwInit())
		{
			ConsolePrint("You've experienced a crash on initialising glfw!");
			std::getchar;
			return -1;
		}

		if (winManager->window == NULL)
		{
			glfwTerminate();
			ConsolePrint("You've experienced a crash on creating a window!");
			std::getchar;
			return -1;
		}
		
		glfwMakeContextCurrent(winManager->window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ConsolePrint("You've experienced a crash on loading GLAD!");
			std::getchar;
			return -1;
		}
	}

	//Pre-first-loop prep
	TimeManager* timeManager = new TimeManager();
	ColourTester* colTest = new ColourTester(0);

	//Main loop
	while (!glfwWindowShouldClose(winManager->window))
	{
		//prep for this loop
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		timeManager->UpdateDeltaTime();


		//behaviour logic here
		colTest->CycleColours();

		
		//render logic here
		glClearColor(*(*colTest).colours[0], *(*colTest).colours[1], *(*colTest).colours[2], 0);


		//display frame
		glfwSwapBuffers(winManager->window);
	}

	//Shutdown
	glfwTerminate();
	return 0;
}