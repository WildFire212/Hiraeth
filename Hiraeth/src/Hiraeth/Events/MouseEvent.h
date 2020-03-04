#pragma once
#include"Hiraeth/Events/Event.h"	

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

	class MouseButtonEvent : public Event
	{
	public:
		inline unsigned int getMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(unsigned int button)
			: m_Button(button) {}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		unsigned int m_Button;
	};
		

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public: 
		MouseButtonPressedEvent(unsigned int button) : MouseButtonEvent(button)
		{}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public: 
		MouseButtonReleasedEvent(unsigned int button) : MouseButtonEvent(button)
		{}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}