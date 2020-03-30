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
	IncludeDirArray = {}
	IncludeDirArray["GLFW"] = "Hiraeth/submodules/GLFW/include"
	IncludeDirArray["GLAD"] = "Hiraeth/submodules/GLAD/include"
	IncludeDirArray["ImGUI"] = "Hiraeth/submodules/ImGUI"
	IncludeDirArray["GLM"] =  "Hiraeth/submodules/GLM"

	group "Dependencies"
		include "Hiraeth/submodules/GLFW"
		include "Hiraeth/submodules/GLAD"
		include "Hiraeth/submodules/ImGUI"
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

		pchheader "pch.h"
		pchsource "Hiraeth/src/pch.cpp"

		files
		{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/submodules/spdlog/include",
			"%{IncludeDirArray.GLAD}",
			"%{IncludeDirArray.GLFW}",
			"%{IncludeDirArray.ImGUI}",
			"%{IncludeDirArray.GLM}",
			
		}
	
		links{ 
			"GLFW",
			"GLAD",
			"ImGUI",
			"opengl32.lib"
		}

		filter "system:windows"
				systemversion "latest"
		defines
		{
		"HI_WINDOWS_PLATFORM",
		"HIBUILD_DLL_",
		"GLFW_INCLUDE_NONE"
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
			"Hiraeth/submodules/spdlog/include",
			"Hiraeth/submodules/GLM"
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



