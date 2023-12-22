#include "nxpch.h"
#include "Application.h"

#include "Log.h"
#include  "Events/ApplicationEvent.h"

namespace nexus_c
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		// Debug purpose
		NX_CORE_INFO("{0}",e);
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

