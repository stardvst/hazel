#pragma once

#include "Hazel/Core.h"
#include "Event.h"

#include <sstream>

namespace Hazel
{

class HAZEL_API MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float fX, const float fY)
		: m_fX(fX)
		, m_fY(fY)
	{
	}

	float getX() const { return m_fX; }
	float getY() const { return m_fY; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_fX << ", " << m_fY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(Mouse | Input)
private:
	float m_fX;
	float m_fY;
};

class HAZEL_API MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_fXOffset(xOffset)
		, m_fYOffset(yOffset)
	{
	}

	float getXOffset() const { return m_fXOffset; }
	float getYOffset() const { return m_fYOffset; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(Mouse | Input)
private:
	float m_fXOffset;
	float m_fYOffset;
};

class HAZEL_API MouseButtonEvent : public Event
{
public:
	int getMouseButton() const { return m_nButton; }
	
	EVENT_CLASS_CATEGORY(Mouse | Input)
protected:
	explicit MouseButtonEvent(const int nButton)
		: m_nButton(nButton)
	{
	}

	int m_nButton;
};
class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	explicit MouseButtonPressedEvent(const int nButton)
		: MouseButtonEvent(nButton)
	{
	}

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_nButton;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	explicit MouseButtonReleasedEvent(const int nButton)
		: MouseButtonEvent(nButton)
	{
	}

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_nButton;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};
	
}
