#pragma once
#include"spdlog/spdlog.h"
#include<spdlog/fmt/ostr.h>
#include"pch.h"
#include"CoreEngine.h"
namespace Hiraeth {

		class HIRAETH_API Log
		{
		public:
			static void init(); 

			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return m_CoreLogger;  }
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return m_ClientLogger;  }

		private: 
			//core and client loggers 
			static std::shared_ptr<spdlog::logger> m_CoreLogger; 
			static std::shared_ptr<spdlog::logger> m_ClientLogger; 


			Log(); 
			~Log(){}
		};

	
}

//Core Log Macros
#define HIRAETH_CORE_TRACE(...)	 ::Hiraeth::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HIRAETH_CORE_INFO(...)	 ::Hiraeth::Log::getCoreLogger()->info(__VA_ARGS__)
#define HIRAETH_CORE_WARN(...)	 ::Hiraeth::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HIRAETH_CORE_ERROR(...)	 ::Hiraeth::Log::getCoreLogger()->error(__VA_ARGS__)
#define HIRAETH_CORE_CRITICAL(...)	 ::Hiraeth::Log::getCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define HIRAETH_CLIENT_TRACE(...)	 ::Hiraeth::Log::getClientLogger()->trace(__VA_ARGS__)
#define HIRAETH_CLIENT_INFO(...)	 ::Hiraeth::Log::getClientLogger()->info(__VA_ARGS__)
#define HIRAETH_CLIENT_WARN(...)	 ::Hiraeth::Log::getClientLogger()->warn(__VA_ARGS__)
#define HIRAETH_CLIENT_ERROR(...)	 ::Hiraeth::Log::getClientLogger()->error(__VA_ARGS__)
#define HIRAETH_CLIENT_CRITICAL(...)	::Hiraeth::Log::getClientLogger()->critical(__VA_ARGS__)
