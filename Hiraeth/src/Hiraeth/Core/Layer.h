#pragma once
#include"Hiraeth/Core/CoreEngine.h"
namespace Hiraeth
{
	class HIRAETH_API Layer
	{
	public: 
		Layer(const std::string& name = "Layer"): m_Name(name) {}
		virtual ~Layer() {}

		virtual void onAttach() {} 
		virtual void onDetach() {}

		virtual void onUpdate() {}
		virtual void onImGuiRender(){}


		inline const std::string& getName() const { return m_Name;  }
	protected: 
		std::string m_Name; 
	};

	
}