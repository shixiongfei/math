solution ( "math-test" )
  configurations { "Release", "Debug" }
  platforms { "x64" }

  if _ACTION == "clean" then
    os.rmdir(".vs")
    os.rmdir("test")
    os.remove("math-test.VC.db")
    os.remove("math-test.sln")
    os.remove("math-test.vcxproj")
    os.remove("math-test.vcxproj.filters")
    os.remove("math-test.vcxproj.user")
    os.remove("math-test.make")
    os.remove("Makefile")
    return
  end

  -- A project defines one build target
  project ( "math-test" )
  kind ( "ConsoleApp" )
  language ( "C" )
  targetname ("math-test")
  files { "./*.h", "./*.c" }
  defines { "_UNICODE" }
  flags { "StaticRuntime" }

  configuration ( "Release" )
    optimize "On"
    objdir ( "./test/tmp" )
    targetdir ( "./test" )
    defines { "NDEBUG", "_NDEBUG" }

  configuration ( "Debug" )
    symbols "On"
    objdir ( "./test/tmp" )
    targetdir ( "./test" )
    defines { "DEBUG", "_DEBUG" }

  configuration ( "vs*" )
    defines { "WIN32", "_WIN32", "_WINDOWS",
              "_CRT_SECURE_NO_WARNINGS", "_CRT_SECURE_NO_DEPRECATE",
              "_CRT_NONSTDC_NO_DEPRECATE", "_WINSOCK_DEPRECATED_NO_WARNINGS" }

  configuration ( "gmake" )
    warnings  "Default" --"Extra"
    defines { "LINUX_OR_MACOSX" }

  configuration { "gmake", "macosx" }
    defines { "__APPLE__", "__MACH__", "__MRC__", "macintosh" }

  configuration { "gmake", "linux" }
    defines { "__linux__" }
