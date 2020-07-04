#pragma once

#ifdef HZ_PLATFORM_WINDOWS

int main(int argc, char *argv[])
{
	Hazel::Log::init();
	HZ_CORE_WARN("Initialized log");

	const auto app = Hazel::createApplication();
	app->run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
