workspace "Hiraeth"
	architecture "x64"	
	startproject "Game"

	configurations 
	{
		"Debug", 
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"	
	}	

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	 
	--Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Hiraeth/submodules/GLFW/include/GLFW"
	
	group "Dependencies"
		include "Hiraeth/submodules/GLFW"
	
	group ""
	
	--project Hiraeth 
	project "Hiraeth"
		location "Hiraeth"
		kind "SharedLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "On"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/submodules/spdlog/include",
			"%{prj.name}/submodules/GLFW/include"
		}
	
		links{ 
			"GLFW",
			"opengl32.lib"
		}

		filter "system:windows"
				systemversion "latest"
		defines
		{
		"HI_WINDOWS_PLATFORM",
		"HIBUILD_DLL_"
		}
		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}
		
		filter "configurations:Debug"

		defines "HI_DEBUG"

		runtime "Debug"

		symbols "on"



	filter "configurations:Release"

		defines "HI_RELEASE"

		runtime "Release"

		optimize "on"



	filter "configurations:Dist"

		defines "HI_DIST"

		runtime "Release"

		optimize "on"


project "Game"
			location "Game"
			kind "ConsoleApp"
			language "C++"	
			cppdialect "C++17"
			staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		includedirs
		{
			"Hiraeth/src",
			"Hiraeth/submodules/spdlog/include"
		}
		files
		{
			"%{prj.name}/**.h",
			"%{prj.name}/**.cpp"
		}



	links
	{
		"Hiraeth"
	}
	
	



	filter "system:windows"
		systemversion "latest"
		defines "HI_WINDOWS_PLATFORM"


	filter "configurations:Debug"
		defines "HI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HI_RELEASE"
		runtime "Release"
		optimize "on"


	filter "configurations:Dist"
		defines "HI_DIST"
		runtime "Release"
		optimize "on"



