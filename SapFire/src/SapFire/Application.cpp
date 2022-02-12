#include "SapFirePch.h"
#include "Application.h"


#include "SapFire/Log.h"

namespace SapFire
{
#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));
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
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));
		
		SAPP_CORE_TRACE("{0}", e);
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}