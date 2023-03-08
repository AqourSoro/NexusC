#include <NexusC.h>


class SandBox : public NexusC::Application
{

public:
	SandBox()
	{

	}

	~SandBox()
	{

	}

};



NexusC::Application* NexusC::CreateApplication()
{
	return new SandBox();
}