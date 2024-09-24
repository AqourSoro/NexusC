#include "nxpch.h"
#include <NexusC.h>
#include <NexusC/EntryPoint.h>

#include "ExampleLayer.h"

class SandBox : public nexus_c::Application
{

public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new nexus_c::ImGuiLayer());
	}

	~SandBox()
	{

	}

};



nexus_c::Application* nexus_c::CreateApplication()
{
	return new SandBox();
}