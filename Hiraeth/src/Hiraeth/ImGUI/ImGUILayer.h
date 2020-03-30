#pragma once
#include"Hiraeth/Core/Layer.h"
#include"Hiraeth/Events/KeyEvent.h"
#include"Hiraeth/Events/MouseEvent.h"
#include"Hiraeth/Events/ApplicationEvent.h"
namespace Hiraeth
{
	class HIRAETH_API ImGUILayer : public Layer
	{
	public: 
		ImGUILayer();
		~ImGUILayer() = default;

		void onAttach() override; 
		void onDetach() override; 

		void begin(); 
		void end(); 
	private: 
	
	};
}