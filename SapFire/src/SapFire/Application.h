#pragma once
#include "Core.h"

namespace SapFire
{
	class SAPP_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in client.
	Application* CreateApplication();
}


