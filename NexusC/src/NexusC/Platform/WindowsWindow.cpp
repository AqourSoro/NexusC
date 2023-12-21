#include "nxpch.h"

#include "NexusC/Platform/WindowsWindow.h"

#include "NexusC/Log.h"

namespace nexus_c
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		NX_CORE_INFO("Creating window {0} {1}, {2}", props.Title, props.Width, props.Height);

		if(!s_GLFWInitialized)
		{
			// TODO: glfwterminate on system shutdown
			int success = glfwInit();

			NX_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}



}
