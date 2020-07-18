#pragma once

#include "Core.h"

// temporary, to disable warning C4251
#pragma warning(disable: 4251)

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
