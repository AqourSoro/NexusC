#pragma once

#include "NexusC\Layer.h"

namespace nexus_c
{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event) {}

	private:

	};


}