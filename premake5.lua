workspace "NexusC"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories to root folder(solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "./NexusC/vendor/GLFW/include"

include "NexusC/vendor/GLFW"

project "NexusC"


	staticruntime "on"
	location "NexusC"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nxpch.h"
	pchsource "NexusC/src/nxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NC_PLATFORM_WINDOWS",
			"NC_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/NexusSandbox")
		}

	filter "configurations:Debug"
		defines "NX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NX_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NX_DIST"
		symbols "On"


project "NexusSandbox"
	staticruntime "on"
	location "NexusSandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"NexusC/vendor/spdlog/include",
		"NexusC/src"
	}

	links
	{
		"NexusC"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NX_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NX_DIST"
		symbols "On"
