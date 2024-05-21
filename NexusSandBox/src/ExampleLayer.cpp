#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
	:Layer("ExampleLayer")
{
	
}

void ExampleLayer::OnUpdate()
{
	//NX_INFO("ExampleLayer::Update");

}

void ExampleLayer::OnAttach()
{
	
}

void ExampleLayer::OnDetach()
{
	
}


void ExampleLayer::OnEvent(nexus_c::Event& event)
{
	NX_TRACE("{0}", event);

}

