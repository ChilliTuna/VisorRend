#include "WindowManager.h"

WindowManager::WindowManager()
{
	window = glfwCreateWindow(1280, 720, "VisorRender", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack());
}

WindowManager::~WindowManager()
{
	glfwDestroyWindow(window);
	window = nullptr;
}

int WindowManager::WindowWidth()
{
	int width = 0;
	glfwGetFramebufferSize(window, &width, NULL);
	return width;
}

int WindowManager::WindowHeight()
{
	int height = 0;
	glfwGetFramebufferSize(window, NULL, &height);
	return height;
}

void WindowManager::SetWindowDimensions(int width, int height)
{
	glfwSetWindowSize(window, width, height);
}

GLFWframebuffersizefun WindowManager::FrameBufferSizeCallBack()
{
	return (GLFWframebuffersizefun)FrameBufferSizeCallbackInternal;
}

void WindowManager::FrameBufferSizeCallbackInternal(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
