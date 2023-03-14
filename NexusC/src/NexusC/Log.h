#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>


namespace NexusC
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
#define NX_CORE_TRACE(...)    ::NexusC::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NX_CORE_INFO(...)     ::NexusC::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NX_CORE_WARN(...)     ::NexusC::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NX_CORE_ERROR(...)    ::NexusC::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NX_CORE_CRITICAL(...) ::NexusC::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NX_TRACE(...)         ::NexusC::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NX_INFO(...)          ::NexusC::Log::GetClientLogger()->info(__VA_ARGS__)
#define NX_WARN(...)          ::NexusC::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NX_ERROR(...)         ::NexusC::Log::GetClientLogger()->error(__VA_ARGS__)
#define NX_CRITICAL(...)      ::NexusC::Log::GetClientLogger()->critical(__VA_ARGS__)
