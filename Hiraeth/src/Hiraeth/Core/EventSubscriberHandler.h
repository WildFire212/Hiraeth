#pragma once
#include"Hiraeth/Core/EventSubscriberBase.h"
namespace Hiraeth
{
	template<class T , class EventClassType> 
	class EventSubscriberHandler : public EventSubscriberBase
	{
		public : 
			typedef void ( T::*MemberFunction)(EventClassType*);

			void call(Event* event) override
			{
				(m_Instance->*m_MemberFunction)(static_cast<EventClassType*>(event)); 
			}
			

			EventSubscriberHandler(T* instance, MemberFunction memberFunction) :
				m_Instance(instance),
				m_MemberFunction(memberFunction)
				{}
			
		private: 
			T* m_Instance; 
			MemberFunction m_MemberFunction; 
	};

}