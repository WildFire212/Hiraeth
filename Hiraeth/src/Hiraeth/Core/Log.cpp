#include"pch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"




std::shared_ptr<spdlog::logger> Hiraeth::Log::m_CoreLogger   ;
std::shared_ptr<spdlog::logger> Hiraeth::Log::m_ClientLogger ;
void Hiraeth::Log::init()
{
	std::vector<spdlog::sink_ptr> logSinks;

	logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

	logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Hiraeth.log", true));



	logSinks[0]->set_pattern("%^[%T] %n: %v%$");

	logSinks[1]->set_pattern("[%T] [%l] %n: %v");



	m_CoreLogger = std::make_shared<spdlog::logger>("HIRAETH", begin(logSinks), end(logSinks));

	spdlog::register_logger(m_CoreLogger);

	m_CoreLogger->set_level(spdlog::level::trace);

	m_CoreLogger->flush_on(spdlog::level::trace);



	m_ClientLogger = std::make_shared<spdlog::logger>("GAME APPLICATION", begin(logSinks), end(logSinks));

	spdlog::register_logger(m_ClientLogger);

	m_ClientLogger->set_level(spdlog::level::trace);

	m_ClientLogger->flush_on(spdlog::level::trace);
}
