#include "hzpch.h"

#include <GLFW/glfw3.h>

#include "Hazel/Input.h"
#include "WindowsInput.h"
#include "Hazel/Application.h"

namespace Hazel
{

bool WindowsInput::isKeyPressed_impl(int nKeyCode) const
{
	auto window = static_cast<GLFWwindow *>(
		Application::get().getWindow().getNativeWindow());
	auto state = glfwGetKey(window, nKeyCode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::isMouseButtonPressed_impl(int nButton) const
{
	auto window = static_cast<GLFWwindow *>(
		Application::get().getWindow().getNativeWindow());
	auto state = glfwGetMouseButton(window, nButton);
	return state == GLFW_PRESS;
}

std::pair<float, float> WindowsInput::getMousePosition_impl() const
{
	auto window = static_cast<GLFWwindow *>(
		Application::get().getWindow().getNativeWindow());
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);
	return std::make_pair(static_cast<float>(xPos), static_cast<float>(yPos));
}

float WindowsInput::getMouseX_impl() const
{
	auto [x, y] = getMousePosition();
	return x;
}

float WindowsInput::getMouseY_impl() const
{
	auto [x, y] = getMousePosition();
	return y;
}

}
