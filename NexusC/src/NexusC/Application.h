#pragma once

#include "Core.h"

namespace NexusC
{
	class NEXUSC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	};

	//To be defined in CLIENT
	Application* CreateApplication();

}



