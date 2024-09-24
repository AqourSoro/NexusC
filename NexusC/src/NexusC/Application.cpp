#include "nxpch.h"
#include "Application.h"

#include "Log.h"
#include <glad/glad.h>

namespace nexus_c
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{

		NX_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		unsigned int id;
		glGenVertexArrays(1, &id);
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

		for (auto it = m_LayerSatck.rbegin(); it != m_LayerSatck.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerSatck.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerSatck.PushOverlay(overlay);
		overlay->OnAttach();
	}


	void Application::run()
	{

		while (m_Running)
		{
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerSatck)
				layer->OnUpdate();

		}

	}

	bool Application::OnWindowsClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

