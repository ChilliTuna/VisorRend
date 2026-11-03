#include "TimeManager.h"
#include <GLFW/glfw3.h>

TimeManager::TimeManager()
{
}

TimeManager::~TimeManager()
{
}

void TimeManager::UpdateDeltaTime()
{
	newTime = glfwGetTime();
	deltaTime = newTime - previousTime;
	previousTime = newTime;
}

float TimeManager::DeltaTime()
{
	return deltaTime;
}