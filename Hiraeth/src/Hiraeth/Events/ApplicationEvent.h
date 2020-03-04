#pragma once
#include"Hiraeth/Events/Event.h"

namespace Hiraeth 
{

	class WindowCloseEvent : public Event
	{
	public: 
		WindowCloseEvent() = default; 
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class WindowResizeEvent : public Event
	{
	public: 
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_Width(width),
			m_Height(height){}

		std::string toString() const override
		{
			std::stringstream windowResizeStream;
			windowResizeStream << "Window Resize Event: width(" << m_Width << ") height(" << m_Height<<")";
			return windowResizeStream.str();
		}

		inline unsigned int getWidth() const { return m_Width; }
		inline unsigned int getHeight() const { return m_Height; }
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication); 


	private: 
		unsigned int m_Width, m_Height;
	};
}