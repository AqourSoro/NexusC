#pragma once

#ifdef NC_PLATFORM_WINDOWS

extern NexusC::Application* NexusC::CreateApplication();

int main(int argc, char** argv)
{
	printf("NexusC Engine starts running!\n");

	NexusC::Log::Init();
	NX_CORE_WARN("Hikari wa kizuna da!");
	NX_CORE_WARN("Initialized Log!");
	int a = 5;
	NX_INFO("Hello! The logger system is working! Var = {0}", a);

	auto app = NexusC::CreateApplication();
	app->run();
	delete app;

}

#endif // NC_PLATFORM_WINDOWS

