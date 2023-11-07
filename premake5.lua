workspace "SI-PRJ"
   configurations { "Debug", "Release" }

project "SI-PRJ"
   kind "ConsoleApp"
   language "C"
   cdialect "C17" -- You can specify the desired C standard version here (e.g., "C11" or "C17")
   targetdir "bin/%{cfg.buildcfg}"

   includedirs { 
      "Include/",
      "Include/DataStructure/",
      "C:/PostgreSQL/16/include/"
   }

   libdirs { "C:/PostgreSQL/16/lib/" } -- Specify the library directory
   links { "libpq" } -- Corrected the library name to "libpq"

   architecture "x86_64" -- Set the target architecture to 64-bit

   files { "src/main.c", 
      "src/**.h",
           "src/**.c" ,
           "Include/DataStructure/**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
