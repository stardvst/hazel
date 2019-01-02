#include "hzpch.h"

#include "Layer.h"

namespace Hazel
{

Layer::Layer(std::string sName /* = "Layer" */)
	: m_sDebugName(std::move(sName))
{
}

}
