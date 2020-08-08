#pragma once

#include "Hazel/Window.h"

// forward declarations
struct GLFWwindow;

namespace Hazel
{

class OpenGLContext;

class WindowsWindow final : public Window
{
public:
	explicit WindowsWindow(const WindowProps &props);
	~WindowsWindow() override;

	void onUpdate() override;

	unsigned getWidth() const override { return m_data.uWidth; }
	unsigned getHeight() const override { return m_data.uHeight; }

	void setEventCallback(const eventCallbackFn &callback) override { m_data.eventCallback = callback; }
	void setVSync(bool bEnabled) override;
	bool isVSync() const override;

	void *getNativeWindow() const override;

private:
	GLFWwindow *m_pWindow = nullptr;
	OpenGLContext *m_pContext = nullptr;

	// for passing to GLFW as custom data
	struct WindowData final
	{
		std::string sTitle{};
		unsigned uWidth = 0;
		unsigned uHeight = 0;
		bool bVSync = false;
		eventCallbackFn eventCallback;
	};

	WindowData m_data;
};

inline void *WindowsWindow::getNativeWindow() const
{
	return m_pWindow;
}

}
