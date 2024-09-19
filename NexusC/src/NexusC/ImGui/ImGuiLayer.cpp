#include "nxpch.h"
#include "ImGuiLayer.h"

#include "NexusC\Platform\OpenGL\ImGuiOpenGLRenderer.h"
#include "GLFW\glfw3.h"

namespace nexus_c
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;


	}

	void ImGuiLayer::OnDetach()
	{
		
	}
	
	void ImGuiLayer::OnUpdate()
	{

	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}

	
	
}