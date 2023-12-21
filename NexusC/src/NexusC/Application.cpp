#include "nxpch.h"
#include "Application.h"

#include "Log.h"
#include  "Events/ApplicationEvent.h"

namespace nexus_c
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::run()
	{

		/*

		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NX_TRACE(e);
		}
		if(e.IsInCategory(EventCategoryInput))
		{
			NX_TRACE(e);
		}
		
		while (true);

		*/

		while (m_Running)
		{
			m_Window->OnUpdate();
		}


		
	}

}

