#pragma once

#include <NexusC.h>

class ExampleLayer : public nexus_c::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	// virtual void OnAttach() override;
	// virtual void OnDetach() override;

	void OnUpdate() override;
	void OnEvent(nexus_c::Event& event) override;

	
};