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
CMAKE_COMMAND = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/gladiator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gladiator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gladiator.dir/flags.make

CMakeFiles/gladiator.dir/main.cpp.o: CMakeFiles/gladiator.dir/flags.make
CMakeFiles/gladiator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gladiator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gladiator.dir/main.cpp.o -c "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/main.cpp"

CMakeFiles/gladiator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gladiator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/main.cpp" > CMakeFiles/gladiator.dir/main.cpp.i

CMakeFiles/gladiator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gladiator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/main.cpp" -o CMakeFiles/gladiator.dir/main.cpp.s

# Object files for target gladiator
gladiator_OBJECTS = \
"CMakeFiles/gladiator.dir/main.cpp.o"

# External object files for target gladiator
gladiator_EXTERNAL_OBJECTS =

gladiator: CMakeFiles/gladiator.dir/main.cpp.o
gladiator: CMakeFiles/gladiator.dir/build.make
gladiator: CMakeFiles/gladiator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gladiator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gladiator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gladiator.dir/build: gladiator

.PHONY : CMakeFiles/gladiator.dir/build

CMakeFiles/gladiator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gladiator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gladiator.dir/clean

CMakeFiles/gladiator.dir/depend:
	cd "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator" "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator" "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug" "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug" "/home/wdjpng/soi/Flims 2019/Flims Contest Friday/gladiator/cmake-build-debug/CMakeFiles/gladiator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/gladiator.dir/depend
