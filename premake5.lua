workspace "SapFire"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SapFire"
    location "SapFire"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            
            "SAPP_PLATFORM_WINDOWS",
            "SAPP_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "SAPP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SAPP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SAPP_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "SapFire/vendor/spdlog/include",
        "SapFire/src"
    }

    links
    {
        "SapFire"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            
            "SAPP_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "SAPP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SAPP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SAPP_DIST"
        optimize "On"