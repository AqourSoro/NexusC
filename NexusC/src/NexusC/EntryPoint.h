#pragma once

#ifdef NC_PLATFORM_WINDOWS

extern nexus_c::Application* nexus_c::CreateApplication();

int main(int argc, char** argv)
{
	printf("NexusC Engine starts running!\n");

	nexus_c::Log::Init();
	NX_CORE_WARN("Hikari wa kizuna da!");
	NX_CORE_WARN("Initialized Log!");
	int a = 5;
	NX_INFO("Hello! The logger system is working! Var = {0}", a);

	auto app = nexus_c::CreateApplication();
	app->run();
	delete app;

}

#endif // NC_PLATFORM_WINDOWS

