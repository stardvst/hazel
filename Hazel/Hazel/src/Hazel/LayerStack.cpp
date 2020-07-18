#include "hzpch.h"

#include "LayerStack.h"

namespace Hazel
{

LayerStack::~LayerStack()
{
	for (auto pLayer : m_layers)
		delete pLayer;
}

void LayerStack::pushLayer(Layer *pLayer)
{
	m_layers.emplace(m_layers.begin() + m_layerInsertIdx, pLayer);
	++m_layerInsertIdx;
}

void LayerStack::pushOverlay(Layer *pOverlay)
{
	m_layers.emplace_back(pOverlay);
}

void LayerStack::popLayer(Layer *pLayer)
{
	const auto layerIt = std::find(m_layers.cbegin(), m_layers.cend(), pLayer);
	if (layerIt != m_layers.cend())
	{
		m_layers.erase(layerIt);
		--m_layerInsertIdx;
	}
}

void LayerStack::popOverlay(Layer *pOverlay)
{
	const auto overlayIt = std::find(m_layers.cbegin(), m_layers.cend(), pOverlay);
	if (overlayIt != m_layers.cend())
		m_layers.erase(overlayIt);
}

LayerStack::layerCollectionIterator LayerStack::begin()
{
	return m_layers.begin();
}

LayerStack::layerCollectionIterator LayerStack::end()
{
	return m_layers.end();
}

}
