#pragma once
#include<map>
#include<queue>
#include"Hiraeth/Core/EventSubscriberHandler.h"
#include<vector>
#include"Hiraeth/Core/CoreEngine.h"
#include"Hiraeth/Core/Log.h"
namespace Hiraeth
{	
	typedef std::vector<EventSubscriberBase*> HandlerList;

	class EventQueue
	{
	public:
		template<class EventClassType> 
		void publish(Hiraeth::Event* event)
		{
			
			HI_CORE_ASSERT(EventClassType::getStaticType() == event->getEventType(), 
							"template argument EventType does not match argument EventType");
			
			/*if (event->getCategoryFlags() != )
			{
			uint16_t category =
			}*/
			
			auto find = m_EventQueues.find(event->getEventType());
			
			//first time initialization of queue
			if (find == m_EventQueues.end())
			{
				m_EventQueues[event->getEventType()] = std::queue<Event*>(); 
				find = m_EventQueues.find(event->getEventType());
			}

			find->second.push(event);
			HIRAETH_CORE_INFO("Event pushed: EventType::{0}", event->getName());
		}

		void relayEvents();

		template<class T , class EventClassType>
		void subscribe(T* instance, void (T::* memberFunction)(EventClassType*))
		{
			HandlerList* handlers = m_Subscribers[EventClassType::getStaticType()];
			
			if (handlers == nullptr)
			{
				handlers = new HandlerList(); 
				m_Subscribers[EventClassType::getStaticType()] = handlers; 
			}
			
			handlers->push_back(new EventSubscriberHandler<T, EventClassType>(instance, memberFunction));
		}

		static EventQueue* getInstance();

	private:
		EventQueue();
		~EventQueue();

		std::map<Hiraeth::EventType, std::queue<Event*>> m_EventQueues;
		std::map<Hiraeth::EventType, HandlerList*> m_Subscribers; 
	};
}