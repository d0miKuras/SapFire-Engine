#include "Application.h"

#include "SapFire/Events/ApplicationEvent.h"
#include "SapFire/Log.h"

namespace SapFire
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}


	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		SAPP_TRACE(e);
		while(true);
	}
}