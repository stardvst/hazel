#pragma once

#include "Hazel/Core.h"
#include "Event.h"

#include <sstream>

namespace Hazel
{

class HAZEL_API KeyEvent : public Event
{
public:
	int getCode() const { return m_nKeyCode; }

	EVENT_CLASS_CATEGORY(Keyboard | Input)
protected:
	explicit KeyEvent(const int nKeyCode)
		: m_nKeyCode(nKeyCode)
	{
	}

	int m_nKeyCode;
};

class HAZEL_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(const int nKeyCode, const int nRepeatCount)
		: KeyEvent(nKeyCode)
		, m_nRepeatCount(nRepeatCount)
	{
	}

	int getRepeatCount() const { return m_nRepeatCount; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_nKeyCode << " (" << m_nRepeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)
private:
	int m_nRepeatCount;
};

class HAZEL_API KeyReleasedEvent : public KeyEvent
{
public:
	explicit KeyReleasedEvent(const int nKeycode)
		: KeyEvent(nKeycode)
	{
	}

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_nKeyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};
	
}
