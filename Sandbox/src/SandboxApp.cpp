#include "SapFire.h"


class Sandbox : public SapFire::Application
{
	public:
		Sandbox()
		{

		}

		~Sandbox()
		{

		}
};

SapFire::Application* SapFire::CreateApplication()
{
	return new Sandbox();
}