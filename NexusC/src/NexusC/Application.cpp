#include "nxpch.h"
#include "Application.h"

#include "Log.h"
#include  "Events/ApplicationEvent.h"

namespace nexus_c
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{

		WindowResizeEvent e(1920, 1080);
		NX_CORE_TRACE(e);

		while (true);
	}

}

