#include "SapFirePch.h"
#include "Application.h"

#include "SapFire/Events/ApplicationEvent.h"
#include "SapFire/Log.h"

namespace SapFire
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}


	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}