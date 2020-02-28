#pragma once
#include"Hiraeth/Core/CoreEngine.h"
#include"pch.h"
namespace Hiraeth {

	enum class EventType 
	{
		WindowResize, WindowClose , 
		KeyPressed , KeyReleased , KeyTyped,
		MouseMoved,MouseButtonPressed, MouseButtonReleased, MouseScrolled
	};

	
	enum  EventCategory
	{
		None = 0,
		EventCategoryInput = BIT(0),
		EventCategoryApplication = BIT(1), 
		EventCategoryKeyboard= BIT(2), 
		EventCategoryMouse= BIT(3),
		EventCategoryMouseButton= BIT(4), 
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
	virtual EventType getEventType() const override { return getStaticType(); }\
		virtual const char* getName() const override { return #type; }


		
#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }


	class Event {
	public : 
		Event() {}
		virtual ~Event(){} ;
		
		virtual EventType getEventType() const = 0; 
		virtual const char* getName() const = 0; 
		virtual int getCategoryFlags() const = 0; 
		virtual std::string toString() const { return getName();  }
		
		inline bool isInCategory(EventCategory category)
		{		//and operator to check category 
			return getCategoryFlags() & category; 
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString(); 
	}
}	