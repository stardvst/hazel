#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"

namespace Hazel
{

// forward declarations
class Event;

struct WindowProps
{
	explicit WindowProps(std::string title = "Hazel Engine",
		const unsigned width = 1280, const unsigned height = 720)
		: sTitle(std::move(title))
		, uWidth(width)
		, uHeight(height)
	{
	}

	std::string sTitle{};
	unsigned uWidth = 0;
	unsigned uHeight = 0;
};

// Interface representing a desktop system based window
class HAZEL_API Window
{
public:
	using eventCallbackFn = std::function<void(Event &)>;

	virtual ~Window() = default;

	virtual void onUpdate() = 0;

	virtual unsigned getWidth() const = 0;
	virtual unsigned getHeight() const = 0;

	// Window attributes
	virtual void setEventCallback(const eventCallbackFn &callback) = 0;
	virtual void setVSync(bool bEnabled) = 0;
	virtual bool isVSync() const = 0;

	virtual void *getNativeWindow() const = 0;

	// To be implemented per platform (in implementation file)
	static Window *create(const WindowProps &props = WindowProps{});
};

}
