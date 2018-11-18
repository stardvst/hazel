#pragma once

#ifdef HZ_PLATFORM_WINDOWS

inline int main(int argc, char *argv[])
{
	Hazel::Log::init();
	HZ_CORE_WARN("Initialized log");
	HZ_INFO("Hello! Var={0}", 5);

	const auto app = Hazel::createApplication();
	Hazel::Application::run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
