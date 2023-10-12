#!/usr/bin/env python
import os
import sys
import shutil

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

def getSubdirs(path) :  
    lst = [ os.path.join(path, name) 
        for name in os.listdir(path) 
            if os.path.isdir(os.path.join(path, name)) and 
                name != ".idea" and 
                name != "x64" and 
                name != ".vs" and 
                name != ".temp" ]
    return lst

def getDirsRec(path) :
    lst = getSubdirs(path)
    for subdir in lst :
        lst += getDirsRec(subdir)
    return lst

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

subdirs = getDirsRec('src')
for subdir in subdirs :
    sources += Glob(subdir + "/*.cpp")
    sources += Glob(subdir + "/*.c")
    env.Append(CPPPATH=[subdir + "/"])

# Add project includes
env.Append(INCLUDE="source")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/addons/godotgif/bin/godotgif.{}.{}.framework/godotgif.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demo/addons/godotgif/bin/godotgif{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)