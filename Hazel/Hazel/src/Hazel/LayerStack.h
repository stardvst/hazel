#pragma once

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel
{

class HAZEL_API LayerStack final
{
public:
	using layerCollection = std::vector<Layer *>;
	using layerCollectionIterator = layerCollection::iterator;

	LayerStack();
	~LayerStack();

	void pushLayer(Layer *pLayer);
	void pushOverlay(Layer *pOverlay);
	void popLayer(Layer *pLayer);
	void popOverlay(Layer *pOverlay);

	// for layer stack to be iterated over
	layerCollectionIterator begin()
	{
		return m_layers.begin();
	}

	layerCollectionIterator end()
	{
		return m_layers.end();
	}

private:
	layerCollection m_layers;
	layerCollectionIterator m_layerInsertIt;
};

}
