#include "nxpch.h"
#include "WindowsInput.h"

#include "NexusC/Application.h"
#include <GLFW/glfw3.h>



namespace nexus_c
{
	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;

	}

}
