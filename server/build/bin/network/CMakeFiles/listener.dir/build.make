# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/itsl/Documents/LightROV/LightROV-1.0-dev/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build

# Include any dependencies generated for this target.
include bin/network/CMakeFiles/listener.dir/depend.make

# Include the progress variables for this target.
include bin/network/CMakeFiles/listener.dir/progress.make

# Include the compile flags for this target's objects.
include bin/network/CMakeFiles/listener.dir/flags.make

bin/network/CMakeFiles/listener.dir/listener.cpp.o: bin/network/CMakeFiles/listener.dir/flags.make
bin/network/CMakeFiles/listener.dir/listener.cpp.o: ../network/listener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/network/CMakeFiles/listener.dir/listener.cpp.o"
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/listener.dir/listener.cpp.o -c /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/network/listener.cpp

bin/network/CMakeFiles/listener.dir/listener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/listener.dir/listener.cpp.i"
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/network/listener.cpp > CMakeFiles/listener.dir/listener.cpp.i

bin/network/CMakeFiles/listener.dir/listener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/listener.dir/listener.cpp.s"
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/network/listener.cpp -o CMakeFiles/listener.dir/listener.cpp.s

bin/network/CMakeFiles/listener.dir/listener.cpp.o.requires:

.PHONY : bin/network/CMakeFiles/listener.dir/listener.cpp.o.requires

bin/network/CMakeFiles/listener.dir/listener.cpp.o.provides: bin/network/CMakeFiles/listener.dir/listener.cpp.o.requires
	$(MAKE) -f bin/network/CMakeFiles/listener.dir/build.make bin/network/CMakeFiles/listener.dir/listener.cpp.o.provides.build
.PHONY : bin/network/CMakeFiles/listener.dir/listener.cpp.o.provides

bin/network/CMakeFiles/listener.dir/listener.cpp.o.provides.build: bin/network/CMakeFiles/listener.dir/listener.cpp.o


# Object files for target listener
listener_OBJECTS = \
"CMakeFiles/listener.dir/listener.cpp.o"

# External object files for target listener
listener_EXTERNAL_OBJECTS =

bin/network/liblistener.a: bin/network/CMakeFiles/listener.dir/listener.cpp.o
bin/network/liblistener.a: bin/network/CMakeFiles/listener.dir/build.make
bin/network/liblistener.a: bin/network/CMakeFiles/listener.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblistener.a"
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && $(CMAKE_COMMAND) -P CMakeFiles/listener.dir/cmake_clean_target.cmake
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/listener.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/network/CMakeFiles/listener.dir/build: bin/network/liblistener.a

.PHONY : bin/network/CMakeFiles/listener.dir/build

bin/network/CMakeFiles/listener.dir/requires: bin/network/CMakeFiles/listener.dir/listener.cpp.o.requires

.PHONY : bin/network/CMakeFiles/listener.dir/requires

bin/network/CMakeFiles/listener.dir/clean:
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network && $(CMAKE_COMMAND) -P CMakeFiles/listener.dir/cmake_clean.cmake
.PHONY : bin/network/CMakeFiles/listener.dir/clean

bin/network/CMakeFiles/listener.dir/depend:
	cd /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/itsl/Documents/LightROV/LightROV-1.0-dev/server /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/network /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network /home/itsl/Documents/LightROV/LightROV-1.0-dev/server/build/bin/network/CMakeFiles/listener.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/network/CMakeFiles/listener.dir/depend
