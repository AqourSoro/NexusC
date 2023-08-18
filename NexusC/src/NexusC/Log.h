#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

//#include <memory>


namespace nexus_c
{
	class NEXUSC_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define NX_CORE_TRACE(...)    ::nexus_c::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NX_CORE_INFO(...)     ::nexus_c::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NX_CORE_WARN(...)     ::nexus_c::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NX_CORE_ERROR(...)    ::nexus_c::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NX_CORE_CRITICAL(...) ::nexus_c::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NX_TRACE(...)         ::nexus_c::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NX_INFO(...)          ::nexus_c::Log::GetClientLogger()->info(__VA_ARGS__)
#define NX_WARN(...)          ::nexus_c::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NX_ERROR(...)         ::nexus_c::Log::GetClientLogger()->error(__VA_ARGS__)
#define NX_CRITICAL(...)      ::nexus_c::Log::GetClientLogger()->critical(__VA_ARGS__)
