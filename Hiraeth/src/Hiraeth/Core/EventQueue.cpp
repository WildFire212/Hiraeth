#include"pch.h"
#include "EventQueue.h"
namespace Hiraeth
{
	void EventQueue::relayEvents()
	{
		std::map<Hiraeth::EventType, std::queue<Event*>>::iterator i; 
		for ( i = m_EventQueues.begin
			(); i != m_EventQueues.end(); ++i)
		{
			Event* evnt;
			if (!i->second.empty())
			{
				evnt = i->second.front();
				HandlerList* handlers = m_Subscribers[i->first];
				if (handlers != nullptr)
				{
					for (EventSubscriberBase* eventBase : *handlers)
					{
						eventBase->execute(evnt);
					}
				}
			}
			if(!i->second.empty())
			i->second.pop();
		}

		
	}

	EventQueue* EventQueue::getInstance()
	{
		static EventQueue* instance = new EventQueue();
		return instance;
	}


	EventQueue::EventQueue()
	{
		
	}

	EventQueue::~EventQueue()
	{
	}

}
