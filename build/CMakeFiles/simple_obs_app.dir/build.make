# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /vol/obs-automate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vol/obs-automate/build

# Include any dependencies generated for this target.
include CMakeFiles/simple_obs_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_obs_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_obs_app.dir/flags.make

CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o: CMakeFiles/simple_obs_app.dir/flags.make
CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o: ../examples/simple_obs_app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vol/obs-automate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o -c /vol/obs-automate/examples/simple_obs_app.cpp

CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vol/obs-automate/examples/simple_obs_app.cpp > CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.i

CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vol/obs-automate/examples/simple_obs_app.cpp -o CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.s

# Object files for target simple_obs_app
simple_obs_app_OBJECTS = \
"CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o"

# External object files for target simple_obs_app
simple_obs_app_EXTERNAL_OBJECTS =

simple_obs_app: CMakeFiles/simple_obs_app.dir/examples/simple_obs_app.cpp.o
simple_obs_app: CMakeFiles/simple_obs_app.dir/build.make
simple_obs_app: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
simple_obs_app: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
simple_obs_app: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
simple_obs_app: CMakeFiles/simple_obs_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vol/obs-automate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple_obs_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_obs_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_obs_app.dir/build: simple_obs_app

.PHONY : CMakeFiles/simple_obs_app.dir/build

CMakeFiles/simple_obs_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_obs_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_obs_app.dir/clean

CMakeFiles/simple_obs_app.dir/depend:
	cd /vol/obs-automate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vol/obs-automate /vol/obs-automate /vol/obs-automate/build /vol/obs-automate/build /vol/obs-automate/build/CMakeFiles/simple_obs_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_obs_app.dir/depend

