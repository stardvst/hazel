#pragma once

#include "Hazel/Core.h"
#include "Event.h"

#include <sstream>

namespace Hazel {

class HAZEL_API WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(const unsigned nWidth, const unsigned nHeight)
		: m_nWidth(nWidth)
		, m_nHeight(nHeight)
	{
	}

	unsigned getWidth() const { return m_nWidth; }
	unsigned getHeight() const { return m_nHeight; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_nWidth << ", " << m_nHeight;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(App)
private:
	unsigned int m_nWidth, m_nHeight;
};

class HAZEL_API WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(App)
};

class HAZEL_API AppTickEvent : public Event
{
public:
	AppTickEvent() = default;

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(App)
};

class HAZEL_API AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() = default;

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(App)
};

class HAZEL_API AppRenderEvent : public Event
{
public:
	AppRenderEvent() = default;

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(App)
};

}