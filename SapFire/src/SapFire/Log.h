#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SapFire
{
	class SAPP_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
// Core Log Macros
#define SAPP_CORE_FATAL(...)	::SapFire::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define SAPP_CORE_ERROR(...)	::SapFire::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAPP_CORE_WARN(...)		::SapFire::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAPP_CORE_INFO(...)		::SapFire::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAPP_CORE_TRACE(...)	::SapFire::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log Macros

#define SAPP_FATAL(...)		::SapFire::Log::GetClientLogger()->critical(__VA_ARGS__)
#define SAPP_ERROR(...)		::SapFire::Log::GetClientLogger()->error(__VA_ARGS__)
#define SAPP_WARN(...)		::SapFire::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAPP_INFO(...)		::SapFire::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAPP_TRACE(...)		::SapFire::Log::GetClientLogger()->trace(__VA_ARGS__)