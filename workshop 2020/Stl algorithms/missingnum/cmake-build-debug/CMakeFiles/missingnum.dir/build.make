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
CMAKE_COMMAND = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wdjpng/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wdjpng/soi/Soi-Training/missingnum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/missingnum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/missingnum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/missingnum.dir/flags.make

CMakeFiles/missingnum.dir/main.cpp.o: CMakeFiles/missingnum.dir/flags.make
CMakeFiles/missingnum.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/missingnum.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/missingnum.dir/main.cpp.o -c /home/wdjpng/soi/Soi-Training/missingnum/main.cpp

CMakeFiles/missingnum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/missingnum.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wdjpng/soi/Soi-Training/missingnum/main.cpp > CMakeFiles/missingnum.dir/main.cpp.i

CMakeFiles/missingnum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/missingnum.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wdjpng/soi/Soi-Training/missingnum/main.cpp -o CMakeFiles/missingnum.dir/main.cpp.s

# Object files for target missingnum
missingnum_OBJECTS = \
"CMakeFiles/missingnum.dir/main.cpp.o"

# External object files for target missingnum
missingnum_EXTERNAL_OBJECTS =

missingnum: CMakeFiles/missingnum.dir/main.cpp.o
missingnum: CMakeFiles/missingnum.dir/build.make
missingnum: CMakeFiles/missingnum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable missingnum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/missingnum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/missingnum.dir/build: missingnum

.PHONY : CMakeFiles/missingnum.dir/build

CMakeFiles/missingnum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/missingnum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/missingnum.dir/clean

CMakeFiles/missingnum.dir/depend:
	cd /home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wdjpng/soi/Soi-Training/missingnum /home/wdjpng/soi/Soi-Training/missingnum /home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug /home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug /home/wdjpng/soi/Soi-Training/missingnum/cmake-build-debug/CMakeFiles/missingnum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/missingnum.dir/depend
