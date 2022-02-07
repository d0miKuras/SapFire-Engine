#pragma once

#ifdef SAPP_PLATFORM_WINDOWS

extern SapFire::Application* SapFire::CreateApplication();

int main(int argc, char** argv)
{
	SapFire::Log::Init();

	SAPP_CORE_WARN("Initialized Log!");
	SAPP_INFO("Hello!");

	printf("Hello from the SapFire Engine\n");
	auto app = SapFire::CreateApplication();
	app->Run();
	delete app;
}
#endif