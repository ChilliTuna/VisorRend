#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	GLFWwindow* window;

	int WindowWidth();
	int WindowHeight();

	void SetWindowDimensions(int width, int height);

	GLFWframebuffersizefun FrameBufferSizeCallBack();

private:	
	static void FrameBufferSizeCallbackInternal(GLFWwindow* window, int width, int height);
};