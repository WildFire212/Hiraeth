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
	private: 
		unsigned int m_Width, m_Height;

	};
}