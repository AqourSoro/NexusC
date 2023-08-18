#include "nxpch.h"
#include <NexusC.h>


class SandBox : public nexus_c::Application
{

public:
	SandBox()
	{

	}

	~SandBox()
	{

	}

};



nexus_c::Application* nexus_c::CreateApplication()
{
	return new SandBox();
}