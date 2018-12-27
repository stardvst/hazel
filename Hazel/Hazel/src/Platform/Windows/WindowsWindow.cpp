#include "hzpch.h"

#include "WindowsWindow.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel
{

static bool glfwInitialized = false;

Window *Window::create(const WindowProps &props /* = WindowProps{} */)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps &props)
{
	init(props);
}

WindowsWindow::~WindowsWindow()
{
	shutdown();
}

void WindowsWindow::init(const WindowProps &props)
{
	m_data.sTitle = props.sTitle;
	m_data.uWidth = props.uWidth;
	m_data.uHeight = props.uHeight;

	HZ_CORE_INFO("Creating window {0} ({1} {2})", m_data.sTitle, m_data.uWidth, m_data.uHeight);

	if (!glfwInitialized)
	{
		const auto success = glfwInit();
		HZ_CORE_ASSERT(success, "Could not initialize GLFW!");

		glfwInitialized = true;
	}

	m_pWindow = glfwCreateWindow(static_cast<int>(m_data.uWidth), static_cast<int>(m_data.uHeight), m_data.sTitle.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_pWindow);
	glfwSetWindowUserPointer(m_pWindow, &m_data);
	setVSync(true);
}

void WindowsWindow::shutdown()
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
