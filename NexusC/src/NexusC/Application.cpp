#include "nxpch.h"
#include "Application.h"

#include "Log.h"

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

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowsClose));

	}


	void Application::run()
	{

		while (m_Running)
		{
			m_Window->OnUpdate();
		}

	}

	bool Application::OnWindowsClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

