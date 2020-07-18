#include "hzpch.h"

#include "Layer.h"

namespace Hazel
{

Layer::Layer(std::string sName /* = "Layer" */)
	: m_sDebugName(std::move(sName))
{
}

void Layer::onAttach()
{
}

void Layer::onDetach()
{
}

void Layer::onUpdate()
{
}

void Layer::onEvent(Event &event)
{
}

void Layer::onImGuiRender()
{
}

const std::string &Layer::getName() const
{
	return m_sDebugName;
}

}
