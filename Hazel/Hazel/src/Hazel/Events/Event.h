#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

namespace Hazel
{

enum class EEventType
{
	None,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EEventCategory
{
	None,
	App = BIT(0),
	Input = BIT(1),
	Keyboard = BIT(2),
	Mouse = BIT(3),
	MouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(type) static EEventType getStaticType() { return EEventType::##type; } \
							   EEventType getType() const override { return getStaticType(); } \
							   const char *getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) int getCategoryFlags() const override { return category; }

class HAZEL_API Event
{
	friend class EventDispatcher;
public:
	virtual ~Event() = default;
	virtual EEventType getType() const = 0;
	virtual const char *getName() const = 0;
	virtual int getCategoryFlags() const = 0;
	virtual std::string toString() const { return getName(); }

	bool isInCategory(const EEventCategory category) const
	{
		return getCategoryFlags() & category;
	}

	bool bIsHandled = false;
};

class EventDispatcher
{
	template <typename TEvent>
	using eventFn = std::function<bool(TEvent &)>;

public:
	explicit EventDispatcher(Event &event)
		: m_event(event)
	{
	}

	template <typename TEvent>
	bool dispatch(eventFn<TEvent> func)
	{
		if (m_event.getType() == TEvent::getStaticType())
		{
			m_event.bIsHandled = func(*static_cast<TEvent *>(&m_event));
			return true;
		}
		return false;
	}

private:
	Event &m_event;
};

inline std::ostream &operator<<(std::ostream &os, const Event &event)
{
	return os << event.toString();
}

}
