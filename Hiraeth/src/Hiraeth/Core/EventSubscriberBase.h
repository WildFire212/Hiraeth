#pragma once
#include"Hiraeth/Events/Event.h"
namespace Hiraeth 
{
	class EventSubscriberBase 
	{
	public: 
		void execute(Event* event) { call(event); }
	private: 
		virtual void call(Event* event) = 0; 
	};
}