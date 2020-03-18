#pragma once
#include"CoreEngine.h"
namespace Hiraeth
{
	class HIRAETH_API Input
	{
	protected : 
		Input() = default;
	public: 
		Input(const Input& input) = delete;	//delete copy constructor
		Input& operator=(const Input& input) = delete; //delete copy assignment operator 
		
		//all those bool 
		inline static bool isKeyPressed(int key) { return m_Instance->isKeyPressedPlatSpecImpl(key);  }
		inline static bool isMouseButtonPressed(int mouseButton) {return m_Instance->isMouseButtonPressed(mouseButton); }
		inline static std::pair<float, float> getMousePosition() { return m_Instance->getMousePositionPlatSpecImpl(); }
		inline static float getMouseX() { return m_Instance->getMouseXPlatSpecImpl();  }
		inline static float getMouseY() { return m_Instance->getMouseYPlatSpecImpl();  }

		//init the Input class 
		static Input* create(); 
	protected: 
		virtual bool isKeyPressedPlatSpecImpl(int key) =0;
		virtual bool isMouseButtonPressedPlatSpecImpl(int mouseButton) =0 ; 
		virtual std::pair<float, float> getMousePositionPlatSpecImpl() =0; 
		virtual float getMouseXPlatSpecImpl() =0; 
		virtual float getMouseYPlatSpecImpl() =0;
		
	private: 
		static Input* m_Instance; //pointer cause we are not defining it in the constructor 
	};
}