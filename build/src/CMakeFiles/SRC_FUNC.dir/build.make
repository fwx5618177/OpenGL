# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dz0401006/Desktop/opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dz0401006/Desktop/opengl/build

# Include any dependencies generated for this target.
include src/CMakeFiles/SRC_FUNC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/SRC_FUNC.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SRC_FUNC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SRC_FUNC.dir/flags.make

src/CMakeFiles/SRC_FUNC.dir/window.cc.o: src/CMakeFiles/SRC_FUNC.dir/flags.make
src/CMakeFiles/SRC_FUNC.dir/window.cc.o: ../src/window.cc
src/CMakeFiles/SRC_FUNC.dir/window.cc.o: src/CMakeFiles/SRC_FUNC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dz0401006/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/SRC_FUNC.dir/window.cc.o"
	cd /Users/dz0401006/Desktop/opengl/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SRC_FUNC.dir/window.cc.o -MF CMakeFiles/SRC_FUNC.dir/window.cc.o.d -o CMakeFiles/SRC_FUNC.dir/window.cc.o -c /Users/dz0401006/Desktop/opengl/src/window.cc

src/CMakeFiles/SRC_FUNC.dir/window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRC_FUNC.dir/window.cc.i"
	cd /Users/dz0401006/Desktop/opengl/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dz0401006/Desktop/opengl/src/window.cc > CMakeFiles/SRC_FUNC.dir/window.cc.i

src/CMakeFiles/SRC_FUNC.dir/window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRC_FUNC.dir/window.cc.s"
	cd /Users/dz0401006/Desktop/opengl/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dz0401006/Desktop/opengl/src/window.cc -o CMakeFiles/SRC_FUNC.dir/window.cc.s

# Object files for target SRC_FUNC
SRC_FUNC_OBJECTS = \
"CMakeFiles/SRC_FUNC.dir/window.cc.o"

# External object files for target SRC_FUNC
SRC_FUNC_EXTERNAL_OBJECTS =

src/libSRC_FUNC.a: src/CMakeFiles/SRC_FUNC.dir/window.cc.o
src/libSRC_FUNC.a: src/CMakeFiles/SRC_FUNC.dir/build.make
src/libSRC_FUNC.a: src/CMakeFiles/SRC_FUNC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dz0401006/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSRC_FUNC.a"
	cd /Users/dz0401006/Desktop/opengl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SRC_FUNC.dir/cmake_clean_target.cmake
	cd /Users/dz0401006/Desktop/opengl/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SRC_FUNC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SRC_FUNC.dir/build: src/libSRC_FUNC.a
.PHONY : src/CMakeFiles/SRC_FUNC.dir/build

src/CMakeFiles/SRC_FUNC.dir/clean:
	cd /Users/dz0401006/Desktop/opengl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SRC_FUNC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SRC_FUNC.dir/clean

src/CMakeFiles/SRC_FUNC.dir/depend:
	cd /Users/dz0401006/Desktop/opengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dz0401006/Desktop/opengl /Users/dz0401006/Desktop/opengl/src /Users/dz0401006/Desktop/opengl/build /Users/dz0401006/Desktop/opengl/build/src /Users/dz0401006/Desktop/opengl/build/src/CMakeFiles/SRC_FUNC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/SRC_FUNC.dir/depend
