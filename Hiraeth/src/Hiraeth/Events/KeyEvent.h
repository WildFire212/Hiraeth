#pragma once
#include"Hiraeth/Events/Event.h"
#include<sstream>
namespace Hiraeth 
{
	class KeyEvent : public Event
	{
	public:
		inline uint16_t getKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY( EventCategoryKeyboard); 
	protected: 
		 KeyEvent(uint16_t keyCode): m_KeyCode(keyCode){ }
		uint16_t m_KeyCode;  

	};


	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(uint16_t keycode, int repeatCount) :
			KeyEvent(keycode), m_RepeatCount(repeatCount) {}
			inline int getRepeatCount() const { return m_RepeatCount; }
		EVENT_CLASS_TYPE(KeyPressed);

		std::string toString() const override 
		{
			std::stringstream keyPressedStream; 
			keyPressedStream << "KeyPressed Event: " << m_KeyCode << " (" << m_RepeatCount << ") repeats"; 
			return keyPressedStream.str(); 
		}

	private: 
		int m_RepeatCount; 
	};

	class KeyReleasedEvent : public KeyEvent {
	public: 
		KeyReleasedEvent(uint16_t keyCode): 
			KeyEvent(keyCode)
		{}
		EVENT_CLASS_TYPE(KeyReleased);

		std::string toString() const override
		{
			std::stringstream keyReleasedStream; 
			keyReleasedStream << "EVENT::KEYRELEASED: " << m_KeyCode; 
			return keyReleasedStream.str();
		}

	};
			
	class KeyTypedEvent: public KeyEvent {
	public:
		KeyTypedEvent(uint16_t keyCode) :
			KeyEvent(keyCode)
		{}
		EVENT_CLASS_TYPE(KeyTyped);

		std::string toString() const override
		{
			std::stringstream keyTypedStream;
			keyTypedStream << "EVENT::KEYTYPED: " << m_KeyCode;
			return keyTypedStream.str();
		}

	};
}