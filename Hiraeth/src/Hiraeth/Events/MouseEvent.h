#pragma once
#include"Hiraeth/Events/Event.h"	
#include<sstream>
namespace Hiraeth 
{
	class MouseMovedEvent : public Event
	{
	public: 
		MouseMovedEvent(float xPos, float yPos) :
			m_XPos(xPos),
			m_YPos(yPos)
		{}

		inline float getX() const { return m_XPos; }
		inline float getY() const { return m_YPos; }
		
		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		std::string toString() const override
		{
			std::stringstream mouseMStream; 
			mouseMStream << "Mouse Moved Event: XPosition(" << m_XPos << ") " << "YPosition(" << m_YPos << ") "; 
			return mouseMStream.str(); 
		}
	private: 
		float m_XPos, m_YPos; 
	};


}