#pragma once

#ifdef SAPP_PLATFORM_WINDOWS

extern SapFire::Application* SapFire::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hello from the SapFire Engine\n");
	auto app = SapFire::CreateApplication();
	app->Run();
	delete app;
}
#endif