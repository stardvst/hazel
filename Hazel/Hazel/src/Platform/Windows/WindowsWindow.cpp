#include "hzpch.h"

#include "WindowsWindow.h"
#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace Hazel
{

static bool glfwInitialized = false;

static void GLFWErrorCallback(const int error, const char *description)
{
	HZ_CORE_ERROR("GLFW Error: ({0}): {1}", error, description);
}

Window *Window::create(const WindowProps &props /* = WindowProps{} */)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps &props)
{
	m_data.sTitle = props.sTitle;
	m_data.uWidth = props.uWidth;
	m_data.uHeight = props.uHeight;

	HZ_CORE_INFO("Creating window {0} ({1} {2})", m_data.sTitle, m_data.uWidth, m_data.uHeight);

	if (!glfwInitialized)
	{
		const auto success = glfwInit();
		HZ_CORE_ASSERT(success, "Could not initialize GLFW!");

		glfwSetErrorCallback(GLFWErrorCallback);
		glfwInitialized = true;
	}

	m_pWindow = glfwCreateWindow(static_cast<int>(m_data.uWidth), static_cast<int>(m_data.uHeight), m_data.sTitle.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_pWindow);
	glfwSetWindowUserPointer(m_pWindow, &m_data);
	setVSync(true);

	// set GLFW callbacks
	glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow *window, int width, int height)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
		data.uWidth = width;
		data.uHeight = height;

		WindowResizeEvent event(width, height);
		data.eventCallback(event);
	});

	glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow *window)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
		WindowCloseEvent event;
		data.eventCallback(event);
	});

	glfwSetKeyCallback(m_pWindow, [](GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));

		switch (action)
		{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.eventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.eventCallback(event);
				break;
			}
			default:
				break;
		}
	});

	glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow *window, const int button, const int action, int mods)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));

		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.eventCallback(event);
				break;
			}
			default:
				break;;
		}
	});

	glfwSetScrollCallback(m_pWindow, [](GLFWwindow *window, const double xOffset, const double yOffset)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
		MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
		data.eventCallback(event);
	});

	glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow *window, const double xPos, const double yPos)
	{
		auto &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
		MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
		data.eventCallback(event);
	});
}

WindowsWindow::~WindowsWindow()
{
	glfwDestroyWindow(m_pWindow);
}

void WindowsWindow::onUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_pWindow);
}

void WindowsWindow::setVSync(const bool bEnabled)
{
	bEnabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
	m_data.bVSync = bEnabled;
}

bool WindowsWindow::isVSync() const
{
	return m_data.bVSync;
}

}
