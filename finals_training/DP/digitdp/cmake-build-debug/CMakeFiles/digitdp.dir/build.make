# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wdjpng/soi/finals_training/DP/digitdp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/digitdp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/digitdp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/digitdp.dir/flags.make

CMakeFiles/digitdp.dir/main.cpp.o: CMakeFiles/digitdp.dir/flags.make
CMakeFiles/digitdp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/digitdp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/digitdp.dir/main.cpp.o -c /home/wdjpng/soi/finals_training/DP/digitdp/main.cpp

CMakeFiles/digitdp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/digitdp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wdjpng/soi/finals_training/DP/digitdp/main.cpp > CMakeFiles/digitdp.dir/main.cpp.i

CMakeFiles/digitdp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/digitdp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wdjpng/soi/finals_training/DP/digitdp/main.cpp -o CMakeFiles/digitdp.dir/main.cpp.s

# Object files for target digitdp
digitdp_OBJECTS = \
"CMakeFiles/digitdp.dir/main.cpp.o"

# External object files for target digitdp
digitdp_EXTERNAL_OBJECTS =

digitdp: CMakeFiles/digitdp.dir/main.cpp.o
digitdp: CMakeFiles/digitdp.dir/build.make
digitdp: CMakeFiles/digitdp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable digitdp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/digitdp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/digitdp.dir/build: digitdp

.PHONY : CMakeFiles/digitdp.dir/build

CMakeFiles/digitdp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/digitdp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/digitdp.dir/clean

CMakeFiles/digitdp.dir/depend:
	cd /home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wdjpng/soi/finals_training/DP/digitdp /home/wdjpng/soi/finals_training/DP/digitdp /home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug /home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug /home/wdjpng/soi/finals_training/DP/digitdp/cmake-build-debug/CMakeFiles/digitdp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/digitdp.dir/depend
