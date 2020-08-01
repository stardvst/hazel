#pragma once

#include "Core.h"

namespace Hazel
{

class Event;

class HAZEL_API Layer
{
public:
	explicit Layer(std::string sName = "Layer");
	virtual ~Layer() = default;

	virtual void onAttach();
	virtual void onDetach();

	virtual void onUpdate();
	virtual void onEvent(Event &event);

	virtual void onImGuiRender();

	const std::string &getName() const;

protected:
	std::string m_sDebugName;
};

}
