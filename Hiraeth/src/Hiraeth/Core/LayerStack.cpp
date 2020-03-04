#include "pch.h"
#include "LayerStack.h"
namespace Hiraeth
{

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->onDetach(); 
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerCount, layer);
		m_LayerCount++; 
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto findIter = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerCount, layer); 
		if (findIter != m_Layers.begin() + m_LayerCount)
		{
			layer->onDetach(); 
			m_Layers.erase(findIter);
			m_LayerCount--; 
		}
	}

	void LayerStack::pushOverLay(Layer* overLay)
	{
		m_Layers.emplace_back(overLay);
	}

	void LayerStack::popOverLay(Layer* overLay)
	{
		auto findIter = std::find(m_Layers.begin() + m_LayerCount,m_Layers.end(), overLay);
		if (findIter != m_Layers.end() )
		{
			overLay->onDetach();
			m_Layers.erase(findIter);
		}
	}

}