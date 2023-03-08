#pragma once

#ifdef NC_PLATFORM_WINDOWS

extern NexusC::Application* NexusC::CreateApplication();

int main(int argc, char** argv)
{
	printf("NexusC Engine starts running!");

	auto app = NexusC::CreateApplication();
	app->run();
	delete app;

}

#endif // NC_PLATFORM_WINDOWS

