#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel
{

// temporary, to disable warning C4251
template class HAZEL_API std::shared_ptr<spdlog::logger>;

class HAZEL_API Log
{
public:
	static void init();

	static std::shared_ptr<spdlog::logger> &getCoreLogger()
	{
		return s_CoreLogger;
	}
	
	static std::shared_ptr<spdlog::logger> &getClientLogger()
	{
		return s_ClientLogger;
	}

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

}

// Core log macros
#define HZ_CORE_TRACE(...)	::Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	::Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)	::Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)	::Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)	::Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)	::Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)